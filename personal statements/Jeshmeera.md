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

## Simple single cycle diagram 

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/96877c81-becf-4c43-bc1e-00090ed8318a" />


The structure of our Program Counter (PC) unit was directly influenced by the single-cycle datapath diagram shown above. I used this exact layout to guide our implementation, ensuring that the PC register updates on each clock edge, while the PC+4 and branch adders operate combinationally to compute the next instruction address. The diagram also helped me understand how the PCsrc control signal drives the multiplexer, enabling conditional branching by selecting between PC+4 and PC+immediate. This visual breakdown strongly informed my own module organisation and wiring, allowing me to replicate the correct RISC-V control-flow behaviour in our single-cycle CPU.



## Pipeline Registers 

## Hazard Unit 

## Forwarding Unit

# Auxilary Tasks 

# Repo and Documentation Support

# Reflection 

## Challenges Faced 

## What I would do differently 



















