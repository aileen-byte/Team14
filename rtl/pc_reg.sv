module pc_reg #(
    parameter DATA_WIDTH = 32 
)(
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  en,      // StallF = !en
    input  logic                  flush,   // branch/jump redirect
    input  logic [DATA_WIDTH-1:0] next_pc,
    output logic [DATA_WIDTH-1:0] pc
); 

always_ff @(posedge clk) begin
    if (rst) begin
        pc <= '0;
    end
    else if (flush) begin
        pc <= next_pc;     // redirect for branch/jump
    end
    else if (en) begin
        pc <= next_pc;     // normal sequential advance
    end
    else begin
        pc <= pc;          // explicit hold (stall)
    end
end

endmodule

