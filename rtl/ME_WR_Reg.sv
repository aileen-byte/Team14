module ME_WR_Reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic                clk,
    input  logic                reset,

    input logic                 RegWriteM,
    input logic [DATA_WIDTH-1:0] ALUOutM,
    input logic [DATA_WIDTH-1:0] ReadDataM,
    input logic [4:0]           WriteRegM,
    input  logic [1:0] ResultSrcM,
    input  logic [DATA_WIDTH-1:0] PCPlus4M,

    output logic                RegWriteW,
    output logic [1:0] ResultSrcW,
    output logic [DATA_WIDTH-1:0] PCPlus4W,
    output logic [DATA_WIDTH-1:0] ALUOutW,
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic [4:0]          WriteRegW
);
    always_ff @(posedge clk) begin
        if (reset) begin
            RegWriteW  <= 0;
            ALUOutW <= 0;
            ReadDataW <= 0;
            WriteRegW <= 0;
            ResultSrcW  <= 0;      
            PCPlus4W    <= 0;
        end 
        else begin
            RegWriteW  <= RegWriteM;
            ALUOutW    <= ALUOutM;
            ReadDataW  <= ReadDataM;
            WriteRegW  <= WriteRegM;
            ResultSrcW <= ResultSrcM;
            PCPlus4W   <= PCPlus4M;
        end
    end

endmodule
