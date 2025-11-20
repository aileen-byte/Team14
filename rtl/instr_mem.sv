module instr_mem(
    input logic [31:0] A, // Address from PC
    output logic [31:0] RD // Insstr output 
);
    // Declare mem that stores ins
    logic [31:0] memory[0: 255];

    // Load program into memory at start of simulation
    initial begin 
        $readmemh("program.hex", memory);
    end 

    assign RD = memory[A[31:2]];

endmodule
