module sign_extend(
    input logic [31:0] instr, //full instr
    input logic [1:0] ImmSrc, // select type of Imm, 00 = I-type 01 = B-type
    output logic [31:0] ImmOp  //output immediate 
);
    always_comb begin 
        case (ImmSrc)
            // If I-type (addi)
            2'b00: begin
                ImmOp = {{20{instr[31]}}, instr[31:20]};
            end
            // If B-Type 
            2'b01: begin 
                ImmOp = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
            end

            default: ImmOp = 32'b0;
        endcase
    end
endmodule

