module instr_mem #(
    parameter DATA_WIDTH = 32,
    parameter MEMORY_WIDTH = 1000
)(
    input logic rst,
    input logic [DATA_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);

// Declare mem that stores instructions
logic [7:0]memory[MEMORY_WIDTH-1:0];

// Load program into memory at start of simulation
initial begin 
    $readmemh("program.hex", memory);
end 
always_comb begin
    if (rst) begin
        RD = 32'b0;
    end
    else begin
        RD = {memory[A+3], memory[A+2], memory[A+1], memory[A+0]};
    end
end

endmodule
