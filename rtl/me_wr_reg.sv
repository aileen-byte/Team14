module me_wr_reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic                clk,
    input  logic                reset,

    input logic                 RegWriteM,
    input logic                 MemtoRegM,
    input logic [DATA_WIDTH-1:0] ALUOutM,
    input logic [DATA_WIDTH-1:0] ReadDataM,
    input logic [4:0]           WriteRegM,

    output logic                RegWriteW,
    output logic                MemtoRegW,
    output logic [DATA_WIDTH-1:0] ALUOutW,
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic [4:0]          WriteRegW 
);
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            RegWriteW  <= 0;
            MemtoRegW <= 0;
            ALUOutW <= 0;
            ReadDataW <= 0;
            WriteRegW <= 0;
        end 
        else begin
            RegWriteW  <= RegWriteM;
            MemtoRegW  <= MemtoRegM;
            ALUOutW    <= ALUOutM;
            ReadDataW  <= ReadDataM;
            WriteRegW  <= WriteRegM;
        end
    end

endmodule

