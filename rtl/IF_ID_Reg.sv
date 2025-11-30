module IF_ID_Reg #(
    parameter DATA_WIDTH = 32
)(
    input   logic                   clk, 
    input   logic                   rst, 

    input   logic                   StallF, 
    input   logic                   FlushD,

    input   logic [DATA_WIDTH-1:0]  PCF,
    input   logic [DATA_WIDTH-1:0]  PCPlus4F,
    input   logic [DATA_WIDTH-1:0]  InstrF, 

    output  logic [DATA_WIDTH-1:0]   PCD, 
    output  logic [DATA_WIDTH-1:0]   InstrD,
    output  logic [DATA_WIDTH-1:0]   PCPlus4D

);

always_ff @(posedge clk) begin
    if(rst || FlushD) begin
        PCD             <= '0;
        PCPlus4D        <= '0; 
        InstrD          <= '0; 
    end 
    else if (!StallF) begin 
        PCD             <= PCF;
        PCPlus4D        <= PCPlus4F; 
        InstrD          <= InstrF;
    end
end 

endmodule