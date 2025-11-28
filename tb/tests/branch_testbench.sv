
`timescale  1ns/1ps

module branch_tb;

    logic [2:0] funct3_i;
    logic [31:0] rs1_val_i;
    logic [31:0] rs2_val_i;
    logic branch_taken_o; 

    branch_unit dut (
        .funct3_i(funct3_i),
        .rs1_i(rs1_val_i),
        .rs2_i(rs2_val_i),
        .branch_taken_o(branch_taken_o)
    );

    initial begin
        //BEQ - Test1

        funct3_i = 3'b000;
        rs1_val_i = 10; 
        rs2_val_i = 10; 

        #1; 

        if(branch_taken_o !== 1) begin
            $error("BEQ test failed!");
        end
        else begin
            $display("BEQ passed!");
        end
        //BEQ - Test2

        funct3_i = 3'b000;
        rs1_val_i = 1;
        rs2_val_i = 10; 

        #1;

        if(branch_taken_o !== 0) begin
            $error("BEQ test 2 failed!");
        end
        else begin
            $display("BEQ test 2 passed");
        end
        // BNE - test 1  

        funct3_i = 3'b001;
        rs1_val_i = 5;
        rs2_val_i = 6;

        #1;

        if(branch_taken_o !== 1) begin
            $error("BNE test failed!");
        end
        else begin
            $display("BNE passed!");
        end

        // BNE - test 2 

        funct3_i = 3'b001;
        rs1_val_i = 10;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 0) begin
            $error("BNE test 2 failed!");
        end
        else begin
            $display("BNE test 2 passed");
        end

        // BLT test 1

        funct3_i = 3'b100;
        rs1_val_i = 11;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 0) begin
            $error("BLT test 1 failed!");
        end
        else begin
            $display("BLT test 1 passed");
        end

        // BLT test 2

        funct3_i = 3'b100;
        rs1_val_i = 5;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 1) begin
            $error("BLT test 2 failed!");
        end
        else begin
            $display("BLT test 2 passed!");
        end

        // BGE test 1

        funct3_i = 3'b101;
        rs1_val_i = 11;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 1) begin
            $error("BGE test 1 failed!");
        end
        else begin
            $display("BGE test 1 passed!");
        end

        // BGE test 2

        funct3_i = 3'b101;
        rs1_val_i = 5;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 0) begin
            $error("BGE test 2 failed!");
        end
        else begin
            $display("BGE test 2 passed");
        end

        //BLTU test 1

        funct3_i = 3'b110;
        rs1_val_i = -1;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 0) begin
            $error("BLTU test 1 failed");
        end else begin
            $display("BLTU test 1 passed");
        end

        //BLTU test 2 

        funct3_i = 3'b110;
        rs1_val_i = 5;
        rs2_val_i = -3; 

        #1;

        if(branch_taken_o !== 1) begin
            $error("BLTU test 2 failed!");
        end
        else begin
            $display("BLTU test 2 passed!");
        end


        //BGEU test 1

        funct3_i = 3'b110;
        rs1_val_i = 5;
        rs2_val_i = -3; 

        #1;

        if(branch_taken_o !== 0) begin
            $error("BGEU test 1 failed");
        end else begin
            $display("BGEU test 1 passed");
        end

        //BGEU test 2 

        funct3_i = 3'b110;
        rs1_val_i = -1;
        rs2_val_i = 10;

        #1;

        if(branch_taken_o !== 1) begin
            $error("BGEU test 2 failed!");
        end
        else begin
            $display("BGEU test 2 passed!");
        end

        $finish 

    end
endmodule

    







