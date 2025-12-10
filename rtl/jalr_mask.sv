module jalr_mask #(
    parameter DATA_WIDTH = 32
)(
    input [DATA_WIDTH-1:0]  ALUPC,
    output [DATA_WIDTH-1:0] jalrPC
);

assign jalrPC = {ALUPC[DATA_WIDTH-1:1], 1'b0};

endmodule
