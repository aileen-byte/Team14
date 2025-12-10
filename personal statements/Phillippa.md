# Contents
- Overview 
- CU, Instruction_Mem and Sign_extend 
- Testbenches
- Debugging
- Adding Data Memory Cache 
- Mistakes I Made 
- Refection 

#  CU, Intstruction_Mem and Sign_extend


## CU 

## Intstruction_Mem 
## Sign_extend 

# Testbenchs 
## Writing CU Testbench 
Initially, I wrote an incorrect branch_testbench discussed further in 'Mistakes I made'. I then wrote the CU testbench. 
My CU testbench caught a design error in the CU. PCSrc was set to Immediate, not Jump. 
![[Screenshot 2025-11-30 at 14.04.42.png]]
JAL set to branch PC instead of initalising a new jump PC. 
![[Screenshot 2025-11-30 at 14.07.52.png]]
Also, found another error in which JALR was carrying stale control signals. 

The Control Unit initially failed several instruction tests because not all output signals were given default values. This caused leftover control signals from previous instructions to persist, leading to incorrect behaviour in JAL, JALR, and branch operations. Additionally, the `PCSrc` constants were incorrectly encoded, causing jump instructions to select the wrong PC path, and a missing `Immediate` constant caused a compile error. After adding full default assignments and correcting the `PCSrc` encodings, all instructions produced the expected control signals and the CU passed the complete testbench.

## ALU Testbench 

I wrote a comprehensive SystemVerilog testbench to verify the RV32I ALU. It included directed tests for all operations (ADD, SUB, AND, OR, XOR), corner-case checks (overflow and masking), and a set of randomised ADD tests. I created a reusable `check()` task to automatically compare ALU outputs with expected values.

During testing, I discovered a bug in the ALU: the Zero flag was being assigned twice, causing incorrect results for non-SUB instructions. I identified and fixed the issue by computing the Zero flag once from the final ALU output. After the fix, all tests passed under Verilator, confirming that the ALU behaves correctly and is ready for integration.

## Reg_file Testbench 

During this part of the project, I focused on verifying and debugging the Register File module for our Reduced RISC-V CPU. I built a complete SystemVerilog testbench that generates its own clock, applies deterministic and randomized test cases, and checks all register behaviours including x0 immutability, write-enable control, dual-port reads, and read-after-write timing. A large part of the work involved diagnosing why expected values weren’t being written or read, which led me to identify issues with initialisation, write-timing, and the testbench’s use of non-blocking assignments. By iterating through these problems and refining both the DUT and testbench, I achieved a fully passing suite of directed and fuzz tests. This process strengthened my understanding of synchronous vs asynchronous behaviour in the register file and improved my confidence in writing robust verification code.

# Debugging 
### After Pipelining 
During the debugging stage of the project, I focused on integrating all modules into the pipelined CPU and ensuring they worked correctly together under Verilator. A large amount of time was spent resolving structural issues, such as inconsistent module naming, missing files (e.g., `ME_WR_Reg`), incorrect port widths, and implicit nets created by typos like `ALUoutW` vs. `ALUOutW`. I also identified several wiring errors inside `top.sv`, particularly around PC control, instruction memory routing, and control-signal propagation between pipeline stages. Many warnings—undriven signals, unused nets, width mismatches, and asynchronous/synchronous reset conflicts—helped uncover hidden design defects that weren’t caught by the unit testbenches. After cleaning these up, I corrected the testbench by removing leftover VBuddy calls so that it compiled and ran fully within the Verilator environment. Once the CPU executed the full F1 program successfully, I confirmed the behaviour visually using GTKWave, inspecting PC progression, instruction flow, and stable control signals across the pipeline stages. This debugging phase improved my understanding of how small structural mistakes cascade through a pipelined CPU, reinforcing the importance of consistent naming, complete default assignments, and careful pipeline wiring.


## **2. Forwarding Unit Not Correctly Integrated**

Another major issue was the incomplete or incorrect wiring of the **Forwarding Unit**. Although the logic for detecting data hazards was partially implemented, the ALU inputs were not properly multiplexed based on `forwardA` and `forwardB`. As a result, dependent instructions would read stale register values instead of the most recent results from EX/MEM or MEM/WB.

I redesigned and re-integrated the forwarding logic to follow the conventional RISC-V pipelining structure:

- EX/MEM forwarding takes priority (`2'b10`),
    
- MEM/WB forwarding applies when EX/MEM is not relevant (`2'b01`),
    
- otherwise register file outputs are used.
    

With these corrections, the ALU consistently receives the most up-to-date operand values, eliminating incorrect execution in back-to-back dependent instructions.


After the fix, the pipeline correctly delays the dependent instruction by one cycle, ensuring functional correctness across all load-use sequences.

# Mistakes I made 
One of the main mistakes I made early on was attempting to write and verify the branch unit testbench before the rest of the pipeline and supporting modules were complete. Because several team members were still developing their parts, the hardware required for the testbench did not yet exist, meaning the testbench could not run and produced misleading errors. When I returned to it later, I realised that the design of the branch logic had changed and that my testbench instantiated signals and modules that were no longer part of the CPU. As a result, I had to discard the entire branch testbench and instead focus on writing dedicated CU and ALU testbenches.

Another mistake was assuming the Control Unit would behave correctly without fully resetting unused signals. In practice, I discovered that failing to give every output a default value caused leftover control signals to “leak” into subsequent instructions. This created bugs that were difficult to diagnose because they only appeared after specific instruction sequences. Through debugging, I learned to always initialise every control signal explicitly, especially in combinational logic.

Although these mistakes slowed my progress, they significantly improved my understanding of pipeline structure, testbench design, and debugging methodology. They also helped me develop a more disciplined workflow, where I write testbenches only when the underlying hardware is stable and review modules systematically for naming and structural correctness.

