module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);

    // PC BLOCK WIRES 
    logic [31:0] pc; 
    logic [31:0] inc_pc; 
    logic [31:0] branch_pc; 
    logic [31:0] next_pc; 


    // pc register
    pc_reg PCREG (
        .clk(clk), 
        .rst(rst), 
        .next_pc(next_pc),
        .pc(pc)
    ); 

    // pc + 4
    pc_plus4 ADD4(
        .pc(pc), 
        .inc_pc(inc_pc)
    ); 

    // branch adder 
    branch_adder BRADD (
        .pc(pc),
        .ImmOp(ImmOp), 
        .branch_pc(branch_pc), 
    ); 

    mux #(32) PCMUX (
        .in0(branch.pc),
        .in1(inc_pc), 
        .sel(PCsrs),
        .out(next_pc)
    ); 

    assign a0 = 32'd5;

endmodule
