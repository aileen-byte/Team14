module sign_extend(
    input  logic [31:0] instr,
    input  logic [2:0]  ImmSrc,
    output logic [31:0] ImmOp
);

    always_comb begin
        case (ImmSrc)

            // I-type (ADDI, LW, JALR)
            3'b000: begin
                ImmOp = {{20{instr[31]}}, instr[31:20]};
            end

            // S-type (SW, SB, SH)
            3'b001: begin
                ImmOp = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            end

            // B-type (BEQ, BNE)
            3'b010: begin
                ImmOp = {{19{instr[31]}},
                         instr[31],
                         instr[7],
                         instr[30:25],
                         instr[11:8],
                         1'b0};
            end

            // J-type (JAL)
            3'b011: begin
                ImmOp = {{11{instr[31]}},     // imm[31:21]
                         instr[31],           // imm[20]
                         instr[19:12],        // imm[19:12]
                         instr[20],           // imm[11]
                         instr[30:21],        // imm[10:1]
                         1'b0};               // imm[0]
            end

            // U-type (LUI, AUIPC)
            3'b100: begin
                ImmOp = {instr[31:12], 12'b0};
            end

            default: ImmOp = 32'b0;

        endcase
    end

endmodule

