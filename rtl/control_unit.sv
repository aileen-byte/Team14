module control_unit(
    input logic [6:0] op,
    input logic [2:0] funct3,
    input logic funct7b5,
    input logic Zero,
    output logic PCsrc,
    output logic [1:0] ResultSrc, // 0: ALUResult, 1: ReadData into register
    output logic MemWrite, // Data Memory write enable
    output logic [2:0] ALUctrl, // ALU operation selection
    output logic ALUsrc, // 0: register, 1: immediate
    output logic [1:0] ImmSrc, // immediate type selection
    output logic RegWrite, // Register File write enable
);

// Immediate type encoding
localparam I_TYPE = 2'b00;
localparam S_TYPE = 2'b01;
localparam B_TYPE = 2'b10;
localparam J_TYPE = 2'b11;

// ALU operations
localparam ALU_ADD = 3'b000;
localparam ALU_SUB = 3'b001;

always_comb begin
    PCSrc = 0;
    ImmSrc = I_TYPE; 

    case(op)
        // R-type instructions
        7'b0110011: begin
            if (funct3 == 3'b000) begin
                if (funct7b5 == 1'b0) begin // ADD
                    ResultSrc = 2'b00; // ALU result
                    MemWrite = 0; //no memory write
                    ALUctrl = ALU_ADD;
                    ALUSrc = 0; // second ALU input = rs2
                    RegWrite = 1; //write back to rd
                end
                else begin // SUB
                    ResultSrc = 0; // ALU result
                    MemWrite = 0; //no memory write
                    ALUctrl = ALU_SUB;
                    ALUSrc = 0; // second ALU input = rs2
                    RegWrite = 1; //write back to rd
                end
            end
        end

        // I-type instructions
        // jalr t =pc+4; pc=(x[rs1]+sext(offset))&∼1; x[rd]=t
        7'b1100111: begin // still have to zero out least significant bit
            ResultSrc = 2'b10; 
            Memwrite = 0; //no memory write
            ALUctrl = ALU_ADD; //x[rs1]+sext(offset) 
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1; //write back to rd
            ImmSrc = J_TYPE;
            PCSrc = 1;
        end
        // load (lbu)
        7'b0000011: begin //need f3 if more instructions
            ResultSrc = 2'b01; // ReadData from memory
            MemWrite = 0; //no memory write
            ALUctrl = ALU_ADD; //x[rs1]+sext(offset)
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1; //write back to rd
            ImmSrc = I_TYPE;
        end
        // immediate arithmetic (addi)
        7'b0010011: begin 
            ResultSrc = 2'b00; // ALU result
            MemWrite = 0; //no memory write
            if (funct3 == 3'b000)
                ALUctrl = ALU_ADD;
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1; //write back to rd
            ImmSrc = I_TYPE; 
        end

        // U-type instructions (lui - load upper immediate)
        7'b0110111: begin //does EXT handle this?
            ResultSrc = 2'b11;
            MemWrite = 0;
            RegWrite = 1; //write back to rd
            ImmSrc = I_TYPE; 
        end

        // S-type instructions (sb)
        7'b0100011: begin
            MemWrite = 1;
            ALUctrl = ALU_ADD;
            ALUSrc = 1;
            RegWrite = 0;
            ImmSrc = S_TYPE;
        end

        // B-type instructions (bne)
        7'b1100011: begin
            MemWrite = 0;
            RegWrite = 0;
            ImmSrc = B_TYPE;
            ALUSrc = 0; //ALU uses rs2
            if (funct3 == 3'b001) begin  // BNE
                ALUctrl = ALU_SUB;
                // take branch if rs1 == rs2  (Zero == 1)
                PCSrc = (Zero == 1'b1);
            end
        end

        // J-type instructions
        // jal: x[rd] = pc+4; pc += sext(offset)
        7'b1101111: begin
            ResultSrc = 2'b10;
            RegWrite = 1; //write back to rd
            MemWrite = 0;
            ImmSrc = J_TYPE;
            PCSrc = 1;
        end
    endcase
end
endmodule

            


