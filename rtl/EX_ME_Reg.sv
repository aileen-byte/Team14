module EX_ME_Reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic                clk,
    input  logic                reset,

    // Control + data from EX stage
    input  logic                    RegWriteE,
    input  logic                    MemWriteE,
    input  logic [1:0]              ResultSrcE,
    input  logic [DATA_WIDTH-1:0]   ALUOutE,
    input  logic [DATA_WIDTH-1:0]   WriteDataE,
    input  logic [4:0]              WriteRegE, //Rd
    input  logic [DATA_WIDTH-1:0]   PCPlus4E,
    input logic [1:0]               LoadSizeE,

    // Store size for memory writes
    input  logic [1:0]           StoreSizeE,
    output logic [1:0]           StoreSizeM,

    // Outputs to MEM stage
    output logic                    RegWriteM,
    output logic                    MemWriteM,
    output logic [1:0]              ResultSrcM,
    output logic [DATA_WIDTH-1:0]   PCPlus4M,
    output logic [DATA_WIDTH-1:0]   ALUOutM,
    output logic [DATA_WIDTH-1:0]   WriteDataM,
    output logic [4:0]              WriteRegM,
    output logic [1:0]              LoadSizeM
);

    always_ff @(posedge clk) begin
        if (reset) begin
            RegWriteM  <= 0;
            MemWriteM  <= 0;
            ResultSrcM <= 0;
            StoreSizeM <= 0;
            ALUOutM    <= 0;
            WriteDataM <= 0;
            WriteRegM  <= 0;
            PCPlus4M   <= 0;
            LoadSizeM <= 0;
        end
        else begin
            RegWriteM  <= RegWriteE;
            MemWriteM  <= MemWriteE;
            ResultSrcM <= ResultSrcE;
            StoreSizeM <= StoreSizeE;
            ALUOutM    <= ALUOutE;
            WriteDataM <= WriteDataE;
            WriteRegM  <= WriteRegE;
            PCPlus4M   <= PCPlus4E;
            LoadSizeM <= LoadSizeE;
        end
    end

endmodule

