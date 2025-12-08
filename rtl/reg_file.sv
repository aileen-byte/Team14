module reg_file #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   rst,

    // Read ports (asynchronous)
    input   logic [4:0]             AD1,   // rs1
    input   logic [4:0]             AD2,   // rs2

    // Write port (synchronous, negedge)
    input   logic [4:0]             AD3,   // rd
    input   logic                   WE3,   // write enable
    input   logic [DATA_WIDTH-1:0]  WD3,   // write data

    // Outputs
    output  logic [DATA_WIDTH-1:0]  RD1,
    output  logic [DATA_WIDTH-1:0]  RD2,
    output  logic [DATA_WIDTH-1:0]  a0
);

    // 32 registers of 32 bits
    logic [DATA_WIDTH-1:0] regs [31:0];

    // ================================================================
    // Register reset (optional: RISC-V only mandates x0=0)
    // ================================================================
    always_ff @(posedge rst) begin
        integer i;
        for (i = 0; i < 32; i++)
            regs[i] <= '0;
    end

    // ================================================================
    // WRITE — must occur on FALLING EDGE for pipelined CPU
    // ================================================================
    always_ff @(negedge clk) begin
        if (!rst) begin
            if (WE3 && (AD3 != 5'd0)) begin
                $display("RF WRITE @ %0t: x%0d <= 0x%08h", $time, AD3, WD3);
                regs[AD3] <= WD3;
            end
        end

        // enforce x0 = 0 after every write cycle
        regs[0] <= '0;
    end

    // ================================================================
    // ASYNCHRONOUS READS — required by RV32I microarchitecture
    // ================================================================
    assign RD1 = regs[AD1];
    assign RD2 = regs[AD2];

    // Debug port: x10 (a0)
    assign a0 = regs[10];

endmodule

