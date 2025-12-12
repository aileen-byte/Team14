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
    
endmodule

