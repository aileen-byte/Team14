# Philippa's Personal Statement 

CID: 02596628

### Contributions

- [Overview](#overview)
    
### Analysis of my Work 
  
- [CU, Instruction_Mem and Sign_extend](#cu-instruction_mem-and-sign_extend)
- [Testbenches](#testbenches)
- [Debugging](#debugging)
- [Multi cycled Cache](#multi-cycled-cache)
    
### Reflection 
  
- [Mistakes I Made](#mistakes-i-made)
- [Reflection](#reflection)

# Overview 

My main role was implementing cu, instruction_mem and sign_extend in the single cycle. Helping Aileen debug the pipelined CPU, writing testbenches and implemeting blocking cache for a multi-cycle CPU. I am grateful for this role as it gave me a good understanding of all of the modules and taught me how to debug. 

# CU, Instruction_Mem and Sign_extend

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/96877c81-becf-4c43-bc1e-00090ed8318a" />

## CU 
I wrote part of the control unit that decodes ADDI and BNE. It sets safe default control signals, then for ADDI enables register write with an I-type immediate added in the ALU, and for BNE selects a B-type immediate, does rs1 - rs2 in the ALU, and sets PCSrc to take the branch when rs1 != rs2 (i.e. Zero == 0).

## Sign_extend 

I also wrote the sign_extend module to generate 32-bit immediates from the raw instruction bits. For I-type instructions it extracts bits [31:20] and sign-extends them, and for B-type branches it reconstructs the split immediate from the scattered fields and appends the low zero bit before sign-extending. This was a good exercise in carefully mapping the RISC-V encoding to hardware, as a single misplaced bit would send branches to entirely the wrong address.

# Testbenches
## CU Testbench 

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
    
            $display("CU testbench finished");
            $finish; 
    
        end 
    
    endmodule  

Initially, I wrote an incorrect branch_testbench discussed further in 'Mistakes I made'. I then wrote the CU testbench. 
My CU testbench caught a design error in the CU. PCSrc was set to Immediate, not Jump.

<img width="448" height="377" alt="Screenshot 2025-12-11 at 09 43 42" src="https://github.com/user-attachments/assets/358a4a40-25bd-4335-8e08-9afcaa9b1ea2" />

JAL set to branch PC instead of initalising a new jump PC. 

<img width="446" height="143" alt="Screenshot 2025-12-11 at 09 44 10" src="https://github.com/user-attachments/assets/498ce554-eb33-42b1-8022-93b49daf70c1" />

Also, found another error in which JALR was carrying stale control signals. 

Our Control Unit initially failed several instruction tests because some outputs lacked default values, so stale control signals persisted and broke JAL, JALR and branch behaviour. We also mis-encoded the PCSrc constants and omitted an Immediate constant, causing incorrect PC selection and a compile error. After adding full default assignments and fixing the PCSrc encodings, all control signals were correct and the CU passed the full testbench.

## ALU Testbench 

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

I wrote a comprehensive SystemVerilog testbench to verify the ALU made by Venice. It included directed tests for all operations (ADD, SUB, AND, OR, XOR), corner-case checks (overflow and masking), and a set of randomised ADD tests. I created a reusable `check()` task to automatically compare ALU outputs with expected values.

During testing, I discovered a bug in the ALU: the Zero flag was being assigned twice, causing incorrect results for non-SUB instructions. I identified and fixed the issue by computing the Zero flag once from the final ALU output. After the fix, all tests passed under Verilator, confirming that the ALU behaves correctly and is ready for integration. Venice also wrote a c++ testbench for final integration.  

## Reg_file Testbench 
    
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

During this part of the project, I focused on verifying and debugging the Register File module for our Reduced RISC-V CPU. I built a complete SystemVerilog testbench that generates its own clock, applies deterministic and randomized test cases, and checks all register behaviours including x0 immutability, write-enable control, dual-port reads, and read-after-write timing. A large part of the work involved diagnosing why expected values weren’t being written or read, which led me to identify issues with initialisation, write-timing, and the testbench’s use of non-blocking assignments. By iterating through these problems and refining both the DUT and testbench, I achieved a fully passing suite of directed and fuzz tests. This process strengthened my understanding of synchronous vs asynchronous behaviour in the register file and improved my confidence in writing robust verification code.

# Debugging 
### After Pipelining 

During the debugging stage of the project, I focused on integrating all modules into the pipelined CPU and ensuring they worked correctly together under Verilator. A large amount of time was spent resolving structural issues, such as inconsistent module naming, missing files (e.g., `ME_WR_Reg`), incorrect port widths, and implicit nets created by typos like `ALUoutW` vs. `ALUOutW`. I also identified several wiring errors inside `top.sv`, particularly around PC control, instruction memory routing, and control-signal propagation between pipeline stages. 

Many warnings—undriven signals, unused nets, width mismatches, and asynchronous/synchronous reset conflicts—helped uncover hidden design defects that weren’t caught by the unit testbenches. After cleaning these up, I corrected the testbench by removing leftover VBuddy calls so that it compiled and ran fully within the Verilator environment. Once the CPU executed the full F1 program successfully, I confirmed the behaviour visually using GTKWave, inspecting PC progression, instruction flow, and stable control signals across the pipeline stages. This debugging phase improved my understanding of how small structural mistakes cascade through a pipelined CPU, reinforcing the importance of consistent naming, complete default assignments, and careful pipeline wiring.

# Main Issues I found 

## **1. JALR/JAL in CU** 

The CU didn't specify the difference between a JAL jump and and JALR jump, this caused issues in the 4_jal_ret test. 

One issue I ran into while implementing the Control Unit was with the jump instructions, JAL and JALR. At first, both instructions behaved inconsistently in simulation, and it took a while to realise that the problem wasn’t in the immediate generation or the ALU, but in the CU itself. We had only set a generic jump signal, meaning JAL and JALR were effectively treated the same, even though they require different PC sources: JAL jumps to PC + immediate, while JALR must use the ALU-computed address. Once I introduced distinct encodings for each jump type and routed them properly, the CPU immediately started behaving as expected. 


## **2. Forwarding Not Correctly Integrated**

Another major issue was the Forwarding Unit wiring. The hazard detection logic existed, but the ALU inputs weren’t actually selected using ForwardAE and ForwardBE, so dependent instructions sometimes saw stale register values instead of the EX/MEM or MEM/WB results. I rewired the forwarding to follow the standard RISC-V convention: EX/MEM has priority (2'b10), then MEM/WB (2'b01), otherwise the register file (2'b00). This ensures the ALU always sees the latest operands for back-to-back ALU dependencies, while load-use hazards are still handled by the hazard unit with a one-cycle stall.

Another major issue was the Forwarding Unit wiring. The original design tried to do decode stage forwarding in some modules and not in others, and the ALU inputs weren’t really using ForwardAE/ForwardBE. I rewired it to do standard EX-stage forwarding, EX/MEM first, then MEM/WB, otherwise the register file, so the ALU now always sees the latest operands, with any remaining load-use cases handled by a one-cycle stall in the hazard unit.

## **3. Reg-File** 

The LUI test wasn’t passing, and I couldn’t work out why. When I opened GTKWave I realised that x1 was never being written – it stayed at zero for the whole run.

Originally, my register file was writing on the same clock edge that the rest of the design (and my testbench) was sampling values. That meant reads and writes were effectively happening at the same time, so the read ports could see either the old value or the new one depending on how the simulator scheduled events. In practice, this showed up as off-by-one behaviour: I’d write to a register and then read it straight away, but the testbench would sometimes still see the previous value.

To fix this, I moved the write logic to the negative edge of the clock:
    
    always_ff @(negedge clk) begin
        if (rst) ...
        else if (WE3 && AD3 != 0)
            regs[AD3] <= WD3;
    end

After this change, the writes happened cleanly between sampling points, and the LUI test started passing with x1 updating as expected.

## Mistakes I made while Debugging 

The main mistake I made while debugging was not reading the textbook carefully before I started. That meant I overcomplicated the design and added unnecessary logic that later had to be removed. If I’d spent a bit of time up front really understanding what the textbook expected, I would have saved a lot of time. Instead, I ended up misdiagnosing issues that actually had simple fixes.

# Multi Cycled Cache 

Ailleen wrote a cache that worked in a single-cycle it was my job to implement it in a multi-cycled cpu. I choose to use a finite state machine, because cache misses and refills happen as a sequence of timed steps and an FSM cleanly controls those actions across multiple cycles. I wrote 4 stages: COMPARE, WRITE_BACK, ALLOCATE and REFILL. 

```mermaid
stateDiagram-v2
    direction LR

    Compare --> Compare: Hit
    Compare --> WriteBack: Miss

    WriteBack --> Allocate
    Allocate --> Refill
    Refill --> Compare
```

One problem I hit was that the original design assumed the memory address stayed constant, but in my multi-cycle version the address could change while handling a miss, so the wrong value was sometimes used in the miss states. I fixed this by latching the key signals at COMPARE and reusing those latched values throughout the miss-handling states.

# Mistakes I made 

One mistake I made early on was writing the branch testbench before the rest of the pipeline was ready. Key modules hadn’t been implemented yet, so the testbench produced misleading errors and quickly became outdated as the design evolved. When I revisited it, most of the signals no longer matched the CPU, so I scrapped it and focused on writing dedicated CU and ALU testbenches instead.

Although these mistakes slowed my progress, they significantly improved my understanding of pipeline structure, testbench design, and debugging methodology. They also helped me develop a more disciplined workflow, where I write testbenches only when the underlying hardware is stable and review modules systematically for naming and structural correctness.

# Reflection 

Looking back, this project taught me as much about workflow as it did about hardware. I’d now:

- Spend more time up front reading the textbook and agreeing a clear architecture and naming scheme as a team.
    
- Only write full system-level testbenches once the main modules are stable, and rely on smaller unit testbenches earlier on.
    
- Be stricter about keeping the top-level and cache wiring simple and well-documented, so that later changes don’t turn into a wiring             puzzle.



