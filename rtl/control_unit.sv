module control_unit(
    input logic [6:0] op,
    input logic [2:0] funct3,
    input logic funct7b5,

    
    output logic [1:0] ResultSrc, // 0: ALUResult, 1: ReadData into register
    output logic MemWrite, // Data Memory write enable
    output logic [2:0] ALUctrl, // ALU operation selection
    output logic ALUSrc, // 0: register, 1: immediate
    output logic [2:0] ImmSrc, // immediate type selection
    output logic RegWrite, // Register File write enable

    output logic Branch,
    output logic Jump

);

// ALU operations
localparam ALU_ADD = 3'b000;
localparam ALU_SUB = 3'b001;

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
// localparam Normal = 2'b00; //PC+4
// localparam Immediate = 2'b01; //PC+imm (B-type)
// localparam JAL= 2'b10; //PC+imm (J-type)
// localparam JALR = 2'b11; // ALU result (rs1+imm)

always_comb begin
    // Default values — safe state
    ResultSrc = ALU;
    MemWrite  = 0;
    ALUctrl   = ALU_ADD;
    ALUSrc    = 0;
    ImmSrc    = I_TYPE;
    RegWrite  = 0;
    Branch    = 0;
    Jump      = 0;

    case (op)

        // R-TYPE —— ADD, SUB
        7'b0110011: begin
            RegWrite = 1;
            ResultSrc = ALU;
            ALUSrc = 0;

            if (funct3 == 3'b000) begin
                ALUctrl = (funct7b5 ? ALU_SUB : ALU_ADD);
            end
        end

        // I-TYPE ARITHMETIC —— ADDI
        7'b0010011: begin
            RegWrite = 1;
            ALUSrc   = 1;
            ImmSrc   = I_TYPE;
            ResultSrc= ALU;

            if (funct3 == 3'b000)
                ALUctrl = ALU_ADD;
        end

        // LOAD —— LB/LBU/LH/LW
        7'b0000011: begin
            RegWrite = 1;
            ALUSrc   = 1;
            ImmSrc   = I_TYPE;
            ALUctrl  = ALU_ADD;
            ResultSrc= Memory;
        end

        // STORE —— SB/SH/SW
        7'b0100011: begin
            MemWrite = 1;
            ALUSrc   = 1;
            ImmSrc   = S_TYPE;
            ALUctrl  = ALU_ADD;
        end

        // BRANCH —— BEQ, BNE, BLT, BGE, etc.
        7'b1100011: begin
            Branch   = 1;
            ALUSrc   = 0;
            ImmSrc   = B_TYPE;

            // always use subtraction for comparisons
            ALUctrl = ALU_SUB;
        end

        // JAL —— Unconditional jump
        7'b1101111: begin
            Jump     = 1;
            RegWrite = 1;
            ResultSrc = PCPlus4;
            ImmSrc   = J_TYPE;
        end

        // JALR —— Jump via register
        7'b1100111: begin
            Jump     = 1;
            RegWrite = 1;
            ALUSrc   = 1;
            ImmSrc   = I_TYPE;
            ALUctrl  = ALU_ADD;
            ResultSrc = PCPlus4;
        end

        // LUI —— Load Upper Immediate
        7'b0110111: begin
            RegWrite  = 1;
            ImmSrc    = U_TYPE;
            ResultSrc = UpperImmediate;
        end

    endcase
end
endmodule

// always_comb begin
//     //List of default values
//     PCSrc = Normal;
//     ImmSrc = I_TYPE; 
//     ResultSrc = ALU;
//     MemWrite = 0; 
//     ALUctrl = ALU_ADD;
//     ALUSrc = 0;
//     ImmSrc = I_TYPE; 
//     RegWrite = 0; 

//     case(op)
//         // R-type instructions
//         7'b0110011: begin
//             if (funct3 == 3'b000) begin
//                 if (funct7b5 == 1'b0) begin // ADD
//                     ResultSrc = ALU; // ALU result
//                     MemWrite = 0; //no memory write
//                     ALUctrl = ALU_ADD;
//                     ALUSrc = 0; // second ALU input = rs2
//                     RegWrite = 1; //write back to rd
//                 end
//                 else begin // SUB
//                     ResultSrc = ALU; // ALU result
//                     MemWrite = 0; //no memory write
//                     ALUctrl = ALU_SUB;
//                     ALUSrc = 0; // second ALU input = rs2
//                     RegWrite = 1; //write back to rd
//                 end
//             end
//         end

//         // I-type instructions
//         // jalr t =pc+4; pc=(x[rs1]+sext(offset))&∼1; x[rd]=t
//         7'b1100111: begin // still have to zero out least significant bit
//             ResultSrc = PCPlus4; 
//             MemWrite = 0; //no memory write
//             ALUctrl = ALU_ADD; //x[rs1]+sext(offset) 
//             ALUSrc = 1; // second ALU input = imm
//             RegWrite = 1; //write back to rd
//             ImmSrc = I_TYPE;
//             PCSrc = JALR; //2'b11
//         end
//         // load (lbu)
//         7'b0000011: begin //need f3 if more instructions
//             ResultSrc = Memory; // ReadData from memory
//             MemWrite = 0; //no memory write
//             ALUctrl = ALU_ADD; //x[rs1]+sext(offset)
//             ALUSrc = 1; // second ALU input = imm
//             RegWrite = 1; //write back to rd
//             ImmSrc = I_TYPE;
//         end
//         // immediate arithmetic (addi)
//         7'b0010011: begin 
//             ResultSrc = ALU; // ALU result
//             MemWrite = 0; //no memory write
//             if (funct3 == 3'b000)
//                 ALUctrl = ALU_ADD;
//             ALUSrc = 1; // second ALU input = imm
//             RegWrite = 1; //write back to rd
//             ImmSrc = I_TYPE; 
//         end

//         // U-type instructions (lui - load upper immediate)
//         // x[rd] = sext(immediate[31:12] << 12)
//         7'b0110111: begin //does EXT handle this?
//             ResultSrc = UpperImmediate;
//             MemWrite = 0;
//             RegWrite = 1; //write back to rd
//             ImmSrc = U_TYPE; 
//         end

//         // S-type instructions (sb)
//         7'b0100011: begin
//             MemWrite = 1;
//             ALUctrl = ALU_ADD;
//             ALUSrc = 1;
//             RegWrite = 0;
//             ImmSrc = S_TYPE;
//         end

//         // B-type instructions (bne)
//         // if (x[rs1] != x[rs2]) pc += sext(offset)
//         7'b1100011: begin
//             MemWrite = 0;
//             RegWrite = 0;
//             ImmSrc = B_TYPE;
//             ALUSrc = 0; //ALU uses rs2
//             if (funct3 == 3'b001) begin  // BNE
//                 ALUctrl = ALU_SUB;
//                 // take branch if rs1 == rs2  (Zero == 1)
//                 if (Zero == 1'b0)
//                     PCSrc = Immediate;
//             end
//         end

//         // J-type instructions
//         // jal: x[rd] = pc+4; pc += sext(offset)
//         7'b1101111: begin
//             ResultSrc = PCPlus4;
//             RegWrite = 1; //write back to rd
//             MemWrite = 0;
//             ImmSrc = J_TYPE;
//             PCSrc = JAL;
//         end
//     endcase
// end

