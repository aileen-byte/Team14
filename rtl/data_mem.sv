module data_mem #(
    parameter DATA_WIDTH    = 32,
    parameter MEMORY_BYTES  = 131072
)(
    input  logic                     clk,
    input  logic [DATA_WIDTH-1:0]    ALUResult,   // full 32-bit byte address from CPU
    input  logic [DATA_WIDTH-1:0]    WriteDataCache,
    input  logic [DATA_WIDTH-1:0]    WriteData,
    input  logic                     WriteThroughWE,
    input  logic [DATA_WIDTH-1:0]    WriteThroughAddress,
    input  logic                     MissWrite,
    input  logic [1:0]               StoreSize,
    output logic [DATA_WIDTH-1:0]    RD
);
    logic [7:0] mem_array [MEMORY_BYTES-1:0];

    initial begin 
        $readmemh("data.hex", mem_array, 32'h10000);
    end 

    logic [DATA_WIDTH-1:0] word_base;
    logic [1:0] byte_offset;
    assign word_base = {ALUResult[DATA_WIDTH-1:2], 2'b00};
    assign byte_offset = ALUResult[1:0];


    always_comb begin
        if (MissWrite) begin
            case (StoreSize)
                2'b00: begin
                    case (byte_offset)
                        2'b00: RD = {mem_array[word_base+3], mem_array[word_base+2], mem_array[word_base+1], WriteData[7:0]};
                        2'b01: RD = {mem_array[word_base+3], mem_array[word_base+2], WriteData[7:0], mem_array[word_base]};
                        2'b10: RD = {mem_array[word_base+3], WriteData[7:0], mem_array[word_base+1], mem_array[word_base]};
                        2'b11: RD = {WriteData[7:0], mem_array[word_base+2], mem_array[word_base+1], mem_array[word_base]};
                    endcase
                end
                default: ;
            endcase
        end
        else begin
            RD = {mem_array[word_base+3], mem_array[word_base+2], mem_array[word_base+1], mem_array[word_base]};
        end
    end

    always_ff @(posedge clk) begin
        if (WriteThroughWE) begin
            mem_array[WriteThroughAddress] <= WriteDataCache[7:0];
            mem_array[WriteThroughAddress+1] <= WriteDataCache[15:8];
            mem_array[WriteThroughAddress+2] <= WriteDataCache[23:16];
            mem_array[WriteThroughAddress+3] <= WriteDataCache[31:24];
        end
        else if (MissWrite) begin
            mem_array[ALUResult] <= WriteData[7:0];
        end
    end

endmodule
