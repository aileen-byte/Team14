module pc_reg #(
    parameter WIDTH = 32, 
)(
    input logic                 clk,
    input logic                 rst,
    input logic  [WIDTH-1:0]    next_pc, 
    output logic [WIDTH-1:0]    pc
); 

always_ff @(posedge clk) begin
    if (rst)
        pc <= 32'b0;
    else
        pc <= pc_next;
end

endmodule