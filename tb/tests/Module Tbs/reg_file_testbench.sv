/* verilator lint_off WIDTHTRUNC */
`timescale 1ns/1ps

module reg_file_testbench;
    parameter DATA_WIDTH = 32;

    // Inputs
    reg                   clk;
    reg [4:0]             AD1;
    reg [4:0]             AD2;
    reg [4:0]             AD3;
    reg                   WE3;
    reg [DATA_WIDTH-1:0]  WD3;

    // Outputs
    wire [DATA_WIDTH-1:0] RD1;
    wire [DATA_WIDTH-1:0] RD2;
    /* verilator lint_off UNUSEDSIGNAL */
    wire [DATA_WIDTH-1:0] a0;  // x10 debug output
    /* verilator lint_on UNUSEDSIGNAL */


    // Testbench vars
    integer i;
    reg [4:0] rnd_reg1, rnd_reg2;
    reg [31:0] rnd_val1, rnd_val2;

    // DUT
    reg_file #(.DATA_WIDTH(32)) dut(
        .clk(clk),
        .AD1(AD1), .AD2(AD2), .AD3(AD3),
        .WE3(WE3), .WD3(WD3),
        .RD1(RD1), .RD2(RD2), .a0(a0)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    task check;
        input [8*20:1] name;
        input [31:0] exp1;
        input [31:0] exp2;
        begin
            $display("%s", name);
            $display("RD1=%0d RD2=%0d", RD1, RD2);

            if(RD1 !== exp1)
                $display("%s Failed: RD1 expected %0d got %0d", name, exp1, RD1);
            if(RD2 !== exp2)
                $display("%s Failed: RD2 expected %0d got %0d", name, exp2, RD2);
        end
    endtask

    initial begin
        AD1 = 0; AD2 = 0; AD3 = 0;
        WE3 = 0; WD3 = 0;

        // --- Test Write and Read ---
        WE3 = 1; AD3 = 2; WD3 = 4678;
        @(posedge clk); #1;        
        AD1 = 2; AD2 = 0; #1;
        check("Test Write and Read", 4678, 0);

        // --- Test x0 immutability ---
        WE3 = 1; AD3 = 0; WD3 = 400;
        @(posedge clk); #1;        
        AD1 = 0; AD2 = 0; #1;
        check("Test x0 immutability", 0, 0);

        // --- Write enable ---
        WE3 = 1; AD3 = 4; WD3 = 800;
        @(posedge clk); #1;        
        WE3 = 0; AD3 = 4; WD3 = 900;
        @(posedge clk); #1;        
        AD1 = 4; AD2 = 0; #1;
        check("Write enable test WE3=0 must block writes", 800, 0);

        // --- Dual read test ---
        WE3 = 1; AD3 = 7; WD3 = 50;
        @(posedge clk); #1;
        AD3 = 9; WD3 = 99;
        @(posedge clk); #1;
        WE3 = 0;
        AD1 = 7; AD2 = 9; #1;
        check("Dual read RD1=x7 RD2=x9", 50, 99);

        // --- Read-after-write ---
        WE3 = 1; AD3 = 8; WD3 = 7089;
        @(posedge clk); #1;
        WE3 = 0;
        AD1 = 8; AD2 = 0; #1;
        check("Read after write test", 7089, 0);

        // --- Random fuzz tests ---
        for (i = 0; i < 50; i = i + 1) begin
            rnd_reg1 = $random % 31 + 1;
            rnd_reg2 = $random % 31 + 1;
            rnd_val1 = $random;
            rnd_val2 = $random;

            WE3 = 1; AD3 = rnd_reg1; WD3 = rnd_val1;
            @(posedge clk); #1;

            WE3 = 1; AD3 = rnd_reg2; WD3 = rnd_val2;
            @(posedge clk); #1;

            WE3 = 0;
            AD1 = rnd_reg1; AD2 = rnd_reg2;
            #1;

            if (RD1 !== rnd_val1)
                $display("Fuzz Fail: RD1 expected %0d from x%0d, got %0d", rnd_val1, rnd_reg1, RD1);

            if (RD2 !== rnd_val2)
                $display("Fuzz Fail: RD2 expected %0d from x%0d, got %0d", rnd_val2, rnd_reg2, RD2);
        end

        $display("Random fuzz test complete!");
        $display("Finished Reg_file tests!");
        $finish;
    end
endmodule


