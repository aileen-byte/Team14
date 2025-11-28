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
        Zero = 0;
        case (ALUctrl)
            3'b000: ALUout = ALUop1 + ALUop2;   // ADD
            3'b001: begin
                ALUout = ALUop1 - ALUop2;
                if (ALUout == 0)
                    Zero = 1;
                else
                    Zero = 0;   // SUB
            end
            3'b010: ALUout = ALUop1 & ALUop2;   // AND
            3'b011: ALUout = ALUop1 | ALUop2;   // OR
            3'b100: ALUout = ALUop1 ^ ALUop2;   // XOR
            default: ALUout = 32'h00000000;     // default
        endcase
    end
endmodule
