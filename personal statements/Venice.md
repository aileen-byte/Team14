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

For read operations, the memory returns a full 32-bit word by assembling four consecutive bytes starting from the aligned address {ALUResult[31:2], 2'b00}. This ensures that all loads access a word-aligned boundary, matching the behaviour required for word-sized data in the RISC-V architecture. When writing, the module performs different store behaviours depending on the StoreSize signal: SB writes a single byte, SH writes two bytes, and SW writes an entire 32-bit word into memory. Data is written in little-endian format, consistent with RISC-V conventions.

Aileen and I chose to enhance the data memory by introducing the MemWriteSize signal because it significantly improved testability and increased the flexibility of our design. Without this signal, verifying store behaviour was much more difficult, as the size of each memory write was implicit. By explicitly encoding whether the operation is a byte, half-word, or word store, we gained clearer control over the memory system and made the design far easier to debug and extend.

The memory is initialised using a $readmemh call, which loads data from a data.hex file into the memory array at simulation start. Overall, this module provides the necessary data storage and retrieval functionality for load and store instructions while maintaining correct byte addressing, alignment, and memory formatting in accordance with the RISC-V ISA.

## Pipeline Registers 

## Mux 

## Forwarding Unit

# Top Implementation 

# Repo and Documentation Support

# Reflection 

## Challenges Faced 

## What I would do differently 




















