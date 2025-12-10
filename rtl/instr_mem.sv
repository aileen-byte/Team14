module instr_mem #(
    parameter DATA_WIDTH = 32,
    MEMORY_WIDTH = 1000
)(
    input logic [DATA_WIDTH-1:0] A, // Address from PC
    output logic [DATA_WIDTH-1:0] RD // Insstr output 
);
    logic [7:0]memory[MEMORY_WIDTH-1:0];
    initial begin 
        $readmemh("program.hex", memory);
    end 
    assign RD = {memory[A+3], memory[A+2], memory[A+1], memory[A+0]};
endmodule
