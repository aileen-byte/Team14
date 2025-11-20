module control_unit(
    input logic [6:0] op,
    input logic [2:0] funct3,
    input logic funct7b5,
    input logic Zero,

    output logic RegWrite,
    output logic ALUsrc,
    output logic [2:0] ALUctrl,
    output logic [1:0] ImmSrc,
    output logic PCSrc,
    output logic ResultSrc,
    output logic MemWrite 
);

// Immediate type encoding
localparam I_TYPE = 2'b00;
localparam B_TYPE = 2'b01; 

// ALU operations
localparam ALU_ADD = 3'b000;
localparam ALU_SUB = 3'b001;


always_comb begin
    RegWrite = 0;
    ALUSrc = 0;
    ALUctrl = ALU_ADD;
    ImmSrc = I_TYPE; 
    PCSrc = 0; 
    MemWrite = 0;
    ResultSrc = 0; 

    case(op)
        // ADDI
        7'b0010011: begin 
            RegWrite = 1; //write back to rd
            ALUSrc = 1; // second ALU input = imm
            ImmSrc = I_TYPE; 
            ALUctrl = ALU_ADD;
        end

        // Branches only if bne used
        7'b1100011: begin
            if (funct3 == 3'b001) begin  // BNE
                RegWrite = 0; //no register write
                ALUSrc = 0; //ALU uses rs2
                ImmSrc = B_TYPE;
                ALUctrl = ALU_SUB;

                // take branch if rs1 != rs2  (Zero == 0)
                PCSrc = (Zero == 1'b0);
            end
        end
    endcase
endmodule

            


