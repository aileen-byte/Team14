module topcache #(
    parameter WIDTH = 32,
    parameter SIZE = 512
)(
    input logic clk,
    input logic rst,
    input logic cache_read,
    input logic cache_write,
    input logic [WIDTH-1:0] memory_address,
    input logic [WIDTH-1:0] cache_data_in,

    output logic [WIDTH-1:0] cache_data_out,
    output logic [WIDTH-1:0] cache_to_memory_address,
    output logic [WIDTH-1:0] cache_to_memory_data,
    output logic cache_to_memory_write_enable, 
    output logic cachestall
);

logic [WIDTH-1:0] memory_to_cache_data;

cache #(
    .WIDTH(WIDTH),
    .SIZE(SIZE)
) cache_inst (
    .clk(clk),
    .rst(rst),
    .cache_write(cache_write),
    .memory_address(memory_address),
    .cache_data_in(cache_data_in),
    .memory_to_cache_data(memory_to_cache_data),
    .cache_data_out(cache_data_out),
    .cache_to_memory_address(cache_to_memory_address),
    .cache_to_memory_data(cache_to_memory_data),
    .cache_to_memory_write_enable(cache_to_memory_write_enable),
    .cache_to_memory_read_enable(cache_to_memory_read_enable),
    .cachestall(cachestall)
);

data_mem #(WIDTH) data_mem_inst (
    .clk(clk),
    .ALUResult(cache_to_memory_address),
    .WriteData(cache_to_memory_data),
    .WE(cache_to_memory_write_enable),
    .RD(memory_to_cache_data)
);

endmodule