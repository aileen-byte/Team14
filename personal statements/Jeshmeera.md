# Jeshmeera's personal statement 

CID: 02561534 

### Contributions
Single-cycle processor 

  - [Program Counter](#program-counter) 

Pipelined processor 

  - [Pipeline Registers](#pipeline-registers)

  - [Hazard Unit](#hazard-unit)

  - [Forwarding Unit](#forwarding-unit) 

###  Auxiliary Tasks  

  - [Repo and Documentation Support](#repo-and-documentation-support)

### Reflection  

   - [Challenges Faced](#challenges-faced)

   - [What I would do differently](#what-i-would-do-differently)

# Contributions 

## Program Counter 

In the single cycle processor, the Program counter (PC) determines the address of the next instruction to fetch each clock cycle. In our single cycle implementation the PC uses three main modules: PC_Reg, PC+4.  and branch adder, with a multiplexer selecting between sequential and branch execution. These modules work together to determine both sequential and branch instruction addresses based on the RISC-V ISA. 

### Simple single cycle diagram 

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/96877c81-becf-4c43-bc1e-00090ed8318a" />


The structure of our Program Counter (PC) unit was directly influenced by the single-cycle datapath diagram shown above. I used this exact layout to guide our implementation, ensuring that the PC register updates on each clock edge, while the PC+4 and branch adders operate combinationally to compute the next instruction address. The diagram also helped me understand how the PCsrc control signal drives the multiplexer, enabling conditional branching by selecting between PC+4 and PC+immediate. This visual breakdown strongly informed my own module organisation and wiring, allowing me to replicate the correct RISC-V control-flow behaviour in our single-cycle CPU.

### PC Register 

The PC Register stores the current instruction address and updates on each rising clock edge. 

- When reset is asserted, it is cleared to the starting address, ensuring the program always begins from a known location.
- Every cycle, it loads the next_PC value selected by the multiplexer, either PC + 4 for sequential execution or the branch target for conditional control-flow changes.

### Sequential and Branch Logic

The sequential and branch logic determines how the next instruction address is selected each cycle. 

- For normal execution, the PC+4 adder provides the next sequential address
- The branch adder computes PC + immediate for branch instructions.

### Top Implementation 

I also implemented the relevant code in the top-level module. Most notably, in the top-level module, we used the provided mux2 to select between the sequential address and the branch target based on PCsrc, and we (co-author Aileen) implemented this directly in the top. This was a purposeful design choice we made to simplify the design and avoid creating an unnecessary additional module.

### Testing 

I also created simple testbenches for each module to verify their basic functionality and ensure that every component behaved correctly before integration into the full processor. This was something we conciously aimed to do with most modules to minimise future sources of error. 



NOTE: ADD TESTBENCHES AND RESULTS HERE 

## Pipeline Registers 

In the pipelined processor, the pipeline registers separate the five execution stages and ensure that each instruction’s data and control signals are correctly forwarded each clock cycle. Our four registers:  IF/ID, ID/EX, EX/ME, and ME/WB store instruction fields, operands, immediates, ALU results, and control signals, allowing multiple instructions to execute concurrently. By holding these intermediate values between stages, the pipeline registers form the core structure that enables correct instruction flow and higher throughput compared to the single-cycle design.

### Piplined CPU diagram 

<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/db612f5d-4e9b-4287-a086-24f910e52c40" />

The structure of our pipeline registers was directly influenced by the pipelined datapath diagrams presented in Digital Design and Computer Architecture (RISC-V Edition) by Harris and Harris. This diagram strongly shaped our organisation and wiring of each register, helping us maintain proper instruction flow and accurately replicate the behaviour of a standard RISC-V pipelined processor.

Venice and I acted as the lead designers for this section. We followed this layout closely when designing our pipeline registers, ensuring that each register captured the correct data and control signals on every clock edge. The textbook diagrams made clear which signals needed to be carried between stages: such as instruction fields, immediates, ALU results, and writeback controls and how these values must remain stable for the subsequent stage while the next instruction progresses behind it.

I took on the task of designing the IF/ID and ID/EX registers while Venice completed the remaining two, a deliberate decision that allowed us to implement the pipeline quickly and efficiently and minimise errors before moving on to the Hazard Unit. 

Aileen played a crucial role in debugging and testing the pipelined design, making small but essential corrections where Venice and I had overlooked details to ensure proper functionality.

### IF/ID Register 

In our CPU, the IF/ID register captures the fetched instruction and PC+4, ensuring the Decode stage receives stable inputs each cycle.

### ID/EX Register 

In our design, the ID/EX register stores the decoded control signals, operands, and immediate values, providing the Execute stage with all the information needed to perform ALU operations and evaluate branches. 

## Hazard Unit 

## Forwarding Unit

## Testing 

As with the single-cycle design, I created simple testbenches for the pipeline modules to verify their functionality in isolation. 

NOTE: ADD TESTBENCHES AND RESULTS HERE 






# Auxilary Tasks 

# Repo and Documentation Support

# Reflection 

## Challenges Faced 

## What I would do differently 



















