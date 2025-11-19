module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0 
);
    // Instruction Memory
    logic [31:0] instr;

    instr_mem IMEM(
        .A(pc),
        .RD(instr)
    );

    // Control Unit
    logic RegWrite;
    logic [2:0] ALUctrl; //3-bit ALU control 
    logic ALUsrc;
    logic [1:0] ImmSrc; //2-bit Immediate Selector
    logic PCsrc; 
    logic ResultSrc;
    logic MemWrite;
    logic Zero;


    control_unit CU(
        .op(instr[6:0]),
        .funct3(instr[14:12]),
        .funct7b5(instr[30]),
        .Zero(Zero),

        .PCSrc(PCSrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .ALUctrl(ALUctrl[2:0]),
        .ImmSrc(ImmSrc),
        .RegWrite(RegWrite)

    );

    // Sign_extend 

    logic [31:0] ImmOp; 


    sign_extend SE(
        .instr(instr),
        .ImmSrc(ImmSrc),
        .ImmOp(ImmOp)

    );
    assign a0 = 32'd5;

endmodule
