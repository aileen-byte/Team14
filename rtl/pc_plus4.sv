module pc_plus4 #(
    parameter  DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]                pc, 
    output logic [DATA_WIDTH-1:0]           inc_pc
); 
    assign inc_pc = pc + 32'd4; 
endmodule
