module instr_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 100
)(
    input logic [DATA_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);

// Declare mem that stores instructions
logic [31:0] memory [0:MEMORY_WIDTH-1];

// Load program into memory at start of simulation
initial begin 
    $readmemh("/home/venicegh/Documents/Team14/rtl/program2.hex", memory);
    $display("Loaded bytes:");
    $display("0: %02h", memory[0]);
    $display("1: %02h", memory[1]);
    $display("2: %02h", memory[2]);
    $display("3: %02h", memory[3]);
end 

assign RD = memory[A >> 2];

endmodule
