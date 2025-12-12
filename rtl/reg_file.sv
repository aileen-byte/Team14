module reg_file #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk, 
    input   logic [4:0]             AD1, // rs1 19:15 
    input   logic [4:0]             AD2, // rs2 24:20 
    input   logic [4:0]             AD3, // rd 11:7
    input   logic                   WE3, 
    input   logic [DATA_WIDTH-1:0]  WD3, // data to be written
    output  logic [DATA_WIDTH-1:0]  RD1,  
    output  logic [DATA_WIDTH-1:0]  RD2,
    output  logic [DATA_WIDTH-1:0]  a0
);
    logic [DATA_WIDTH-1:0] regs [31:0];

    always_ff @(posedge clk) begin
        if (WE3 && AD3 != 0) begin
            regs[AD3] <= WD3;  
        end
    end

    assign RD1 = regs[AD1]; 
    assign RD2 = regs[AD2];
    assign a0 = regs[10];
endmodule
