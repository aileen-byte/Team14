module pc_plus4 #(
    parameter  DATA_WIDTH = 32
)(
    input logic rst,
    input logic [DATA_WIDTH-1:0]                pc, 
    output logic [DATA_WIDTH-1:0]           inc_pc
); 

always_comb begin
    if (rst) begin
        inc_pc = 32'b0;
    end
    else begin
        inc_pc = pc + 32'd4;
    end
end

endmodule
