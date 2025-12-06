/* verilator lint_off DECLFILENAME */
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

    control_unit cu_dut(
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

    task show(input string name);
        $display("---- %s ----", name);
        $display("PCSrc=%b ResultSrc=%b MemWrite=%b ALUSrc=%b ALUctrl=%b ImmSrc=%b RegWrite=%b",
            PCSrc, ResultSrc, MemWrite, ALUSrc, ALUctrl, ImmSrc, RegWrite);
    endtask


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
        if(PCSrc !== 0) $error("PCSrc Failed");

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
        if(PCSrc !== 0) $error("PCSrc Failed");

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
        if(PCSrc !== 0) $error("PCSrc Failed");

        //LOAD Test 

        op = 7'b0000011;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0;

        #1;

        show("LOAD");

        if(RegWrite !== 1) $error("LOAD Failed: RegWrite should be 1");
        if(ALUSrc !== 1) $error("LOAD Failed: ALUSrc should be 1");
        if(ALUctrl !== 3'b000) $error("LOAD Failed: ALUctrl should be ADD");
        if(ResultSrc !== 2'b01)  $error("LOAD Failed: ResultSrc should be Memory");
        if(ImmSrc !== 3'b000) $error("LOAD Failed: ImmSrc should be I_TYPE");
        if(PCSrc !== 0) $error("PCSrc Failed");

        //STORE Test 
        op = 7'b0100011;
        funct3 = 3'b000;

        #1;

        show("STORE"); 

        if(MemWrite !== 1) $error("STORE Failed: MemWrite wrong");
        if(RegWrite !== 0) $error("STORE Failed: RegWrite must be 0");
        if(ALUSrc !== 1) $error("STORE Failed: ALUSrc must be 1");
        if(PCSrc !== 0) $error("PCSrc Failed");

        // LUI Test 
        op = 7'b0110111; 
        funct3 = 3'b000;
        funct7b5 = 1'b0;
        Zero = 1'b0;

        #1; 

        show("LUI");

        if(ImmSrc !== 3'b100) $error("LUI Failed: ImmSrc wrong");
        if(PCSrc !== 0) $error("PCSrc Failed");


        //BEQ Test 
        //op = 7'b1100011; 
        //funct3 = 3'b000;
        //Zero = 1; 

       // #1; 

        //show("BEQ taken");

        //if(PCSrc !== 2'b01) $error("BEQ Failed: PCSrc should be Immediate");

        //BEQ not taken 
        //Zero = 0;
        //#1; 
        //if(PCSrc !== 2'b00) $error("BEQ Failed: PCSrc should be 0 when not taken");

        //BNE Test 
        op = 7'b1100011;
        funct3 = 3'b001; 
        Zero = 0; 

        #1; 
        
        show("BNE taken");
        if(PCSrc !== 2'b01) $error("BNE Failed: PCSrc should select a branch target");

        //BNE not taken 
        Zero = 1;
        #1; 
        show("BNE not taken");
        if(PCSrc !== 2'b00) $error("BNE Failed: PCSrc should be PC+4 when not taken");

        //JAL Test

        op = 7'b1101111;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0; 

        #1;
        
        show("JAL");
        if(PCSrc !== 2'b10) $error("JAL Failed");
        if(RegWrite !== 1) $error("JAL Failed"); 

        //JALR Test 

        op = 7'b1100111;
        funct3 = 3'b000;
        funct7b5 = 0;
        Zero = 0; 

        #1; 

        if(PCSrc !== 2'b11) $error("JALR Failed");
        if(RegWrite !== 1) $error("JAL Failed"); 


        //SB Test 

        //LBU Test 

        $display("CU testbench finished");
        $finish; 

    end 

endmodule  

