module instr_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 100
)(
    input logic [DATA_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);

// Declare mem that stores instructions
logic [DATA_WIDTH-1:0]memory[MEMORY_WIDTH:0];

// Load program into memory at start of simulation
initial begin 
    $readmemh("../rtl/program.hex", memory);
end 

assign RD = memory[A[DATA_WIDTH-1:2]];

endmodule
