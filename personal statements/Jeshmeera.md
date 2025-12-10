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
- Every cycle, it loads the next_PC value selected by the multiplexer—either PC + 4 for sequential execution or the branch target for conditional control-flow changes.

### Sequential and Branch Logic

The sequential and branch logic determines how the next instruction address is selected each cycle. 

- For normal execution, the PC+4 adder provides the next sequential address
- The branch adder computes PC + immediate for branch instructions.

In the top-level module, I used the provided mux2 component to choose between these two values based on the PCsrc control signal, ensuring correct behaviour for both sequential flow and conditional branching in the single-cycle processor.

## Pipeline Registers 

## Hazard Unit 

## Forwarding Unit

# Auxilary Tasks 

# Repo and Documentation Support

# Reflection 

## Challenges Faced 

## What I would do differently 



















