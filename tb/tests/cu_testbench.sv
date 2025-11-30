`timescale 1ns/1ps 

module control_unit_tb; 

    // inputs 
    logic [6:0] op;
    logic [2:0] funct3; 
    logic funct7b5;
    logic Zero; 

    // outputs 
    logic [1:0] PCSrc;
    logic [1:0] ResultSrc; 
    logic MemWrite; 
    logic [2:0] ALUctrl; 
    logic ALUSrc;
    logic [2:0] ImmSrc; 
    logic RegWrite; 

    cu_dut(
        .op(op),
        .funct3(funct3), 
        .funct7b5(funct7b5),
        .Zero(Zero), 
        .PCSrc(PCSrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .ALUctrl(ALUctrl),
        .ALUSrc(ALUSrc),
        .ImmSrc(ImmSrc),
        .RegWrite(RegWrite)
    ); 

    // Printing all control signals 

    initial begin 
        $display("CU testbench starting.... ");

        //ADDI Test 

        op = 7'b0010011;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0; 

        #1;

        show("ADDI"); 

        if(RegWrite !== 1) $error("ADDI Failed: RegWrite should be 1");
        if(ALUSrc !== 1) $error("ADDI Failed: ALUSrc should be 1");
        if(ALUctrl !== 3'b000) $error("ADDI Failed: ALUctrl should be ADD");
        if(MemWrite !== 0) $error("ADDI Failed: MemWrite should be 0");

        //ADD Test 

        op = 7'b0110011;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0;

        #1; 
        
        show("ADD");

        if(RegWrite !== 1) $error("ADD Failed: RegWrite should be 1");
        if(ALUSrc !== 0) $error("ADD Failed: ALUSrc should be 0");
        if(ALUctrl !== 3'b000) $error("ADD Failed: ALUctrl should be ADD");
        if(MemWrite !== 0) $error("ADD Failed: MemWrite should be 0");

        //SUB Test 

        op = 7'b0110011;
        funct3 = 3'b000;
        funct7b5 = 1; 
        Zero = 0; 

        #1; 

        show("SUB");

        if(RegWrite !== 1) $error("SUB Failed: RegWrite should be 1");
        if(ALUSrc !== 0) $error("SUB Failed: ALUSrc should be 0");
        if(ALUctrl !== 3'b001) $error("SUB Failed: ALUctrl should be SUB");
        if(MemWrite !== 0) $error("SUB Failed: MemWrite should be 0");

        //LOAD test 

        op = 7'b0000011;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0;

        #1;

        show("LOAD");

        if(RegWrite !== 0) $error("LOAD Failed: RegWrite should be 0");
        if(ALUSrc !== 1) $error("LOAD Failed: ALUSrc should be 1");
        if(ALUctrl !== ) $error("LOAD Failed: ALUctrl should be ");

        //

        $display("CU testbench finished");
        $finish; 


    end 

endmodule 
