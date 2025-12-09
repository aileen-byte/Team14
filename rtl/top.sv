module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    input logic trigger,
    output logic [DATA_WIDTH-1:0] x0,
    output logic [DATA_WIDTH-1:0] t0,
    output logic [DATA_WIDTH-1:0] t1,
    output logic [DATA_WIDTH-1:0] t3,
    output logic [DATA_WIDTH-1:0] t4,
    output logic [DATA_WIDTH-1:0] a1,
    output logic [DATA_WIDTH-1:0] a2,
    output logic [DATA_WIDTH-1:0] a3,
    output logic [DATA_WIDTH-1:0] a4, 
    output logic [DATA_WIDTH-1:0] a5,
    output logic [DATA_WIDTH-1:0] a6,
    output  logic [DATA_WIDTH-1:0] a0
);

// INSTRUCTION BLOCK WIRES 
logic [DATA_WIDTH-1:0] inc_pc; //pc+4 
logic [DATA_WIDTH-1:0] branch_pc; //pc+imm
logic [DATA_WIDTH-1:0] next_pc; 
logic [DATA_WIDTH-1:0] pc; 
logic [DATA_WIDTH-1:0] instr;

// REGISTER FILE WIRES
logic [DATA_WIDTH-1:0] WD3;  // write data
logic [DATA_WIDTH-1:0] RD1;  // read data 1
logic [DATA_WIDTH-1:0] RD2;  // read data 2

// DATA MEMORY WIRES
logic [DATA_WIDTH-1:0] ReadData; // output from data memory

//ALU WIRES
logic [DATA_WIDTH-1:0] ALUoutE;
logic ZeroE;

logic [DATA_WIDTH-1:0] ImmOp; 
logic [DATA_WIDTH-1:0] jalrPC;

// DECODE STAGE (D) SIGNALS 
logic RegWriteD;
logic [1:0] ResultSrcD;
logic MemWriteD;
logic [1:0] JumpD;
logic [1:0] BranchD;
logic [2:0] ALUControlD;
logic ALUSrcD;
logic [2:0] ImmSrcD;
logic [1:0] StoreSizeD;

logic [4:0] Rs1D, Rs2D, RdD;
assign Rs1D = InstrD[19:15];
assign Rs2D = InstrD[24:20];
assign RdD  = InstrD[11:7];

logic [DATA_WIDTH-1:0] PCD, InstrD, PCPlus4D;

// EXECUTE STAGE (E) SIGNALS 
logic RegWriteE;
logic [1:0] ResultSrcE;
logic MemWriteE;
logic [1:0] JumpE;
logic [1:0] BranchE;
logic [2:0] ALUControlE;
logic ALUSrcE;
logic [1:0] StoreSizeE;

logic [DATA_WIDTH-1:0] RD1E, RD2E;
logic [DATA_WIDTH-1:0] PCE;
logic [4:0] Rs1E, Rs2E, RdE;
logic [DATA_WIDTH-1:0] ExtImmE;
logic [DATA_WIDTH-1:0] PCPlus4E;

logic [1:0] PCSrcE;

// MEMORY STAGE (M) SIGNALS
logic RegWriteM;
logic MemWriteM;
logic [DATA_WIDTH-1:0] ALUOutM;
logic [DATA_WIDTH-1:0] WriteDataM;
logic [4:0] WriteRegM; //RdM
logic [1:0] ResultSrcM;
logic [DATA_WIDTH-1:0] ExtImmM;
logic [DATA_WIDTH-1:0] PCPlus4M;
logic [1:0] StoreSizeM;

// WRITEBACK STAGE (W) SIGNALS
logic RegWriteW;
logic [DATA_WIDTH-1:0] ALUOutW;
logic [DATA_WIDTH-1:0] ReadDataW;
logic [4:0] WriteRegW; //RdW
logic [1:0] ResultSrcW;
logic [DATA_WIDTH-1:0] ExtImmW;
logic [DATA_WIDTH-1:0] PCPlus4W;

// HAZARD UNIT SIGNALS
logic StallF, StallD, FlushD, FlushE;

//FORWARDING 
logic [1:0] ForwardAE, ForwardBE;

logic [DATA_WIDTH-1:0] SrcAE, SrcBE, SrcBE_preALUSrc;

// pc register
pc_reg #(DATA_WIDTH) PCREG (
    .clk(clk), 
    .rst(rst),
    .en(~StallF), 
    .next_pc(next_pc),
    .pc(pc)
); 

// pc + 4
pc_plus4 #(DATA_WIDTH) ADD4(
    .rst(rst),
    .pc(pc), 
    .inc_pc(inc_pc)
); 

// branch adder 
branch_adder #(DATA_WIDTH) BRADD (
    .pc(PCE),
    .ImmOp(ExtImmE), 
    .branch_pc(branch_pc)
); 

// pc mux
mux4 #(DATA_WIDTH) PCMUX (
    .in0(inc_pc),
    .in1(branch_pc),
    .in2(jalrPC),
    .in3(32'b0), 
    .sel(PCSrcE),
    .out(next_pc)
);

pc_source PCSRC (
    .JumpType(JumpE),
    .BranchType(BranchE),
    .ZeroE(ZeroE),
    .PCSrcE(PCSrcE)
);

// Instruction Memory
instr_mem #(.DATA_WIDTH(DATA_WIDTH)) IMEM(
    .rst(rst),
    .A(pc),
    .RD(instr)
);

// control unit
control_unit CU(
    .op(InstrD[6:0]),
    .funct3(InstrD[14:12]),
    .funct7b5(InstrD[30]),
    .ResultSrc(ResultSrcD),
    .MemWrite(MemWriteD),
    .ALUctrl(ALUControlD),
    .ALUSrc(ALUSrcD),
    .ImmSrc(ImmSrcD),
    .RegWrite(RegWriteD),

    .BranchType(BranchD),
    .JumpType(JumpD),
    .MemWriteSize(StoreSizeD)
);

// Sign_extend 
sign_extend SE(
    .instr(InstrD[31:7]),
    .ImmSrc(ImmSrcD),
    .ImmOp(ImmOp)
);

// reg file
reg_file #(DATA_WIDTH) RF (
    .clk(clk),
    .rst(rst),
    .AD1(Rs1D),
    .AD2(Rs2D),
    .AD3(WriteRegW),
    .WE3(RegWriteW),
    .WD3(WD3),
    .RD1(RD1),
    .RD2(RD2),
    .x0(x0),
    .t0(t0),
    .t1(t1),
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
    .ALUResult(ALUOutM),    // memory address
    .WriteData(WriteDataM),       // data to write
    .MemWrite(MemWriteM),         // from control unit
    .RD(ReadData),          // output data
    .StoreSize(StoreSizeM)
);

//alu
ALU myALU (
    .ALUop1(SrcAE),    // forwarded ALU operand A
    .ALUop2(SrcBE),    // forwarded ALU operand B (after ALUSrc mux)
    .ALUctrl(ALUControlE),
    .ALUout(ALUoutE),
    .Zero(ZeroE)
);

jalr_mask jalr(
    .ALUPC(ALUoutE),
    .jalrPC(jalrPC)
);

IF_ID_Reg #(.DATA_WIDTH(DATA_WIDTH)) IF_ID (
    .clk(clk),
    .rst(rst),

    .StallD(StallD),    // from Hazard Unit
    .FlushD(FlushD),    // also from Hazard Unit (branch mispredict)

    .PCF(pc),           // current PC
    .PCPlus4F(inc_pc),  // PC+4
    .InstrF(instr),     // fetched instruction

    .PCD(PCD),          // outputs to Decode stage
    .InstrD(InstrD),
    .PCPlus4D(PCPlus4D)
);

ID_EX_Reg #(.DATA_WIDTH(DATA_WIDTH)) ID_EX (
    .clk(clk),
    .rst(rst),

    .FlushE(FlushE),     // also from Hazard Unit

    // Control signals in D
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),

    // Data signals
    .RD1D(RD1),
    .RD2D(RD2),
    .PCD(PCD),
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdD(RdD),
    .ExtImmD(ImmOp),
    .PCPlus4D(PCPlus4D),

    // E-stage outputs
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),
    .JumpE(JumpE),
    .BranchE(BranchE),
    .ALUControlE(ALUControlE),
    .ALUSrcE(ALUSrcE),

    .RD1E(RD1E),
    .RD2E(RD2E),
    .PCE(PCE),
    .Rs1E(Rs1E),
    .Rs2E(Rs2E),
    .RdE(RdE),
    .ExtImmE(ExtImmE),
    .PCPlus4E(PCPlus4E),

    .StoreSizeD(StoreSizeD),
    .StoreSizeE(StoreSizeE)
);

EX_ME_Reg #(.DATA_WIDTH(DATA_WIDTH)) EX_MEM (
    .clk(clk),
    .reset(rst),

    .RegWriteE(RegWriteE),
    .MemWriteE(MemWriteE),
    .ALUOutE(ALUoutE),
    .WriteDataE(SrcBE_preALUSrc),
    .WriteRegE(RdE),
    .ResultSrcE(ResultSrcE),
    .PCPlus4E(PCPlus4E),
    .ExtImmE(ExtImmE),

    .RegWriteM(RegWriteM),
    .MemWriteM(MemWriteM),
    .ResultSrcM(ResultSrcM),
    .PCPlus4M(PCPlus4M),
    .ALUOutM(ALUOutM),
    .WriteDataM(WriteDataM),
    .WriteRegM(WriteRegM),
    .ExtImmM(ExtImmM),

    .StoreSizeE(StoreSizeE),
    .StoreSizeM(StoreSizeM)
);

ME_WR_Reg #(.DATA_WIDTH(DATA_WIDTH)) MEM_WB (
    .clk(clk),
    .reset(rst),

    // From MEM stage
    .RegWriteM(RegWriteM),
    .ALUOutM(ALUOutM),
    .ReadDataM(ReadData),
    .WriteRegM(WriteRegM),

    .ResultSrcM(ResultSrcM),
    .PCPlus4M(PCPlus4M),
    .ExtImmM(ExtImmM),

    // Outputs to WB stage
    .RegWriteW(RegWriteW),
    .ALUOutW(ALUOutW),
    .ReadDataW(ReadDataW),
    .WriteRegW(WriteRegW),
    .ResultSrcW(ResultSrcW),
    .PCPlus4W(PCPlus4W),
    .ExtImmW(ExtImmW)
);

HazardUnit HZ (
    .RsD(Rs1D),     // rs1 in Decode stage
    .RtD(Rs2D),     // rs2 in Decode stage

    .WriteRegE(RdE),        // EX destination register

    .ResultSrcE(ResultSrcE), // EX-stage load indicator
    .PCSrcE(PCSrcE),

    .StallF(StallF),        // ⟵ connect to IF/ID reg
    .StallD(StallD),        // ⟵ connect to ID/EX reg
    .FlushD(FlushD),
    .FlushE(FlushE)
);

ForwardingUnit FW (
    .RsE(Rs1E),
    .RtE(Rs2E),

    .WriteRegM(WriteRegM),
    .WriteRegW(WriteRegW),

    .RegWriteM(RegWriteM),
    .RegWriteW(RegWriteW),

    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE)
);



mux3 #(32) FORWARD_A_MUX (
    .in0(RD1E),     // normal register value
    .in1(WD3),      // forwarding from WB stage
    .in2(ALUOutM),  // forwarding from MEM stage
    .sel(ForwardAE),
    .out(SrcAE)
);

mux3 #(32) FORWARD_B_PREALUSRC (
    .in0(RD2E), 
    .in1(WD3), 
    .in2(ALUOutM), 
    .sel(ForwardBE),
    .out(SrcBE_preALUSrc)
);

mux #(32) ALUSRC_MUX (
    .in0(SrcBE_preALUSrc),
    .in1(ExtImmE),
    .sel(ALUSrcE),
    .out(SrcBE)
);

// 4bit Mux
mux4 #(DATA_WIDTH) RESULT_MUX (
    .in0(ALUOutW),
    .in1(ReadDataW),
    .in2(PCPlus4W),
    .in3(ExtImmW), 
    .sel(ResultSrcW),
    .out(WD3)
);

endmodule
