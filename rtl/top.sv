module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0 
);

    // PC BLOCK WIRES 
    logic [31:0] pc; 
    logic [31:0] inc_pc; 
    logic [31:0] branch_pc; 
    logic [31:0] next_pc; 

    // REGISTER FILE WIRES
    logic [4:0] AD1;     // rs1
    logic [4:0] AD2;     // rs2
    logic [4:0] AD3;     // rd
    logic WE3;           // write enable
    logic [DATA_WIDTH-1:0] WD3;  // write data
    logic [DATA_WIDTH-1:0] RD1;  // read data 1
    logic [DATA_WIDTH-1:0] RD2;  // read data 2

    //ALU WIRES
    logic [31:0] ALUop1, ALUop2;
    logic [31:0] ALUout;
    logic        EQ;
    logic [2:0]  ALUctrl;


    // pc register
    pc_reg PCREG (
        .clk(clk), 
        .rst(rst), 
        .next_pc(next_pc),
        .pc(pc)
    ); 

    // pc + 4
    pc_plus4 ADD4(
        .pc(pc), 
        .inc_pc(inc_pc)
    ); 

    // branch adder 
    branch_adder BRADD (
        .pc(pc),
        .ImmOp(ImmOp), 
        .branch_pc(branch_pc), 
    ); 

    mux #(32) PCMUX (
        .in0(branch.pc),
        .in1(inc_pc), 
        .sel(PCsrs),
        .out(next_pc)
    ); 

    //alu
    ALU myALU (
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUctrl),
        .ALUout(ALUout),
        .EQ(EQ)
    );

    //reg file
    reg_file #(
        .DATA_WIDTH(32),
        .REG_COUNT(32)
    ) RF (
        .clk(clk),
        .AD1(AD1),
        .AD2(AD2),
        .AD3(AD3),
        .WE3(WE3),
        .WD3(WD3),
        .RD1(RD1),
        .RD2(RD2),
        .a0(a0)
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
