module instr_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 100
)(
    input logic [DATA_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);

// Declare mem that stores instructions
logic [31:0] memory [0:MEMORY_WIDTH-1];
string memfile;
// Load program into memory at start of simulation
initial begin
        $display("Loading instruction memory from program.hex");
        $readmemh("program.hex", memory);
end

assign RD = memory[A[31:2]];

endmodule
