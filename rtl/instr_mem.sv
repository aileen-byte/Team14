module instr_mem #(
    parameter DATA_WIDTH = 32,
    parameter MEM_BYTES  = 131072       // memory size in bytes
)(
    input  logic [DATA_WIDTH-1:0] A,   // byte address from PC
    output logic [DATA_WIDTH-1:0] RD   // 32-bit instruction
);

    // Byte-addressed instruction memory
    logic [7:0] memory [0:MEM_BYTES-1];

    // Name of program file to load
    string program_file = "program.hex";   // default

    // Load hex file
    initial begin
        if ($value$plusargs("PROGRAM=%s", program_file)) begin
            $display("INSTR_MEM: Loading program file: %s", program_file);
        end else begin
            $display("INSTR_MEM: Using default program: %s", program_file);
        end

        $readmemh(program_file, memory);
    end

    localparam ADDR_BITS = $clog2(MEM_BYTES);
    logic [ADDR_BITS-1:0] addr;
    assign addr = A[ADDR_BITS-1:0];

    // Prevent out-of-range access
    logic out_of_range;
    assign out_of_range = ((addr+3) >= MEM_BYTES);

    // Little-endian assembly of the 32-bit instruction
    // Little-endian assembly of 32-bit instruction
    assign RD = out_of_range
                ? 32'h00000013        // NOP (ADDI x0,x0,0)
                : { memory[addr+3], memory[addr+2], memory[addr+1], memory[addr] };
endmodule
