# Venice's personal statement 

CID: 02559434

### Contributions

Single-cycle processor 

  - [ALU](#alu)

  - [Data Mem](#data-mem)

Pipelined processor 

  - [Pipeline Registers](#pipeline-registers)

  - [Mux types](#mux)

  - [Top Implementation](#top-implementation) 

###  Auxiliary Tasks  

  - [Repo and Documentation Support](#repo-and-documentation-support)

### Reflection  

   - [Challenges Faced](#challenges-faced)

   - [What I would do differently](#what-i-would-do-differently)

# Contributions 

## Simple Single Cycle Diagram (Lab 4)

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/559af967-2254-4d58-ab8f-dcc40b8ef88c" />

During our time in lab 4 and spliting up the section, I volenteered to do the red section which included the ALU, Reg File, and multiplexer (already provided). 

## Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/62fbb526-c526-4252-8709-36710a8e8c9f" />

## ALU

The ALU (Arithmetic Logic Unit) is one of the core components of the CPU datapath. Its primary role is to perform the arithmetic and logical operations required by RISC-V instructions. In our implementation, the ALU supports a set of arithmetic operations—ADD and SUB—as well as logical operations such as AND, OR, and XOR. Additionally, a pass-through operation is included, which simply forwards the second operand (ALUop2). A default case is also implemented to set the output to zero for any unsupported ALU control value.

In the earlier Lab 4 design, an explicit equality (EQ) operation existed within the ALU to support branch decisions. However, in the full single-cycle implementation, this operation was removed and replaced with a dedicated Zero logic block. After the ALU computes its result, the Zero output is asserted if the result is equal to zero, implemented as Zero = (ALUout == {DATA_WIDTH{1'b0}});. For branch instructions such as BEQ and BNE, the ALU performs a subtraction between the two source registers, and the Zero signal indicates whether the two values were equal. This simplifies the ALU while still enabling correct branch behaviour under the RISC-V ISA. 

## Data Mem

In the single-cycle processor, the data memory module provides byte-addressable read and write access for load and store instructions defined in the RISC-V ISA. The memory is implemented as an array of 8-bit entries, allowing flexible support for byte (SB), half-word (SH), and word (SW) store operations. During instruction execution, the ALU generates a 32-bit address which is used both to select the target memory location and determine how many consecutive bytes should be written based on the store size control signal.

## Pipeline Registers 

## Mux 

## Forwarding Unit

# Top Implementation 

# Repo and Documentation Support

# Reflection 

## Challenges Faced 

## What I would do differently 




















