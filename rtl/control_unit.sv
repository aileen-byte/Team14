module control_unit(
    input logic [6:0]   op,
    input logic [2:0]   funct3,
    input logic         funct7b5,
    input logic         Zero,
    output logic [1:0]  PCSrc,
    output logic [1:0]  ResultSrc, // 0: ALUResult, 1: ReadData into register
    output logic        MemWrite, 
    output logic [1:0]  MemWriteSize, 
    output logic [1:0]  LoadSize,
    output logic [2:0]  ALUctrl,
    output logic        ALUSrc, // 0: register, 1: immediate
    output logic [2:0]  ImmSrc, 
    output logic        RegWrite 
);

// ALU operations
localparam ALU_ADD = 3'b000;
localparam ALU_SUB = 3'b001;
localparam ALU_XOR = 3'b011;

// Immediate type encoding
localparam I_TYPE = 3'b000;
localparam S_TYPE = 3'b001;
localparam B_TYPE = 3'b010;
localparam J_TYPE = 3'b011;
localparam U_TYPE = 3'b100;

// ResultSrc encodings
localparam ALU = 2'b00;
localparam Memory = 2'b01;
localparam PCPlus4 = 2'b10;
localparam UpperImmediate = 2'b11;

// PCSrc encodings
localparam Normal = 2'b00;
localparam Immediate = 2'b01;
localparam JALR = 2'b10;

always_comb begin
    PCSrc = Normal;
    ImmSrc = I_TYPE; 

    case(op)
        // R-type instructions
        7'b0110011: begin
            ResultSrc = ALU; 
            MemWrite = 0; 
            ALUSrc = 0; // second ALU input = rs2
            RegWrite = 1; //write back to rd
            if (funct3 == 3'b000) begin
                if (funct7b5 == 1'b0) begin // ADD
                    ALUctrl = ALU_ADD;
                end
                else begin // SUB
                    ALUctrl = ALU_SUB;
                end
            end
            if (funct3 == 3'b100) begin
                ALUctrl = ALU_XOR; // XOR
            end
        end

        // I-type instructions
        // jalr
        7'b1100111: begin
            ResultSrc = PCPlus4; 
            MemWrite = 0; 
            ALUctrl = ALU_ADD; //x[rs1]+sext(offset) 
            ALUSrc = 1; //second ALU input = imm
            RegWrite = 1; 
            ImmSrc = I_TYPE;
            PCSrc = JALR;
        end

        // lbu
        7'b0000011: begin 
            ResultSrc = Memory; 
            MemWrite = 0; 
            ALUctrl = ALU_ADD; //x[rs1]+sext(offset)
            ALUSrc = 1; 
            RegWrite = 1; 
            ImmSrc = I_TYPE;
            LoadSize = 2'b00;
        end

        // immediate arithmetic (addi)
        7'b0010011: begin 
            ResultSrc = ALU; 
            MemWrite = 0; 
            if (funct3 == 3'b000)
                ALUctrl = ALU_ADD;
            if (funct3 == 3'b100)
                ALUctrl = ALU_XOR;
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1; 
            ImmSrc = I_TYPE; 
        end

        // U-type instructions (lui)
        7'b0110111: begin 
            ResultSrc = UpperImmediate;
            MemWrite = 0;
            RegWrite = 1; 
            ImmSrc = U_TYPE; 
        end

        // S-type instructions (sb)
        7'b0100011: begin
            MemWrite = 1;
            MemWriteSize = 2'b00; // byte size write
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
                // take branch if rs1 == rs2  (Zero == 0)
                if (Zero == 1'b0)
                    PCSrc = Immediate;
            end
            if (funct3 == 3'b000) begin  // BEQ
                ALUctrl = ALU_SUB;
                // take branch if rs1 == rs2  (Zero == 1)
                if (Zero == 1'b1)
                    PCSrc = Immediate;
            end
        end

        // J-type instructions(jal)
        7'b1101111: begin
            ResultSrc = PCPlus4;
            RegWrite = 1; 
            MemWrite = 0;
            ImmSrc = J_TYPE;
            PCSrc = Immediate;
        end

    endcase
end
endmodule
