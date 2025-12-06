`timescale 1ns/1ps

module alu_testbench;
    // inputs 
    logic [31:0] ALUop1;
    logic [31:0] ALUop2;
    logic [2:0] ALUctrl;

    //outputs 
    logic [31:0] ALUout; 
    logic Zero; 
    
    // DUT
    ALU dut (
        .ALUop1(ALUop1),
        .ALUop2(ALUop2),
        .ALUctrl(ALUctrl),
        .ALUout(ALUout),
        .Zero(Zero)
    );

    task check(input string name, input logic [31:0] exp_out, input logic exp_zero); 
            $display("%s", name); 
            $display("ALUop1=%0d ALUop2=%0d ALUctrl=%b", ALUop1, ALUop2, ALUctrl); 
            $display("ALUout=%0d Zero=%b", ALUout, Zero);

            if(ALUout !== exp_out)
                $error("%s Failed: Expected ALUout=%d but got %d",
                name, exp_out, ALUout); 

            if(Zero !== exp_zero)
                $error("%s Failed: Expected Zero=%b but got %b",
                name, exp_zero, Zero); 

    endtask

    initial begin 

        // ADD Test 
        ALUop1 = 6; 
        ALUop2 = 7;
        ALUctrl = 3'b000; 

        #1; 

        check("ADD Test", 13, 0); 

        //Negative ADD Test 

        ALUop1 = -5; 
        ALUop2 = 3;
        ALUctrl = 3'b000; 

        #1; 

        check("ADD Negative Test", -2, 0); 

        //SUB Test 
        ALUop1 = 5;
        ALUop2 = 6;
        ALUctrl = 3'b001;

        #1; 

        check("SUB Test", -1, 0); 

        //AND
        ALUop1 = 5;
        ALUop2 = 6;
        ALUctrl = 3'b010;

        #1; 

        check("AND Test", 4, 0);

        //OR
        ALUop1 = 9;
        ALUop2 = 8; 
        ALUctrl = 3'b011; 

        #1; 

        check("OR Test", 9,0);

        //XOR
        ALUop1 = 9;
        ALUop2 = 8; 
        ALUctrl = 3'b100; 

        #1; 

        check("XOR Test", 1,0);

        //Max Integer Test 

        ALUop1 = 32'hFFFFFFFF;
        ALUop2 = 1;
        ALUctrl = 3'b000;

        #1; 

        check("ADD overflow wrap test", 32'h00000000, 1);

        //AND mask test

        ALUop1 = 32'hFFFF0000;
        ALUop2 = 32'h0000FFFF;
        ALUctrl = 3'b010;  
        #1; 
        check("AND mask test", 32'h00000000, 1);

        repeat (5) begin
            ALUop1 = $random;
            ALUop2 = $random;
            ALUctrl = 3'b000; // ADD
            #1;

            if (ALUout !== (ALUop1 + ALUop2))
                $error("Random ADD failed: expected %0d", ALUop1 + ALUop2);
        end


        $display("ALU Testbench Finished"); 
        $finish; 
    end
endmodule 

