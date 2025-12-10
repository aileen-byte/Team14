module ID_EX_Reg #(
    parameter DATA_WIDTH = 32
)(
    input   logic                   clk, 
    input   logic                   rst, 

    input   logic                   FlushE, 

    input   logic                   RegWriteD,
    input   logic [1:0]             ResultSrcD,
    input   logic                   MemWriteD, 
    input   logic [1:0]             JumpD,
    input   logic [1:0]             BranchD,
    input   logic [2:0]             ALUControlD, 
    input   logic                   ALUSrcD,
    input logic [1:0] LoadSizeD,

    input   logic [DATA_WIDTH-1:0]  RD1D,
    input   logic [DATA_WIDTH-1:0]  RD2D, 
    input   logic [DATA_WIDTH-1:0]  PCD, 
    input   logic [4:0]             Rs1D,
    input   logic [4:0]             Rs2D,
    input   logic [4:0]             RdD, 
    input   logic [DATA_WIDTH-1:0]  ExtImmD, 
    input   logic [DATA_WIDTH-1:0]  PCPlus4D,

    output  logic                   RegWriteE, 
    output  logic [1:0]             ResultSrcE,
    output  logic                   MemWriteE,  
    output  logic [1:0]             JumpE, 
    output  logic [1:0]             BranchE,
    output  logic [2:0]             ALUControlE,  
    output  logic                   ALUSrcE, 
    output logic [1:0] LoadSizeE,

    output  logic [DATA_WIDTH-1:0]   RD1E,
    output  logic [DATA_WIDTH-1:0]   RD2E,  
    output  logic [DATA_WIDTH-1:0]   PCE, 
    output  logic [4:0]              Rs1E,
    output  logic [4:0]              Rs2E, 
    output  logic [4:0]              RdE, 
    output  logic [DATA_WIDTH-1:0]   ExtImmE,
    output  logic [DATA_WIDTH-1:0]   PCPlus4E, 

    input  logic [1:0] StoreSizeD,
    output logic [1:0] StoreSizeE
);

always_ff @(posedge clk) begin
    if(rst || FlushE) begin
        RegWriteE   <= '0;
        ResultSrcE  <= '0; 
        MemWriteE   <= '0; 
        JumpE       <= '0; 
        BranchE     <= '0; 
        ALUControlE <= '0; 
        ALUSrcE     <= '0; 
        RD1E        <= '0; 
        RD2E        <= '0; 
        PCE         <= '0; 
        Rs1E        <= '0; 
        Rs2E        <= '0; 
        RdE         <= '0;
        ExtImmE     <= '0; 
        PCPlus4E    <= '0;
        StoreSizeE <= '0;
        LoadSizeE <= '0;
    end 
    else begin 
        RegWriteE   <= RegWriteD;
        ResultSrcE  <= ResultSrcD; 
        MemWriteE   <= MemWriteD; 
        JumpE       <= JumpD; 
        BranchE     <= BranchD; 
        ALUControlE <= ALUControlD; 
        ALUSrcE     <= ALUSrcD; 
        RD1E        <= RD1D; 
        RD2E        <= RD2D; 
        PCE         <= PCD; 
        Rs1E        <= Rs1D; 
        Rs2E        <= Rs2D; 
        RdE         <= RdD;
        ExtImmE     <= ExtImmD; 
        PCPlus4E    <= PCPlus4D; 
        StoreSizeE <= StoreSizeD;
        LoadSizeE <= LoadSizeD;
    end
end 
endmodule
