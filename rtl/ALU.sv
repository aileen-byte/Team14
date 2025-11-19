module ALU #(
    DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  ALUop1,
    input   logic [DATA_WIDTH-1:0]  ALUop2,
    input   logic [2:0]             ALUctrl,
    output  logic [DATA_WIDTH-1:0]  ALUout,
    output  logic                       EQ
);

    always_comb begin
        //default vaules
        ALUout = '0;
        EQ = 0;
    
        case (ALUctrl)
            3'b000: ALUout = ALUop1 + ALUop2;   // ADD
            3'b001: ALUout = ALUop1 - ALUop2;   // SUB
            3'b010: ALUout = ALUop1 & ALUop2;   // AND
            3'b011: ALUout = ALUop1 | ALUop2;   // OR
            3'b100: ALUout = ALUop1 ^ ALUop2;   // XOR
            default: ALUout = 32'h00000000;     // default
        endcase

        if (ALUop1 == ALUop2)
            EQ = 1
        else 
            EQ = 0
    end
endmodule
