/* module data_mem #(
    parameter DATA_WIDTH = 32,
    parameter MEMORY_WORDS = 1 << 20 // 1 MB
)(
    input   logic                      clk,
    input logic [DATA_WIDTH-1:0] ALUResult, 
    input logic [DATA_WIDTH-1:0] WriteData,
    input logic                        WE,
    output logic [DATA_WIDTH-1:0]      RD 
);
    logic [7:0] mem_array [0:MEMORY_WORDS-1];
    // Read
    assign RD = { mem_array[ALUResult + 3],
                  mem_array[ALUResult + 2],
                  mem_array[ALUResult + 1],
                  mem_array[ALUResult + 0] };

    // Write
    always_ff @(posedge clk) begin
        if (WE)
            mem_array[ALUResult] <= WriteData[7:0];
    end
endmodule */ 

module data_mem #(
    parameter DATA_WIDTH    = 32,
    parameter MEMORY_BYTES  = 1 << 20     // 1 MB = 2^20 bytes
)(
    input  logic                     clk,
    input  logic [DATA_WIDTH-1:0]    ALUResult,   // full 32-bit byte address from CPU
    input  logic [DATA_WIDTH-1:0]    WriteData,
    input  logic                     MemWrite,
    input  logic [1:0]               StoreSize,
    output logic [DATA_WIDTH-1:0]    RD
);

    // ------------------------------------------------------------
    // MASK ADDRESS TO 20 BITS  (1 MB RANGE)
    // ------------------------------------------------------------
    logic [19:0] addr;  
    assign addr = ALUResult[19:0];   // mask to 0 .. (1MB - 1)

    // Byte-addressable memory
    logic [7:0] mem_array [0:MEMORY_BYTES-1];

    // ------------------------------------------------------------
    // ASYNCHRONOUS READ (little endian)
    // ------------------------------------------------------------

    assign RD = {24'b0, mem_array[addr]};

    // ------------------------------------------------------------
    // SYNCHRONOUS WRITE WITH BYTE ENABLES
    // ------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (MemWrite) begin
            case (StoreSize)
                2'b00: begin  // SB
                    mem_array[addr + 0] <= WriteData[7:0];
                end

                2'b01: begin  // SH
                    mem_array[addr + 0] <= WriteData[7:0];
                    mem_array[addr + 1] <= WriteData[15:8];
                end

                2'b10: begin  // SW
                    mem_array[addr + 0] <= WriteData[7:0];
                    mem_array[addr + 1] <= WriteData[15:8];
                    mem_array[addr + 2] <= WriteData[23:16];
                    mem_array[addr + 3] <= WriteData[31:24];
                end
            endcase
        end
    end

endmodule
