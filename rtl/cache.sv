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
    input  logic [1:0] StoreSize,
    input logic memory,
    output logic [WIDTH-1:0] modified_fill_data,
    output logic [110:0] cache_line_current,
    output logic [WIDTH-1:0] cache_data_out,
    output logic [WIDTH-1:0] cache_to_memory_address, 
    output logic [WIDTH-1:0] cache_to_memory_data,
    output logic [110:0] cache_line_next,
    output logic [20:0] tag,
    output logic [20:0] cache_tag1,
    output logic [20:0] cache_tag0,
    output logic valid0,
    output logic valid1,
    output logic hit,
    output logic hit1,
    output logic hit0,
    output logic dirty0,
    output logic dirty1,
    output logic [8:0] set_index,
    output logic cache_to_memory_write_enable,
    output logic cache_stall
);



logic [110:0] cache_memory [SIZE-1:0];

// logic [8:0] set_index = memory_address[10:2];
assign set_index = memory_address[10:2];
 
assign tag = memory_address[31:11];
logic [1:0] byte_offset = memory_address[1:0];

assign cache_line_current = cache_memory[set_index];
//logic [110:0] cache_line_next;
//logic [110:0] cache_line_current;


logic used = cache_line_current[110];
//logic valid1 = cache_line_current[109];
//logic valid0 = cache_line_current[54];
assign valid1 = cache_line_current[109];
assign valid0 = cache_line_current[54];
//logic dirty1 = cache_line_current[108];
//logic dirty0 = cache_line_current[53];
assign dirty1 = cache_line_current[108];
assign dirty0 = cache_line_current[53];
assign cache_tag1 = cache_line_current[107:87];
//logic [20:0] cache_tag0 = cache_line_current[52:32];
assign cache_tag0 = cache_line_current[52:32];
logic [31:0] cache_data1 = cache_line_current[86:55];
logic [31:0] cache_data0 = cache_line_current[31:0];

//logic hit1;
//logic hit0;
//logic hit;

logic [WIDTH-1:0] current_cache_data;
logic [WIDTH-1:0] new_write_data;

logic [WIDTH-1:0] current_fill_data;
//logic [WIDTH-1:0] modified_fill_data;

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
    cache_data_out = 32'b0;
    cache_stall = 0;
    if (!rst && memory) begin
        hit1 = (tag == cache_tag1) && valid1;
        hit0 = (tag == cache_tag0) && valid0;
        hit = hit1 || hit0;
        if (hit) begin
            cache_stall = 0;
            current_cache_data = hit1 ? cache_data1 : cache_data0;
            new_write_data = current_cache_data;
            if (cache_write) begin
                case (StoreSize)
                    // Store Byte (sb)
                    2'b00: begin
                        case (byte_offset)
                            2'b00: new_write_data[7:0] = cache_data_in[7:0];
                            2'b01: new_write_data[15:8] = cache_data_in[7:0];
                            2'b10: new_write_data[23:16] = cache_data_in[7:0];
                            2'b11: new_write_data[31:24] = cache_data_in[7:0];
                        endcase
                    end
                    // Store Half-Word (sh)
                    2'b01: begin
                        // Must be word-aligned for half-word (byte_offset[0] must be 0)
                        case (byte_offset[1])
                            1'b0: new_write_data[15:0] = cache_data_in[15:0]; // Bytes 0 and 1
                            1'b1: new_write_data[31:16] = cache_data_in[15:0]; // Bytes 2 and 3
                        endcase
                    end
                    // Store Word (sw)
                    2'b10: begin
                        new_write_data = cache_data_in; // Write all 32 bits
                    end
                    default: ; // Do nothing for 2'b11 (or handle as an error)
                endcase
            end
            if (hit1) begin
                cache_data_out = cache_data1;
                cache_line_next[110] = 1'b1;
                if (cache_write) begin
                    cache_line_next[86:55] = new_write_data;
                    cache_line_next[108] = 1'b1;
                end
            end 
            else begin
                cache_data_out = cache_data0;
                cache_line_next[110] = 1'b0;
                if (cache_write) begin
                    cache_line_next[31:0] = new_write_data;
                    cache_line_next[53] = 1'b1;
                end
            end
        end 
        else begin
            cache_stall = 1;
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
                    cache_line_next[110] = 1'b0;
                    if (cache_write) begin
                        current_fill_data = memory_to_cache_data;
                        modified_fill_data = current_fill_data;
                        case (StoreSize)
                            2'b00: begin
                                case (byte_offset)
                                    2'b00: modified_fill_data[7:0] = cache_data_in[7:0];
                                    2'b01: modified_fill_data[15:8] = cache_data_in[7:0];
                                    2'b10: modified_fill_data[23:16] = cache_data_in[7:0];
                                    2'b11: modified_fill_data[31:24] = cache_data_in[7:0];
                                endcase
                            end
                            2'b01: begin
                                case (byte_offset[1])
                                    1'b0: modified_fill_data[15:0] = cache_data_in[15:0];
                                    1'b1: modified_fill_data[31:16] = cache_data_in[15:0];
                                endcase
                            end
                            2'b10: modified_fill_data = cache_data_in;
                            default: ;
                        endcase
                        cache_line_next[31:0] = modified_fill_data;
                        cache_line_next[53] = 1'b1;
                    end
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
                    cache_line_next[110] = 1'b1;
                    if (cache_write) begin
                        current_fill_data = memory_to_cache_data;
                        modified_fill_data = current_fill_data;
                        case (StoreSize)
                            2'b00: begin
                                case (byte_offset)
                                    2'b00: modified_fill_data[7:0] = cache_data_in[7:0];
                                    2'b01: modified_fill_data[15:8] = cache_data_in[7:0];
                                    2'b10: modified_fill_data[23:16] = cache_data_in[7:0];
                                    2'b11: modified_fill_data[31:24] = cache_data_in[7:0];
                                endcase
                            end
                            2'b01: begin
                                case (byte_offset[1])
                                    1'b0: modified_fill_data[15:0] = cache_data_in[15:0];
                                    1'b1: modified_fill_data[31:16] = cache_data_in[15:0];
                                endcase
                            end
                            2'b10: modified_fill_data = cache_data_in;
                            default: ;
                        endcase
                        cache_line_next[86:55] = modified_fill_data;
                        cache_line_next[108] = 1'b1;
                    end
                end
            end
        end
    end
end

endmodule
