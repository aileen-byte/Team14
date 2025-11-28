module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0,
    output logic [DATA_WIDTH-1:0] instr,
     
);

assign a0 = 32'd5;

// INSTRUCTION BLOCK WIRES 
logic [1:0] PCSrc;
logic [DATA_WIDTH-1:0] inc_pc; 
logic [DATA_WIDTH-1:0] branch_pc; 
logic [DATA_WIDTH-1:0] next_pc; 
logic [DATA_WIDTH-1:0] pc; 
//logic [DATA_WIDTH-1:0] instr;

// CONTROL UNIT WIRES
logic RegWrite;
logic [2:0] ALUctrl; //3-bit ALU control 
logic ALUSrc;
logic [2:0] ImmSrc; //3-bit Immediate Selector
logic [1:0] ResultSrc;
logic MemWrite;
logic Zero;

// REGISTER FILE WIRES
logic [DATA_WIDTH-1:0] WD3;  // write data
logic [DATA_WIDTH-1:0] RD1;  // read data 1
logic [DATA_WIDTH-1:0] RD2;  // read data 2

// DATA MEMORY WIRES
logic [DATA_WIDTH-1:0] ReadData; // output from data memory

//ALU WIRES
logic [DATA_WIDTH-1:0] ALUop2;
logic [DATA_WIDTH-1:0] ALUout;

logic [DATA_WIDTH-1:0] ImmOp; 

logic [DATA_WIDTH-1:0] jalrPC;

// pc register
pc_reg #(DATA_WIDTH) PCREG (
    .clk(clk), 
    .rst(rst), 
    .next_pc(next_pc),
    .pc(pc)
); 

// pc + 4
pc_plus4 #(DATA_WIDTH) ADD4(
    .pc(pc), 
    .inc_pc(inc_pc)
); 

// branch adder 
branch_adder #(DATA_WIDTH) BRADD (
    .pc(pc),
    .ImmOp(ImmOp), 
    .branch_pc(branch_pc)
); 

// pc mux
mux4 #(DATA_WIDTH) PCMUX (
    .in0(inc_pc),
    .in1(branch_pc),
    .in2(jalrPC),
    .in3(32'b0), 
    .sel(PCSrc),
    .out(next_pc)
);

// Instruction Memory
instr_mem #(.DATA_WIDTH(DATA_WIDTH)) IMEM(
    .A(pc),
    .RD(instr)
);

// control unit
control_unit CU(
    .op(instr[6:0]),
    .funct3(instr[14:12]),
    .funct7b5(instr[30]),
    .Zero(Zero),
    .PCSrc(PCSrc),
    .ResultSrc(ResultSrc),
    .MemWrite(MemWrite),
    .ALUctrl(ALUctrl),
    .ALUSrc(ALUSrc),
    .ImmSrc(ImmSrc),
    .RegWrite(RegWrite)
);

// Sign_extend 
sign_extend SE(
    .instr(instr[31:7]),
    .ImmSrc(ImmSrc),
    .ImmOp(ImmOp)
);

// reg file
reg_file #(DATA_WIDTH) RF (
    .clk(clk),
    .AD1(instr[19:15]),
    .AD2(instr[24:20]),
    .AD3(instr[11:7]),
    .WE3(RegWrite),
    .WD3(WD3),
    .RD1(RD1),
    .RD2(RD2),
    .a0(a0)
);

data_mem #(
    .DATA_WIDTH(DATA_WIDTH)
) DM (
    .clk(clk),
    .ALUResult(ALUout),    // memory address
    .WriteData(RD2),       // data to write
    .WE(MemWrite),         // from control unit
    .RD(ReadData)          // output data
);

mux ALUMUX (
    .in0(RD2),
    .in1(ImmOp),
    .sel(ALUSrc),
    .out(ALUop2)
);

//alu
ALU myALU (
    .ALUop1(RD1),
    .ALUop2(ALUop2),
    .ALUctrl(ALUctrl),
    .ALUout(ALUout),
    .Zero(Zero)
);

jalr_mask jalr(
    .ALUPC(ALUout),
    .jalrPC(jalrPC)
);

// 4bit Mux
mux4 #(DATA_WIDTH) RESULT_MUX (
    .in0(ALUout),
    .in1(ReadData),
    .in2(inc_pc),
    .in3(ImmOp), 
    .sel(ResultSrc),
    .out(WD3)
);

endmodule
