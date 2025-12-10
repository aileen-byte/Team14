module control_unit(
    input logic [6:0]     op,
    input logic [2:0]     funct3,
    input logic           funct7b5,
    output logic [1:0]    ResultSrc, // 0: ALUResult, 1: ReadData into register
    output logic          MemWrite, // Data Memory write enable, 0: no mem write, 1: mem write 
    output logic [1:0]    MemWriteSize, // Data Memory write size
    output logic [1:0]    LoadSize,
    output logic [2:0]    ALUctrl, 
    output logic          ALUSrc, // 0: register, 1: immediate
    output logic [2:0]    ImmSrc, 
    output logic          RegWrite, // Register File write enable
    output logic [1:0]    BranchType,
    output logic [1:0]    JumpType
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

// BranchType encodings
localparam NO_BRANCH = 2'b00;
localparam BNE = 2'b01;
localparam BEQ = 2'b10;

// JumpType encodings
localparam NO_JUMP = 2'b00;
localparam JAL = 2'b01;
localparam JALR = 2'b10;

always_comb begin
    // PCSrc = Normal;
    ImmSrc = I_TYPE; 
    JumpType = NO_JUMP;
    BranchType = NO_BRANCH;

    case(op)
        // R-type instructions
        7'b0110011: begin
            ResultSrc = ALU; // ALU result
            MemWrite = 0; 
            ALUSrc = 0; // second ALU input = rs2
            RegWrite = 1; 
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
            ALUctrl = ALU_ADD; 
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1; 
            ImmSrc = I_TYPE;
            JumpType = JALR;
        end
        // lbu
        7'b0000011: begin
            ResultSrc = Memory; // ReadData from memory
            MemWrite = 0; 
            ALUctrl = ALU_ADD; 
            ALUSrc = 1; 
            RegWrite = 1; //write back to rd
            ImmSrc = I_TYPE;
        end
        // addi
        7'b0010011: begin 
            ResultSrc = ALU; // ALU result
            MemWrite = 0; 
            if (funct3 == 3'b000)
                ALUctrl = ALU_ADD;
            if (funct3 == 3'b100)
                ALUctrl = ALU_XOR;
            ALUSrc = 1; // second ALU input = imm
            RegWrite = 1;
            ImmSrc = I_TYPE; 
        end

        // U-type instructions 
        // lui 
        7'b0110111: begin
            ResultSrc = ALU;
            MemWrite = 0;
            RegWrite = 1; 
            ImmSrc = U_TYPE; 
            ALUSrc = 1;
            LoadSize = 2'b00; 
        end

        // S-type instructions (
        // sb
        7'b0100011: begin
            MemWrite = 1;
            MemWriteSize = 2'b00; 
            ALUctrl = ALU_ADD;
            ALUSrc = 1;
            RegWrite = 0;
            ImmSrc = S_TYPE;
        end

        // B-type instructions 
        // bne
        7'b1100011: begin
            MemWrite = 0;
            RegWrite = 0;
            ImmSrc = B_TYPE;
            ALUSrc = 0; //ALU uses rs2
            if (funct3 == 3'b001) begin  // BNE
                ALUctrl = ALU_SUB;
                BranchType = BNE;
            end
            if (funct3 == 3'b000) begin  // BEQ
                ALUctrl = ALU_SUB;
                BranchType = BEQ;
            end
        end

        // J-type instructions
        // jal
        7'b1101111: begin
            ResultSrc = PCPlus4;
            RegWrite = 1; 
            MemWrite = 0;
            ImmSrc = J_TYPE;
            JumpType = JAL;
        end
    endcase
end
endmodule

