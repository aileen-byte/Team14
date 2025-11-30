module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0
);

// INSTRUCTION BLOCK WIRES 
logic [1:0] PCSrc;
logic [DATA_WIDTH-1:0] inc_pc; 
logic [DATA_WIDTH-1:0] branch_pc; 
logic [DATA_WIDTH-1:0] next_pc; 
logic [DATA_WIDTH-1:0] pc; 
logic [DATA_WIDTH-1:0] instr;

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
logic [DATA_WIDTH-1:0] ALUop2E;
logic [DATA_WIDTH-1:0] ALUoutE;
logic ZeroE;

logic [DATA_WIDTH-1:0] ImmOp; 
logic [DATA_WIDTH-1:0] jalrPC;

// DECODE STAGE (D) SIGNALS 
logic RegWriteD;
logic [1:0] ResultSrcD;
logic MemWriteD;
logic JumpD;
logic BranchD;
logic [2:0] ALUControlD;
logic ALUSrcD;

logic [DATA_WIDTH-1:0] RD1D, RD2D;
logic [4:0] Rs1D, Rs2D, RdD;
logic [DATA_WIDTH-1:0] ExtImmD;

// FETCH STAGE SIGNALS
logic StallF, StallD, FlushD;
logic [DATA_WIDTH-1:0] PCD, InstrD, PCPlus4D;

// EXECUTE STAGE (E) SIGNALS 
logic RegWriteE;
logic [1:0] ResultSrcE;
logic MemWriteE;
logic JumpE;
logic BranchE;
logic [2:0] ALUControlE;
logic ALUSrcE;
logic FlushE;
logic [DATA_WIDTH-1:0] RD1E, RD2E;
logic [DATA_WIDTH-1:0] PCE;
logic [4:0] Rs1E, Rs2E, RdE;
logic [DATA_WIDTH-1:0] ExtImmE;
logic [DATA_WIDTH-1:0] PCPlus4E;

// MEMORY STAGE (M) SIGNALS
logic RegWriteM;
logic MemtoRegM;
logic MemWriteM;
logic [DATA_WIDTH-1:0] ALUOutM;
logic [DATA_WIDTH-1:0] WriteDataM;
logic [4:0] WriteRegM;
logic [1:0] ResultSrcM;
logic [DATA_WIDTH-1:0] ExtImmM;
logic [DATA_WIDTH-1:0] PCPlus4M;

// WRITEBACK STAGE (W) SIGNALS
logic RegWriteW;
logic MemtoRegW;
logic [DATA_WIDTH-1:0] ALUOutW;
logic [DATA_WIDTH-1:0] ReadDataW;
logic [4:0] WriteRegW;
logic [1:0] ResultSrcW;
logic [DATA_WIDTH-1:0] ExtImmW;
logic [DATA_WIDTH-1:0] PCPlus4W;

// HAZARD (also the control unit???)
logic Jump;
logic Branch;



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
    .in3({DATA_WIDTH{1'b0}}), 
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
    .AD1(InstrD[19:15]),
    .AD2(InstrD[24:20]),
    .AD3(InstrD[11:7]),
    .WE3(RegWriteW),
    .WD3(WD3),
    .RD1(RD1),
    .RD2(RD2),
    .a0(a0)
);

data_mem #(
    .DATA_WIDTH(DATA_WIDTH)
) DM (
    .clk(clk),
    .ALUResult(ALUoutM),    // memory address
    .WriteData(WriteDataM),       // data to write
    .WE(MemWriteM),         // from control unit
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
    .ALUop1(RD1E),
    .ALUop2(ALUop2E),
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

    .StallF(StallF),    // from Hazard Unit
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

    .StallD(StallD),     // from Hazard Unit
    .FlushE(FlushE),     // also from Hazard Unit

    // Control signals
    .RegWriteD(RegWrite),
    .ResultSrcD(ResultSrc),
    .MemWriteD(MemWrite),
    .JumpD(Jump),
    .BranchD(Branch),
    .ALUControlD(ALUctrl),
    .ALUSrcD(ALUSrc),

    // Data signals
    .RD1D(RD1),
    .RD2D(RD2),
    .PCD(PCD),
    .Rs1D(InstrD[19:15]),
    .Rs2D(InstrD[24:20]),
    .RdD(InstrD[11:7]),
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
    .PCPlus4E(PCPlus4E)
);

EX_ME_Reg #(.DATA_WIDTH(DATA_WIDTH)) EX_MEM (
    .clk(clk),
    .reset(rst),

    // From EX stage
    .RegWriteE(RegWriteE),
    .MemtoRegE(ResultSrcE[0]),   // If MemToReg is encoded in ResultSrc
    .MemWriteE(MemWriteE),
    .ALUOutE(ALUout),
    .WriteDataE(RD2E),
    .WriteRegE(RdE),
    .ResultSrcE(ResultSrcE),
    .ExtImmE(ExtImmE),
    .PCPlus4E(PCPlus4E),

    // Outputs to MEM stage
    .RegWriteM(RegWriteM),
    .MemtoRegM(MemtoRegM),
    .MemWriteM(MemWriteM),
    .ALUOutM(ALUOutM),
    .WriteDataM(WriteDataM),
    .WriteRegM(WriteRegM),

    .ResultSrcM(ResultSrcM),
    .ExtImmM(ExtImmM),
    .PCPlus4M(PCPlus4M)
);

ME_WR_reg #(.DATA_WIDTH(DATA_WIDTH)) MEM_WB (
    .clk(clk),
    .reset(rst),

    // From MEM stage
    .RegWriteM(RegWriteM),
    .MemtoRegM(MemtoRegM),
    .ALUOutM(ALUOutM),
    .ReadDataM(ReadData),
    .WriteRegM(WriteRegM),

    .ResultSrcM(ResultSrcM),
    .ExtImmM(ExtImmM),
    .PCPlus4M(PCPlus4M),

    // Outputs to WB stage
    .RegWriteW(RegWriteW),
    .MemtoRegW(MemtoRegW),
    .ALUOutW(ALUOutW),
    .ReadDataW(ReadDataW),
    .WriteRegW(WriteRegW),
    .ResultSrcW(ResultSrcW),
    .ExtImmW(ExtImmW),
    .PCPlus4W(PCPlus4W)
);

HazardUnit HZ (
    .RsD(InstrD[19:15]),     // rs1 in Decode stage
    .RtD(InstrD[24:20]),     // rs2 in Decode stage

    .RsE(Rs1E),             // from ID/EX pipeline register
    .RtE(Rs2E),             // from ID/EX pipeline register

    .WriteRegE(RdE),        // EX destination register
    .WriteRegM(WriteRegM),  // MEM destination register

    .MemtoRegE(ResultSrcE[0]),  // EX loads
    .MemtoRegM(MemtoRegM),      // MEM loads
    .RegWriteE(RegWriteE),      // EX regwrite
    .RegWriteM(RegWriteM),      // MEM regwrite

    .BranchD(BranchD),      // branch in Decode

    .StallF(StallF),        // ⟵ connect to IF/ID reg
    .StallD(StallD),        // ⟵ connect to ID/EX reg
    .FlushE(FlushE)         // ⟵ connect to ID/EX flush
);


// 4bit Mux
mux4 #(DATA_WIDTH) RESULT_MUX (
    .in0(ALUoutW),
    .in1(ReadDataW),
    .in2(PCPlus4W),
    .in3(ExtImmW), 
    .sel(ResultSrcW),
    .out(WD3)
);

endmodule
