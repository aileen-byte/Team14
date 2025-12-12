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
    input logic [1:0] StoreSize,
    input logic memory,
    output logic [WIDTH-1:0] cache_data_out,
    output logic [WIDTH-1:0] cache_to_memory_address, 
    output logic [WIDTH-1:0] cache_to_memory_data,
    output logic MissRead,
    output logic MissWrite,
    output logic cache_to_memory_write_enable
);
logic [108:0] cache_memory [SIZE-1:0];

logic [8:0] set_index;
logic [20:0] tag;
logic [1:0] byte_offset; 
assign set_index = memory_address[10:2];
assign tag = memory_address[31:11];
assign byte_offset = memory_address[1:0];

logic [108:0] cache_line_current;
logic [108:0] cache_line_next;
assign cache_line_current = cache_memory[set_index];

logic used;
logic valid1;
logic valid0;
logic [20:0] cache_tag1;
logic [20:0] cache_tag0;
logic [31:0] cache_data1;
logic [31:0] cache_data0;
assign used = cache_line_current[108];
assign valid1 = cache_line_current[109];
assign valid0 = cache_line_current[54];
assign valid1 = cache_line_current[107];
assign valid0 = cache_line_current[53];
assign cache_tag1 = cache_line_current[106:86];
assign cache_tag0 = cache_line_current[52:32];
assign cache_data1 = cache_line_current[85:54];
assign cache_data0 = cache_line_current[31:0];

logic hit1;
logic hit0;
logic hit;

logic [WIDTH-1:0] current_cache_data;
logic [WIDTH-1:0] new_write_data;

always_ff @(posedge clk) begin
    if (rst) begin
        for (int i = 0; i < SIZE; i = i + 1)
            cache_memory[i] = 109'b0;
    end
    else begin
        cache_memory[set_index] <= cache_line_next;
    end
end

always_comb begin
    cache_line_next = cache_line_current;
    cache_to_memory_write_enable = 1'b0;
    cache_data_out = 32'b0;
    MissRead = 0;
    MissWrite = 0;
    if (!rst && memory) begin
        hit1 = (tag == cache_tag1) && valid1;
        hit0 = (tag == cache_tag0) && valid0;
        hit = hit1 || hit0;

        if (hit) begin
            MissRead = 0;
            MissWrite = 0;
            current_cache_data = hit1 ? cache_data1 : cache_data0;
            new_write_data = current_cache_data;
            if (cache_write) begin
                case (StoreSize)
                    2'b00: begin
                        case (byte_offset)
                            2'b00: new_write_data[7:0] = cache_data_in[7:0];
                            2'b01: new_write_data[15:8] = cache_data_in[7:0];
                            2'b10: new_write_data[23:16] = cache_data_in[7:0];
                            2'b11: new_write_data[31:24] = cache_data_in[7:0];
                        endcase
                    end
                    2'b01: begin
                        case (byte_offset[1])
                            1'b0: new_write_data[15:0] = cache_data_in[15:0];
                            1'b1: new_write_data[31:16] = cache_data_in[15:0]; 
                        endcase
                    end
                    2'b10: begin
                        new_write_data = cache_data_in;
                    end
                    default: ;
                endcase
            end
            if (hit1) begin
                cache_data_out = cache_data1;
                cache_line_next[108] = 1'b1;
                if (cache_write) begin
                    cache_line_next[85:54] = new_write_data;
                    cache_to_memory_address = {memory_address[31:2], 2'b00};
                    cache_to_memory_write_enable = 1;
                    cache_to_memory_data = new_write_data;
                end
            end 
            else begin
                cache_data_out = cache_data0;
                cache_line_next[108] = 1'b0;
                if (cache_write) begin
                    cache_line_next[31:0] = new_write_data;
                    cache_to_memory_address = {memory_address[31:2], 2'b00};
                    cache_to_memory_write_enable = 1;
                    cache_to_memory_data = new_write_data;
                end
            end
        end 
        else begin
            if (cache_write) begin
                MissWrite = 1;
            end
            else begin
                MissRead = 1;
            end
            if (used) begin
                cache_line_next[31:0] = memory_to_cache_data;
                cache_line_next[52:32] = tag;
                cache_line_next[53] = 1'b1;
                cache_line_next[108] = 1'b0;
            end
            else begin 
                cache_line_next[85:54] = memory_to_cache_data;
                cache_line_next[106:86] = tag;
                cache_line_next[107] = 1'b1;
                cache_line_next[108] = 1'b1;
            end
        end
    end
end

endmodule
