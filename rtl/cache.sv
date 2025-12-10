module cache #(
    parameter WIDTH = 32,
    parameter SIZE = 512
)(
    input logic clk,
    input logic rst,
    input logic cache_write,
    input logic [WIDTH-1:0] memory_address,
    input logic [WIDTH-1:0] cache_data_in,
    input logic [WIDTH-1:0] memory_to_cache_data,

    output logic [WIDTH-1:0] cache_data_out,
    output logic [WIDTH-1:0] cache_to_memory_address, 
    output logic [WIDTH-1:0] cache_to_memory_data,
    output logic cache_to_memory_write_enable,
    output logic cachestall 
);

logic [110:0] cache_memory [SIZE-1:0];

logic [8:0] set_index = memory_address[10:2];
logic [20:0] tag = memory_address[31:11];

logic [110:0] cache_line_current = cache_memory[set_index];
logic [110:0] cache_line_next;

logic used = cache_line_current[110];
logic valid1 = cache_line_current[109];
logic valid0 = cache_line_current[54];
logic dirty1 = cache_line_current[108];
logic dirty0 = cache_line_current[53];
logic [20:0] cache_tag1 = cache_line_current[107:87];
logic [20:0] cache_tag0 = cache_line_current[52:32];
logic [31:0] cache_data1 = cache_line_current[86:55];
logic [31:0] cache_data0 = cache_line_current[31:0];

logic hit1;
logic hit0;
logic hit;

logic miss_way;
logic [31:0] miss_addr; 
logic [20:0] miss_tag; 
logic [8:0] miss_set_index;



// logic [31:0] miss_wdata; 


typedef enum logic [1:0] {
        COMPARE,
        WRITE_BACK,
        ALLOCATE,
        REFILL
    } state_t;

    state_t state, next_state;

always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        for (int i = 0; i < SIZE; i = i + 1) begin
            cache_memory[i] <= '0;
        end

        state <= COMPARE; 
        miss_set_index <= '0;

    end
    else begin
        state <= next_state;

        if (state == COMPARE && !hit) begin
            miss_addr <= memory_address;
            miss_way <= used ? 0 : 1; 
            miss_tag <= tag; 
            miss_set_index <= set_index; 
        end

        if (state == COMPARE && hit && cache_write) begin
            cache_memory[set_index] <= cache_line_next;
        end 
        else if (state == REFILL) begin
            cache_memory[miss_set_index] <= cache_line_next;
        end
    end 
end

always_comb begin

    cache_line_next              = cache_line_current;
    cache_to_memory_write_enable = 0;
    cache_to_memory_address      = '0;
    cache_to_memory_data         = '0;
    cache_data_out               = '0;
    cachestall                   = 0;
    next_state                   = state;

    hit1 = (tag == cache_tag1) && valid1;
    hit0 = (tag == cache_tag0) && valid0;
    hit = hit1 || hit0;

    case(state)
        COMPARE: begin 

            cachestall = !hit;

            if (hit) begin

                if (hit1) begin
                    cache_data_out = cache_write ? cache_data_in : cache_data1;

                    cache_line_next[110] = 1'b1;
                    if (cache_write) begin
                        cache_line_next[86:55] = cache_data_in;
                        cache_line_next[108] = 1'b1;
                    end
                end 
                else begin

                    cache_data_out = cache_write ? cache_data_in : cache_data0;
                    cache_line_next[110] = 1'b0;      
                        if (cache_write) begin
                            cache_line_next[31:0]  = cache_data_in;
                            cache_line_next[53]    = 1'b1; 
                        end
                end

                next_state = COMPARE; 
            end 
            else begin 

                if ((used && dirty0 && valid0) || (!used && dirty1 && valid1)) begin 
                    cachestall = 1; 
                    next_state = WRITE_BACK; 
                end 
                else begin 
                    cachestall = 1; 
                    next_state = ALLOCATE; 
                end
            end 
        end 


        WRITE_BACK: begin 
            cachestall = 1;
            cache_to_memory_write_enable = 1'b1; 

            if (miss_way == 1'b1) begin
                cache_to_memory_address = {cache_tag0, miss_set_index, 2'b00};
                cache_to_memory_data    = cache_data0;
                cache_line_next[53]     = 1'b0;  
            end 
            else begin
                cache_to_memory_address = {cache_tag1, miss_set_index, 2'b00};
                cache_to_memory_data    = cache_data1;
                cache_line_next[108]    = 1'b0;  
            end

            next_state = ALLOCATE; 
        end

        ALLOCATE: begin 
            cachestall = 1;
            cache_to_memory_address     = miss_addr;

            next_state = REFILL; 
        end
        REFILL: begin 
            cachestall = 1;
            if(miss_way) begin 
                cache_line_next[31:0] = memory_to_cache_data; 
                cache_data_out        = memory_to_cache_data;
                cache_line_next[52:32]  = miss_tag;
                cache_line_next[54]     = 1'b1;
                cache_line_next[53]     = 1'b0;
                cache_line_next[110]    = 1'b0;

            end 
            else begin 
                cache_line_next[86:55]  = memory_to_cache_data; 
                cache_data_out        = memory_to_cache_data;
                cache_line_next[107:87] = miss_tag; 
                cache_line_next[109]    = 1'b1;
                cache_line_next[108]    = 1'b0;
                cache_line_next[110]    = 1'b1;

            end 

            if (cache_write) begin
                if (miss_way) begin
                    // writing into way0
                    cache_line_next[31:0] = cache_data_in;
                    cache_line_next[53]   = 1'b1;   // dirty0
                end else begin
                    // writing into way1
                    cache_line_next[86:55] = cache_data_in;
                    cache_line_next[108]   = 1'b1;  // dirty1
                end
            end

            next_state = COMPARE; 
        end 
    endcase
end 

/*
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        for (int i = 0; i < SIZE; i = i + 1) begin
            cache_memory[i] = 111'b0;
        end
    end
    else begin
        cache_memory[set_index] <= cache_line_next;
    end
end

always_comb begin
    cache_line_next = cache_line_current;
    cache_to_memory_write_enable = 1'b0;
    if (!rst) begin
        hit1 = (tag == cache_tag1) && valid1;
        hit0 = (tag == cache_tag0) && valid0;
        hit = hit1 || hit0;
        if (hit) begin
            if (hit1) begin
                cache_data_out = cache_data1;
                cache_line_next[110] = 1'b1;
                if (cache_write) begin
                    cache_line_next[86:55] = cache_data_in;
                    cache_line_next[108] = 1'b1;
                end
            end 
            else begin
                cache_data_out = cache_data0;
                cache_line_next[110] = 1'b0;
                if (cache_write) begin
                    cache_line_next[31:0] = cache_data_in;
                    cache_line_next[53] = 1'b1;
                end
            end
        end 
        else begin
            if (used) begin
                if (dirty0 && valid0) begin 
                    cache_to_memory_address = {cache_tag0, set_index, 2'b00};
                    cache_to_memory_data = cache_data0;
                    cache_to_memory_write_enable = 1'b1;
                    cache_line_next[53] = 1'b0;
                end
                else begin
                    cache_to_memory_address = memory_address;
                    cache_line_next[31:0] = memory_to_cache_data;
                    cache_line_next[52:32] = tag;
                    cache_line_next[54] = 1'b1;
                end
            end 
            else begin 
                if (dirty1 && valid1) begin
                    cache_to_memory_address = {cache_tag1, set_index, 2'b00};
                    cache_to_memory_data = cache_data1;
                    cache_to_memory_write_enable = 1'b1;
                    cache_line_next[108] = 1'b0;
                end
                else begin
                    cache_to_memory_address = memory_address;
                    cache_line_next[86:55] = memory_to_cache_data;
                    cache_line_next[107:87] = tag;
                    cache_line_next[109] = 1'b1;
                end
            end
        end
    end
end 
*/

endmodule