module branch_adder #(
    parameter DATA_WIDTH = 32 
)(
    input logic [DATA_WIDTH-1:0]                pc, 
    input logic [DATA_WIDTH-1:0]             ImmOp,
    output logic [DATA_WIDTH-1:0]         branch_pc
); 

assign branch_pc = pc + ImmOp;

endmodule 
