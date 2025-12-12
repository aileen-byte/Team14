module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    input logic trigger,
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
logic                  ZeroE;

logic [DATA_WIDTH-1:0] ImmOp; 
logic [DATA_WIDTH-1:0] jalrPC;

// DECODE STAGE (D) SIGNALS 
logic         RegWriteD;
logic [1:0]   ResultSrcD;
logic         MemWriteD;
logic [1:0]   JumpD;
logic [1:0]   BranchD;
logic [2:0]   ALUControlD;
logic         ALUSrcD;
logic [2:0]   ImmSrcD;
logic [1:0]   StoreSizeD;
logic [1:0]   LoadSizeD;

logic [4:0] Rs1D, Rs2D, RdD;
assign Rs1D = InstrD[19:15];
assign Rs2D = InstrD[24:20];
assign RdD  = InstrD[11:7];

logic [DATA_WIDTH-1:0] PCD, InstrD, PCPlus4D;

// EXECUTE STAGE (E) SIGNALS 
logic         RegWriteE;
logic [1:0]   ResultSrcE;
logic         MemWriteE;
logic [1:0]   JumpE;
logic [1:0]   BranchE;
logic [2:0]   ALUControlE;
logic         ALUSrcE;
logic [1:0]   StoreSizeE;
logic [1:0]   LoadSizeE;

logic [DATA_WIDTH-1:0]     RD1E, RD2E;
logic [DATA_WIDTH-1:0]     PCE;
logic [4:0]                Rs1E, Rs2E, RdE;
logic [DATA_WIDTH-1:0]     ExtImmE;
logic [DATA_WIDTH-1:0]     PCPlus4E;

logic [1:0] PCSrcE;

// MEMORY STAGE (M) SIGNALS
logic                     RegWriteM;
logic                     MemWriteM;
logic [DATA_WIDTH-1:0]    ALUOutM;
logic [DATA_WIDTH-1:0]    WriteDataM;
logic [4:0]               WriteRegM; //RdM
logic [1:0]               ResultSrcM;
logic [DATA_WIDTH-1:0]    PCPlus4M;
logic [1:0]               StoreSizeM;
logic [DATA_WIDTH-1:0]    ReadDataM;
logic [1:0]               LoadSizeM;

// WRITEBACK STAGE (W) SIGNALS
logic                     RegWriteW;
logic [DATA_WIDTH-1:0]    ALUOutW;
logic [DATA_WIDTH-1:0]    ReadDataW;
logic [4:0]               WriteRegW; //RdW
logic [1:0]               ResultSrcW;
logic [DATA_WIDTH-1:0]    PCPlus4W;

// HAZARD UNIT SIGNALS
logic StallF, StallD, FlushD, FlushE;

//FORWARDING 
logic [1:0] ForwardAE, ForwardBE;

logic [DATA_WIDTH-1:0] SrcAE, SrcBE, SrcBE_preALUSrc;

//CACHE
logic [DATA_WIDTH-1:0] ReadDataCache;
logic [DATA_WIDTH-1:0] cache_to_memory_address;
logic [DATA_WIDTH-1:0] cache_to_memory_data;
logic cache_to_memory_write_enable;
logic [DATA_WIDTH-1:0] LoadSelecIn;
logic MissRead;
logic MissWrite;
logic memoryD;
logic memoryE;
logic memoryM;

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
    .memory(memoryD),
    .ALUctrl(ALUControlD),
    .ALUSrc(ALUSrcD),
    .ImmSrc(ImmSrcD),
    .RegWrite(RegWriteD),
    .LoadSize(LoadSizeD),

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
    .a0(a0)
);

cache CACHE (
    .clk(clk),
    .rst(rst),
    .memory(memoryM),
    .cache_write(MemWriteM),
    .memory_address(ALUOutM),
    .cache_data_in(WriteDataM),
    .memory_to_cache_data(ReadData),
    .StoreSize(StoreSizeM),
    .cache_data_out(ReadDataCache),
    .cache_to_memory_address(cache_to_memory_address),
    .cache_to_memory_data(cache_to_memory_data),
    .MissRead(MissRead),
    .MissWrite(MissWrite),
    .cache_to_memory_write_enable(cache_to_memory_write_enable)
);

data_mem #(
    .DATA_WIDTH(DATA_WIDTH)
) DM (
    .clk(clk),
    .ALUResult(ALUOutM),   
    .WriteDataCache(cache_to_memory_data),
    .WriteThroughAddress(cache_to_memory_address), 
    .WriteThroughWE(cache_to_memory_write_enable),  
    .WriteData(WriteDataM),   
    .MissWrite(MissWrite), 
    .StoreSize(StoreSizeM),     
    .RD(ReadData)        
);

mux memory_mux (
    .in0(ReadDataCache),
    .in1(ReadData),
    .sel(MissRead),
    .out(LoadSelecIn)
);

load_selec #(DATA_WIDTH) LS (
    .size(LoadSizeM),
    .byte_num(ALUOutM[1:0]),
    .mem_data(LoadSelecIn),
    .load_data(ReadDataM)
);

//alu
ALU myALU (
    .ALUop1(SrcAE),    
    .ALUop2(SrcBE),    
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

    .StallD(StallD),    
    .FlushD(FlushD),    

    .PCF(pc),           
    .PCPlus4F(inc_pc),  
    .InstrF(instr),    

    .PCD(PCD),        
    .InstrD(InstrD),
    .PCPlus4D(PCPlus4D)
);

ID_EX_Reg #(.DATA_WIDTH(DATA_WIDTH)) ID_EX (
    .clk(clk),
    .rst(rst),
    .FlushE(FlushE),    

    // Control signals in D
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),
    .LoadSizeD(LoadSizeD),
    .memoryD(memoryD),

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
    .LoadSizeE(LoadSizeE),
    .memoryE(memoryE),

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
    .LoadSizeE(LoadSizeE),
    .memoryE(memoryE),

    .RegWriteM(RegWriteM),
    .MemWriteM(MemWriteM),
    .ResultSrcM(ResultSrcM),
    .PCPlus4M(PCPlus4M),
    .ALUOutM(ALUOutM),
    .WriteDataM(WriteDataM),
    .WriteRegM(WriteRegM),
    .LoadSizeM(LoadSizeM),
    .memoryM(memoryM),

    .StoreSizeE(StoreSizeE),
    .StoreSizeM(StoreSizeM)
);

ME_WR_Reg #(.DATA_WIDTH(DATA_WIDTH)) MEM_WB (
    .clk(clk),
    .reset(rst),

    // From MEM stage
    .RegWriteM(RegWriteM),
    .ALUOutM(ALUOutM),
    .ReadDataM(ReadDataM),
    .WriteRegM(WriteRegM),

    .ResultSrcM(ResultSrcM),
    .PCPlus4M(PCPlus4M),

    // Outputs to WB stage
    .RegWriteW(RegWriteW),
    .ALUOutW(ALUOutW),
    .ReadDataW(ReadDataW),
    .WriteRegW(WriteRegW),
    .ResultSrcW(ResultSrcW),
    .PCPlus4W(PCPlus4W)
);

HazardUnit HZ (
    .RsD(Rs1D),    
    .RtD(Rs2D),   

    .WriteRegE(RdE),      

    .ResultSrcE(ResultSrcE),
    .PCSrcE(PCSrcE),

    .StallF(StallF),      
    .StallD(StallD),      
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
    .in0(RD1E),     
    .in1(WD3),    
    .in2(ALUOutM), 
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
    .in3(32'b0), 
    .sel(ResultSrcW),
    .out(WD3)
);

endmodule
