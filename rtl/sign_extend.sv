module sign_extend(
    input logic [31:7] instr,
    input logic [2:0] ImmSrc,
    output logic [31:0] ImmOp
);
    always_comb begin 
        case (ImmSrc)
            3'b000: ImmOp = {{20{instr[31]}}, instr[31:20]};// If I-type (addi)
            3'b001: ImmOp = {{20{instr[31]}}, instr[31:25], instr[11:7]};// If S-Type 
            3'b010: ImmOp = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0}; // If B-Type
            3'b011: ImmOp = {{11{instr[31]}},instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};// If J-Type
            3'b100: ImmOp = {instr[31:12], {12{1'b0}}};// If U-type
            default: ImmOp = 32'b0;
        endcase
    end
endmodule

