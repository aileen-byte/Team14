module data_mem #(
    parameter DATA_WIDTH    = 32,
    parameter MEMORY_BYTES  = 131072
)(
    input  logic                     clk,
    input  logic [DATA_WIDTH-1:0]    ALUResult,   // full 32-bit byte address from CPU
    input  logic [DATA_WIDTH-1:0]    WriteData,
    input  logic                     MemWrite,
    input  logic [1:0]               StoreSize,
    output logic [DATA_WIDTH-1:0]    RD
);
    logic [7:0] mem_array [MEMORY_BYTES-1:0];

    initial begin 
        $readmemh("data.hex", mem_array, 32'h10000);
    end 

    assign RD = {mem_array[ALUResult+3], mem_array[ALUResult+2], mem_array[ALUResult+1], mem_array[ALUResult]};

    always_ff @(posedge clk) begin
        if (MemWrite) begin
            case (StoreSize)
                2'b00: begin  // SB
                    mem_array[ALUResult] <= WriteData[7:0];
                end
                2'b01: begin  // SH
                    mem_array[ALUResult] <= WriteData[7:0];
                    mem_array[ALUResult+1] <= WriteData[15:8];
                end
                2'b10: begin  // SW
                    mem_array[ALUResult] <= WriteData[7:0];
                    mem_array[ALUResult+1] <= WriteData[15:8];
                    mem_array[ALUResult+2] <= WriteData[23:16];
                    mem_array[ALUResult+3] <= WriteData[31:24];
                end
                default: ;
            endcase
        end
    end

endmodule
