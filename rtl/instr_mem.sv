module instr_mem #(
    parameter DATA_WIDTH = 32,
)(
    input logic [DATA_WIDTH_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);

// Declare mem that stores instructions
logic [DATA_WIDTH-1:0]memory[2**(DATA_WIDTH-2)-1:0];

// Load program into memory at start of simulation
initial begin 
    $readmemh("program.hex", memory);
end 

assign RD = memory[A[DATA_WIDTH-1:2]];

endmodule
