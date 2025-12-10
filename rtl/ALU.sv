module ALU #(
    DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  ALUop1,
    input   logic [DATA_WIDTH-1:0]  ALUop2,
    input   logic [2:0]             ALUctrl,
    output  logic [DATA_WIDTH-1:0]  ALUout,
    output  logic                   Zero
);
    always_comb begin
        case (ALUctrl)
            3'b000: ALUout = ALUop1 + ALUop2;   // ADD
            3'b001: ALUout = ALUop1 - ALUop2;   // SUB
            3'b011: ALUout = ALUop1 ^ ALUop2;   // XOR
            3'b110: ALUout = ALUop1 | ALUop2;   // OR
            3'b111: ALUout = ALUop1 & ALUop2;   // AND
            default: ALUout = 32'h00000000;     
        endcase
        Zero = (ALUout == 0);
    end
endmodule
