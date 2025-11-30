module reg_file #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk, // provides clock signal
    input   logic [4:0]             AD1, // rs1 19:15 Selects the register whose value will be output on RD1.
    input   logic [4:0]             AD2, // rs2 24:20 Selects the register whose value will be output on RD2
    input   logic [4:0]             AD3, // rd 11:7 Selects the destination register to write to when RegWrite = 1
    input   logic                   WE3, // controls wheter the register file performs a write on the clock
    input   logic [DATA_WIDTH-1:0]  WD3, // Write Data - Data that will be written into register A3 if RegWrite = 1
    
    output  logic [DATA_WIDTH-1:0]  RD1, // read data 1 
    output  logic [DATA_WIDTH-1:0]  RD2, // read data 2 
    output  logic [DATA_WIDTH-1:0]  a0  // x10 degub output 
);
    // 32x32 bit registers
    logic [DATA_WIDTH-1:0] regs [31:0]; // 5 bit address line

    //Initialise all registers to 0
    initial begin 
        integer i;
        for(i=0; i < 32; i=i+1) begin
            regs[i] = '0; 
        end
    end 


    always_ff @(posedge clk) begin
        if (WE3 && (AD3 != 5'd0)) begin
            regs[AD3] <= WD3;  
        end
        // Enforce x0 = 0 every cycle
        regs[0] <= '0;
    end

    assign RD1 = regs[AD1]; 
    assign RD2 = regs[AD2];

    assign a0 = regs[10];

endmodule
