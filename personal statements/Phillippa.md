# Philippa's Personal Statement 

CID: 02596628

### Contributions

- [Overview](#overview)
    
### Analysis of my Work 
  
- [Control Unit, Instruction_Mem and Sign_extend](#control-unit-instruction_mem-and-sign_extend)
- [Testbenches](#testbenches)
- [Debugging](#debugging)
- [Multi cycled Cache](#multi-cycled-cache)
    
### Reflection 
  
- [Mistakes I Made](#mistakes-i-made)
- [Reflection](#reflection)

# Overview 

Core RTL design (single-cycle CPU): wrote control_unit.sv for ADDI/BNE, contributed to JAL/JALR and branch control, and implemented sign_extend.sv and instr_mem.sv used in both the single-cycle and pipelined CPUs.

Verification in SystemVerilog: authored directed and random CU, ALU and reg_file testbenches (*_tb.sv) and used them to drive fixes in the RTL.

Pipeline integration & debugging: fixed structural and wiring bugs in top.sv (PC path, forwarding, hazard logic, reset behaviour) until the pipelined CPU passed the F1 and reference tests under Verilator.

Multi-cycle data cache: extended the single-cycle cache into a multi-cycle blocking cache with a finite-state machine and stall signalling, integrated with the data memory interface.

# Control Unit, Instruction_Mem and Sign_extend

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/96877c81-becf-4c43-bc1e-00090ed8318a" />

## Control Unit 
I wrote part of the control unit that decodes ADDI and BNE. It sets safe default control signals, then for ADDI enables register write with an I-type immediate added in the ALU, and for BNE selects a B-type immediate, does rs1 - rs2 in the ALU, and sets PCSrc to take the branch when rs1 != rs2 (i.e. Zero == 0). The more comprehensive implementation of the control unit was designed and implemented by Aileen. 

## Sign_extend 

I wrote the sign_extend module to generate 32-bit immediates from the raw instruction bits. For I-type instructions it extracts bits [31:20] and sign-extends them, and for B-type branches it reconstructs the split immediate from the scattered fields and appends the low zero bit before sign-extending. This was a good exercise in carefully mapping the RISC-V encoding to hardware, as a single misplaced bit would send branches to entirely the wrong address.

# Testbenches
## CU Testbench 

<img width="543" height="1350" alt="image" src="https://github.com/user-attachments/assets/878d409b-84a5-4560-b996-f2f8276657df" />

<img width="511" height="1139" alt="image" src="https://github.com/user-attachments/assets/e902903a-b150-4657-993d-b45b022fb247" />
 
My CU testbench caught a design error in the CU. PCSrc was set to Immediate, not Jump. This is proof that the use of these testbenches throught the project was crutial for proper implementation of our CPU. 

<img width="448" height="377" alt="Screenshot 2025-12-11 at 09 43 42" src="https://github.com/user-attachments/assets/358a4a40-25bd-4335-8e08-9afcaa9b1ea2" />

JAL set to branch PC instead of initalising a new jump PC. 

<img width="446" height="143" alt="Screenshot 2025-12-11 at 09 44 10" src="https://github.com/user-attachments/assets/498ce554-eb33-42b1-8022-93b49daf70c1" />

Another issue found was an error in which JALR was carrying stale control signals. 

Our Control Unit initially failed several instruction tests because some outputs lacked default values, so stale control signals persisted and broke JAL, JALR and branch behaviour. We also wrongly coded the PCSrc constants and omitted an Immediate constant, causing incorrect PC selection and a compile error. After adding full default assignments and fixing the PCSrc encodings, all control signals were correct and the CU passed the full testbench. Venice also wrote a c++ testbench for final integration.

After these fixes, my CU testbench now passes all directed cases for ADDI, BNE, JAL and JALR, and its waveforms match the expected PC and control-signal behaviour from the lecture slides.

## ALU Testbench 

Though the ALU was written by Venice during the debugging stage i decided to make a fully comprehensive system verilog test to ensure full functionality within the ALU. 

<img width="421" height="1402" alt="image" src="https://github.com/user-attachments/assets/311b971a-bfb1-4dbf-accb-c3c40d725c5e" />

This included directed tests for all operations (ADD, SUB, AND, OR, XOR), corner-case checks (overflow and masking), and a set of randomised ADD tests. I created a reusable `check()` task to automatically compare ALU outputs with expected values.

During testing, I discovered a bug in the ALU: the Zero flag was being assigned twice, causing incorrect results for non-SUB instructions. I identified and fixed the issue by computing the Zero flag once from the final ALU output. After the fix, all tests passed under Verilator, confirming that the ALU behaves correctly and is ready for integration. Venice also wrote a c++ testbench for final integration.  

<img width="672" height="411" alt="Screenshot 2025-12-11 at 13 54 34" src="https://github.com/user-attachments/assets/c9458910-dcfe-4c07-90db-9d3bd46eaa4c" />

The final ALU testbench runs ~N directed checks plus 100+ randomised ADD cases under Verilator with no failures, giving us strong confidence that the ALU is correct before integration.

## Reg_file Testbench 

<img width="482" height="1344" alt="image" src="https://github.com/user-attachments/assets/874ddfd1-e4c8-4b4d-8c08-f636e6f44cae" />

The Reg_file.sv was initially written by Venice but as a part of my debugging I decided to make a testbench in system verilog for our Reduced RISC-V CPU. I built the testbench to generates its own clock, applies deterministic and randomized test cases, and checks all register behaviours including x0 immutability, write-enable control, dual-port reads, and read-after-write timing. A large part of the work involved diagnosing why expected values weren’t being written or read, which led me to identify issues with initialisation, write-timing, and the testbench’s use of non-blocking assignments. By iterating through these problems and refining both the DUT and testbench, I achieved a fully passing suite of directed and fuzz tests. This process strengthened my understanding of synchronous vs asynchronous behaviour in the register file and improved my confidence in writing robust verification code. After the upgrade to the full CPU Venice made another testbench in C++ to ensure all our testbenches are consistant. 

With the negedge-write change in the register file, all directed tests and random fuzz runs now pass. I also confirmed my results in GTKWave. 

# Debugging 

### After Pipelining 

During the debugging stage of the project, I focused on integrating all modules into the pipelined CPU and ensuring they worked correctly together under Verilator. A large amount of time was spent resolving structural issues, such as inconsistent module naming, incorrect port widths, and implicit nets created by typos like `ALUoutW` vs. `ALUOutW`. I also identified wiring errors inside `top.sv` around PC control, instruction memory routing, and control-signal propagation between pipeline stages. 

Many warnings from undriven signals, unused nets, width mismatches, and asynchronous/synchronous reset conflicts helped uncover hidden design defects that weren’t caught by the unit testbenches. After cleaning these up, I corrected the testbench by removing leftover VBuddy calls so that it compiled and ran fully within the Verilator environment. Once the CPU executed the full F1 program successfully, I confirmed the behaviour visually using GTKWave, inspecting PC progression, instruction flow, and stable control signals across the pipeline stages. This debugging phase improved my understanding of how small structural mistakes cascade through a pipelined CPU, reinforcing the importance of consistent naming, complete default assignments, and careful pipeline wiring.

# Main Issues I found 

## **1. JALR/JAL in CU** 

The CU didn't specify the difference between a JAL jump and and JALR jump, this caused issues in the 4_jal_ret test. 

One issue I ran into while implementing the Control Unit was with the jump instructions, JAL and JALR. At first, both instructions behaved inconsistently in simulation, and it took a while to realise that the problem wasn’t in the immediate generation or the ALU, but in the CU itself. We had only set a generic jump signal, meaning JAL and JALR were effectively treated the same, even though they require different PC sources: JAL jumps to PC + immediate, while JALR must use the ALU-computed address. Once I introduced distinct encodings for each jump type and routed them properly, the CPU immediately started behaving as expected. 


## **2. Forwarding Not Correctly Integrated**

Another issue found was in the Forwarding Unit wiring. The hazard detection logic existed, but the ALU inputs weren’t actually selected using ForwardAE and ForwardBE, so dependent instructions sometimes saw stale register values instead of the EX/MEM or MEM/WB results. I rewired the forwarding to follow the standard RISC-V convention: EX/MEM has priority (2'b10), then MEM/WB (2'b01), otherwise the register file (2'b00). This ensures the ALU always sees the latest operands for back-to-back ALU dependencies, while load-use hazards are still handled by the hazard unit with a one-cycle stall.

Another major issue was the Forwarding Unit wiring. The original design tried to do decode stage forwarding in some modules and not in others, and the ALU inputs weren’t really using ForwardAE/ForwardBE. I rewired it to do standard EX-stage forwarding, EX/MEM first, then MEM/WB, otherwise the register file, so the ALU now always sees the latest operands, with any remaining load-use cases handled by a one-cycle stall in the hazard unit.

## **3. Reg-File** 

The LUI test wasn’t passing, and I couldn’t work out why. When I opened GTKWave I realised that x1 was never being written – it stayed at zero for the whole run.

Originally, the register file was writing on the same clock edge that the rest of the design (and my testbench) was sampling values. That meant reads and writes were effectively happening at the same time, so the read ports could see either the old value or the new one depending on how the simulator scheduled events. In practice, this showed up as off-by-one behaviour: I’d write to a register and then read it straight away, but the testbench would sometimes still see the previous value.

To fix this, I moved the write logic to the negative edge of the clock:
    
    always_ff @(negedge clk) begin
        if (rst) ...
        else if (WE3 && AD3 != 0)
            regs[AD3] <= WD3;
    end

After this change, the writes happened cleanly between sampling points, and the LUI test started passing with x1 updating as expected.

# Multi Cycled Cache 

Aileen implemented the majority of single cycle data cache that appears in our final submission. In parallel, I experimented with extending this into a multi-cycle blocking cache controlled by a small finite state machine. The prototype used states like COMPARE, WRITE_BACK, ALLOCATE and REFILL to model realistic miss handling and asserted a cachestall signal back to the CPU whenever a miss was in progress.

It didn't fully verify and integrate it into the pipelined CPU without risking regressions in the working design. As a team we therefore chose to keep the simpler single cycle cache for the final hand in. 

```mermaid
stateDiagram-v2
    direction LR

    Compare --> Compare: Hit
    Compare --> WriteBack: Miss

    WriteBack --> Allocate
    Allocate --> Refill
    Refill --> Compare
```

One problem I had was that the original design assumed the memory address stayed constant, but in my multi-cycle version the address could change while handling a miss, so the wrong value was sometimes used in the miss states. I fixed this by latching the key signals at COMPARE and reusing those latched values throughout the miss-handling states. This exercise made me much more comfortable designing FSMs around memory systems and reasoning about timing and handshakes between modules.

# Auxilary 

I helped the team stay organised when it came to testing, I used Makefile to standardise how we built and ran the tests (tb/doit.sh), which helped the team reproduce failures quickly. I created a whatapp groupchat for easy communication, ensured team memebers communicated with one another by making sure we gave one another regular updates about progress with various modules.   

# Mistakes I made 

One mistake I made early on was writing the branch testbench before the rest of the pipeline was ready. Key modules hadn’t been implemented yet, so the testbench produced misleading errors and quickly became outdated as the design evolved. When I revisited it, most of the signals no longer matched the CPU, so I scrapped it and focused on writing dedicated CU and ALU testbenches instead.

Although these mistakes slowed my progress, they significantly improved my understanding of pipeline structure, testbench design, and debugging methodology. They also helped me develop a more disciplined workflow, where I write testbenches only when the underlying hardware is stable and review modules systematically for naming and structural correctness.

The main mistake I made while debugging was not reading the Harris and Harris textbook carefully before I started. That meant I overcomplicated the design and added unnecessary logic that later had to be removed. If I’d spent a bit of time up front really understanding what the textbook expected, I would have saved a lot of time. Instead, I ended up misdiagnosing issues that actually had simple fixes.

# Reflection 

This project also forced me to internalise several hardware concepts that rarely show up in small lab exercises:

– How write timing (posedge vs negedge) affects register file semantics in a pipelined CPU

– Why hazard and forwarding logic must be designed around the exact pipeline stage ordering 

– How little-endian byte addressing interacts with immediate generation and branch targets.
Making (and then fixing) mistakes in each of these areas has given me a much deeper understanding than simply following the textbook design.

Looking back, this project taught me as much about workflow as it did about hardware. I’d now:

- Spend more time up front reading the textbook and agreeing a clear architecture and naming scheme as a team.
    
- Only write full system-level testbenches once the main modules are stable, and rely on smaller unit testbenches earlier on.
    
- Be stricter about keeping the top-level and cache wiring simple and well-documented, so that later changes don’t turn into a wiring puzzle.





