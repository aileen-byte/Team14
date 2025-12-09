module sign_extend(
    input logic [31:7] instr,
    input logic [2:0] ImmSrc,
    output logic [31:0] ImmOp  //output immediate 
);
    always_comb begin 
        case (ImmSrc)
            // If I-type (addi)
            3'b000: begin
                ImmOp = {{20{instr[31]}}, instr[31:20]};
            end
            // If S-Type 
            3'b001: begin 
                ImmOp = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            end
            // If B-Type
            3'b010: begin
                ImmOp = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
            end
            // If J-Type
            3'b011: begin
                ImmOp = {{11{instr[31]}},instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
            end
            // If U-type
            3'b100: begin
                ImmOp = {instr[31:12], {12{1'b0}}};
            end

            default: ImmOp = 32'b0;
        endcase
    end
endmodule

