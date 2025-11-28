module ex_me_reg #(
    parameter DATA_WIDTH = 32
)(
    input  logic                clk,
    input  logic                reset,

    input logic                 RegWriteE,
    input logic                 MemtoRegE,
    input logic                 MemWriteE,
    input logic [DATA_WIDTH-1:0] ALUOutE,
    input logic [DATA_WIDTH-1:0] WriteDataE,
    input logic [4:0]           WriteRegE,

    output logic                RegWriteM,
    output logic                MemtoRegM,
    output logic                MemWriteM,
    output logic [DATA_WIDTH-1:0] ALUOutM,
    output logic [DATA_WIDTH-1:0] WriteDataM,
    output logic [4:0]          WriteRegM
);
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            RegWriteM  <= 0;
            MemtoRegM  <= 0;
            MemWriteM  <= 0;
            ALUOutM    <= 0;
            WriteDataM <= 0;
            WriteRegM  <= 0;
        end 
        else begin
            RegWriteM  <= RegWriteE;
            MemtoRegM  <= MemtoRegE;
            MemWriteM  <= MemWriteE;
            ALUOutM    <= ALUOutE;
            WriteDataM <= WriteDataE;
            WriteRegM  <= WriteRegE;
        end
    end

endmodule

