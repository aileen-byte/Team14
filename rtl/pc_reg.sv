module pc_reg #(
    parameter DATA_WIDTH = 32 
)(
    input logic                 clk,
    input logic                 rst,
    input  logic                en,
    input logic  [DATA_WIDTH-1:0]    next_pc, 
    output logic [DATA_WIDTH-1:0]    pc
); 

always_ff @ (posedge clk) begin
    if (rst)
        pc <= 32'b0;
    else if (en)
        pc <= next_pc;
end

endmodule
