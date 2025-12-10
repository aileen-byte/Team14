module top #(
    parameter DATA_WIDTH = 32
) (
    input logic clk,
    input logic rst,
    input logic trigger,
    output logic [DATA_WIDTH-1:0] x0,
    output logic [DATA_WIDTH-1:0] t0,
    output logic [DATA_WIDTH-1:0] t1,
    output logic [DATA_WIDTH-1:0] t2,    
    output logic [DATA_WIDTH-1:0] t3,
    output logic [DATA_WIDTH-1:0] t4,
    output logic [DATA_WIDTH-1:0] a1,
    output logic [DATA_WIDTH-1:0] a2,
    output logic [DATA_WIDTH-1:0] a3,
    output logic [DATA_WIDTH-1:0] a4, 
    output logic [DATA_WIDTH-1:0] a5,
    output logic [DATA_WIDTH-1:0] a6,  
    output logic [DATA_WIDTH-1:0] a0
);

// INSTRUCTION BLOCK WIRES 
logic [1:0]            PCSrc;
logic [DATA_WIDTH-1:0] inc_pc; 
logic [DATA_WIDTH-1:0] branch_pc; 
logic [DATA_WIDTH-1:0] next_pc; 
logic [DATA_WIDTH-1:0] pc; 
logic [DATA_WIDTH-1:0] instr;

// CONTROL UNIT WIRES
logic       RegWrite;
logic [2:0] ALUctrl;
logic       ALUSrc;
logic [2:0] ImmSrc;
logic [1:0] ResultSrc;
logic       MemWrite;
logic [1:0] MemWriteSize;
logic [1:0] LoadSize;
logic       Zero;

// REGISTER FILE WIRES
logic [DATA_WIDTH-1:0] WD3; 
logic [DATA_WIDTH-1:0] RD1; 
logic [DATA_WIDTH-1:0] RD2;  

// DATA MEMORY WIRES
logic [DATA_WIDTH-1:0] ReadData; 
logic [DATA_WIDTH-1:0] load_data; 

//ALU WIRES
logic [DATA_WIDTH-1:0] ALUop2;
logic [DATA_WIDTH-1:0] ALUout;
logic [DATA_WIDTH-1:0] ImmOp; 
logic [DATA_WIDTH-1:0] jalrPC;

//automatic trigger
logic auto_trigger = trigger;

pc_reg #(DATA_WIDTH) PCREG (
    .clk(clk), 
    .rst(rst), 
    .next_pc(next_pc),
    .pc(pc)
); 

pc_plus4 #(DATA_WIDTH) ADD4(
    .pc(pc), 
    .inc_pc(inc_pc)
); 

branch_adder #(DATA_WIDTH) BRADD (
    .pc(pc),
    .ImmOp(ImmOp), 
    .branch_pc(branch_pc)
); 

mux4 #(DATA_WIDTH) PCMUX (
    .in0(inc_pc),
    .in1(branch_pc),
    .in2(jalrPC),
    .in3(32'b0), 
    .sel(PCSrc),
    .out(next_pc)
);

instr_mem #(.DATA_WIDTH(DATA_WIDTH)) IMEM(
    .A(pc),
    .RD(instr)
);

control_unit CU(
    .op(instr[6:0]),
    .funct3(instr[14:12]),
    .funct7b5(instr[30]),
    .Zero(Zero),
    .PCSrc(PCSrc),
    .ResultSrc(ResultSrc),
    .MemWrite(MemWrite),
    .MemWriteSize(MemWriteSize),
    .LoadSize(LoadSize),
    .ALUctrl(ALUctrl),
    .ALUSrc(ALUSrc),
    .ImmSrc(ImmSrc),
    .RegWrite(RegWrite)
);

sign_extend SE(
    .instr(instr[31:7]),
    .ImmSrc(ImmSrc),
    .ImmOp(ImmOp)
);

reg_file #(DATA_WIDTH) RF (
    .clk(clk),
    .AD1(instr[19:15]),
    .AD2(instr[24:20]),
    .AD3(instr[11:7]),
    .WE3(RegWrite),
    .WD3(WD3),
    .RD1(RD1),
    .RD2(RD2),
    .x0(x0),
    .t0(t0),
    .t1(t1),
    .t2(t2),
    .t3(t3),
    .t4(t4),
    .a1(a1),
    .a2(a2),
    .a3(a3),
    .a4(a4),
    .a5(a5),
    .a6(a6),
    .a0(a0)
);

data_mem #(
    .DATA_WIDTH(DATA_WIDTH)
) DM (
    .clk(clk),
    .ALUResult(ALUout),
    .WriteData(RD2),   
    .WE(MemWrite),     
    .MemWriteSize(MemWriteSize),
    .RD(ReadData)         
);

load_selec #(DATA_WIDTH) LS (
    .size(LoadSize),
    .byte_num(ALUout[1:0]),
    .mem_data(ReadData),
    .load_data(load_data)
);

mux ALUMUX (
    .in0(RD2),
    .in1(ImmOp),
    .sel(ALUSrc),
    .out(ALUop2)
);

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

mux4 #(DATA_WIDTH) RESULT_MUX (
    .in0(ALUout),
    .in1(load_data),
    .in2(inc_pc),
    .in3(ImmOp), 
    .sel(ResultSrc),
    .out(WD3)
);

endmodule
