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
    output  logic [DATA_WIDTH-1:0]  x0,
    output  logic [DATA_WIDTH-1:0]  t0, 
    output  logic [DATA_WIDTH-1:0]  t1,
    output  logic [DATA_WIDTH-1:0]  t3,
    output  logic [DATA_WIDTH-1:0]  t4,
    output logic [DATA_WIDTH-1:0] a1,
    output logic [DATA_WIDTH-1:0] a2,
    output logic [DATA_WIDTH-1:0] a3,
    output logic [DATA_WIDTH-1:0] a4,
    output logic [DATA_WIDTH-1:0] a5,
    output logic [DATA_WIDTH-1:0] a6,
    output logic [DATA_WIDTH-1:0] s0,
    output logic [DATA_WIDTH-1:0] s1,
    output logic [DATA_WIDTH-1:0] t2,
    output  logic [DATA_WIDTH-1:0]  a0
);
    logic [DATA_WIDTH-1:0] regs [31:0];

    always_ff @(negedge clk) begin
        if (rst) begin
            for (int i = 0; i < 32; i++)
                regs[i] <= 32'b0;
        end 
        else if (WE3 && AD3 != 0) begin
            regs[AD3] <= WD3;  
        end
    end

    assign RD1 = regs[AD1]; 
    assign RD2 = regs[AD2];

    assign a0 = regs[10];

    assign x0 = regs[0];
    assign t0 = regs[5];
    assign t1 = regs[6];
    assign t3 = regs[28];
    assign t4 = regs[29];
    assign a1 = regs[11];
    assign a2 = regs[12];
    assign a3 = regs[13];
    assign a4 = regs[14];
    assign a5 = regs[15];
    assign a6 = regs[16];
    assign s0 = regs[8];
    assign s1 = regs[9];
    assign t2 = regs[7];
endmodule

