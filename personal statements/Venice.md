# Venice's personal statement 

CID: 02559434

### Contributions

Single-cycle processor 

  - [ALU](#alu)

  - [Data Mem](#data-mem)

  - [Multiplexers](#multiplexers)

  - [Top Implementation](#top-implementation-for-single-cycle)

Pipelined processor 

  - [Pipeline Registers](#pipeline-registers)

  - [Further Multiplexers](#further-multiplexers)

  - [Top Implementation](#top-implementation-for-pipeline) 

###  Auxiliary Tasks 

  - [Repo and Documentation Support](#repo-and-documentation-support)

### Reflection  

   - [Challenges Faced](#challenges-faced)

   - [What I would do differently](#what-i-would-do-differently)

# Single Cycle CPU Contributions 

## Simple Single Cycle Diagram (Lab 4)

<img width="2012" height="950" alt="image" src="https://github.com/user-attachments/assets/559af967-2254-4d58-ab8f-dcc40b8ef88c" />

During Lab 4, when our group divided the processor components among us, I volunteered to implement the red section of the datapath, which included the ALU, the register file, and the provided 2-bit multiplexer.

## Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/62fbb526-c526-4252-8709-36710a8e8c9f" />

## ALU

The ALU (Arithmetic Logic Unit) is one of the core components of the CPU datapath. Its primary role is to perform the arithmetic and logical operations required by RISC-V instructions. In our implementation, the ALU supports a set of arithmetic operations - ADD and SUB - as well as logical operations AND, OR, and XOR. Additionally, a pass-through operation is included, which simply forwards the second operand (ALUop2). A default case is also implemented to set the output to zero for any unsupported ALU control value.

In the earlier Lab 4 design, an explicit equality (EQ) operation existed within the ALU to support branch decisions. However, in the full single-cycle implementation, this operation was removed and replaced with a dedicated Zero logic block. After the ALU computes its result, the Zero output is asserted if the result is equal to zero, implemented as Zero = (ALUout == {DATA_WIDTH{1'b0}});. For branch instructions such as BEQ and BNE, the ALU performs a subtraction between the two source registers, and the Zero signal indicates whether the two values were equal. This simplifies the ALU while still enabling correct branch behaviour under the RISC-V ISA. 

###Testing the ALU 
<img width="651" height="1540" alt="image" src="https://github.com/user-attachments/assets/608b7806-b7d8-4bdc-83bf-0c0340dcc12a" />
<img width="180" height="171" alt="image" src="https://github.com/user-attachments/assets/ff31f5e9-b928-472a-98bf-fa64773c2670" />
To ensure propper testing throughout the project testbenches were used to test each induvidual module.  


## Data Mem

In the single-cycle processor, the data memory module provides byte-addressable read and write access for load and store instructions defined in the RISC-V ISA. The memory is implemented as an array of 8-bit entries, allowing flexible support for byte (SB), half-word (SH), and word (SW) store operations. During instruction execution, the ALU generates a 32-bit address which is used both to select the target memory location and determine how many consecutive bytes should be written based on the store size control signal.

For read operations, the memory returns a full 32-bit word by assembling four consecutive bytes starting from the aligned address {ALUResult[31:2], 2'b00}. This ensures that all loads access a word-aligned boundary, matching the behaviour required for word-sized data in the RISC-V architecture. When writing, the module performs different store behaviours depending on the StoreSize signal: SB writes a single byte, SH writes two bytes, and SW writes an entire 32-bit word into memory. Data is written in little-endian format, consistent with RISC-V conventions.

Aileen and I chose to enhance the data memory by introducing the MemWriteSize signal because it significantly improved testability and increased the flexibility of our design. Without this signal, verifying store behaviour was much more difficult, as the size of each memory write was implicit. By explicitly encoding whether the operation is a byte, half-word, or word store, we gained clearer control over the memory system and made the design far easier to debug and extend.

The memory is initialised using a $readmemh call, which loads data from a data.hex file into the memory array at simulation start. Overall, this module provides the necessary data storage and retrieval functionality for load and store instructions while maintaining correct byte addressing, alignment, and memory formatting in accordance with the RISC-V ISA.

## Multiplexers 

The original two-input multiplexer was provided in the initial packet from Peter Cheung, but a four-input multiplexer was also required for the full implementation of the processor. Since I was responsible for the initial datapath section that included the 2-input mux, I also took on the task of designing and implementing the 4-input mux needed for the extended functionality of the single-cycle processor.

The additional inputs are essential for supporting all RISC-V control flow and write-back scenarios: one mux is used to select the next program counter value (PC+4, branch target, JALR target, or a default input), while the second mux determines what data is written back to the register file (ALU result, loaded data, PC+4 for jumps, or an upper immediate). Implementing the 4-input mux ensured that the datapath could correctly support branching, jumping, immediate instructions and full write-back behaviour as required by the complete RISC-V ISA.

## Top Implementation For Single Cycle

All of my assigned modules including the ALU, Register File, the original 2-input multiplexer, and the additional 4-input multiplexers were what I incorporated directly into the top-level top.sv file. Each module was instantiated exactly as designed, with its ports connected to the datapath signals required for the full RISC-V instruction flow. While I provided the modules themselves, the final wiring and signal integration within the top-level design were carried out collaboratively by the whole of the group. In particular, Aileen took primary responsibility for connecting the modules correctly because she led the development of the testbenches and therefore had the clearest understanding of the signal behaviours required for full processor functionality. Her knowledge of the verification framework ensured that the datapath connections matched the control logic expectations and that each of my modules interacted correctly with the wider system.

# Pipeline CPU Contributions
##Pipelined CPU Diagram 
<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/6f0836fb-eda3-430a-a995-8bc63b91eda5" />
Jeshmeera and I shared the responsibility for implementing the pipeline functionality. Together, we developed the pipeline registers, hazard detection unit, and forwarding unit, then wired and integrated these components into the top.sv design. Following the implementation, we jointly carried out the testing and debugging process, with valuable support from Aileen, who ensured that the pipelined processor behaved correctly under the testbench framework.

## Pipeline Registers 
In the pipelined processor, the pipeline registers separate the five execution stages and ensure that each instruction’s data and control signals are correctly forwarded each clock cycle. Our four registers: IF/ID, ID/EX, EX/ME, and ME/WB store instruction fields, operands, immediates, ALU results, and control signals, allowing multiple instructions to execute concurrently. By holding these intermediate values between stages, the pipeline registers form the core structure that enables correct instruction flow and higher throughput compared to the single-cycle design.

### ex_me reg

The EX_ME_Reg module serves as the pipeline register between the Execute (EX) stage and the Memory (MEM) stage in the pipelined processor. Its role is to capture and store all control signals and datapath values produced in the EX stage - including the ALU result, write-back controls, memory access controls, and destination register - so they can be reliably used in the MEM stage on the following clock cycle. On reset, all outputs are cleared to prevent unintended writes. This register ensures that each stage operates on the correct set of values as instructions progress through the pipeline, maintaining proper timing, consistency, and separation between the EX and MEM stages.

### me_wr reg

The ME_WR_Reg module acts as the pipeline register between the Memory (MEM) stage and the Write-Back (WB) stage. Its purpose is to hold the memory output, ALU result, write-back control signals, and destination register number produced in the MEM stage so that the WB stage receives stable, correctly timed values on the next clock cycle. On reset, all outputs are cleared to avoid accidental writes to the register file. This register ensures that the write-back stage always operates on the correct instruction results, maintaining smooth and reliable progression through the final stage of the pipeline.

## Further Multiplexers

A further three select multiplexter was needed for the pipeline intergration - specifically for the correct implementation of the forwarding logic. 

## Top Implementation For Pipeline

To extend our original single-cycle processor into a fully pipelined RISC-V implementation, the datapath was restructured into the classical five-stage pipeline: IF, ID, EX, MEM, and WB. This required breaking apart the monolithic single-cycle design and introducing pipeline registers between each stage to preserve the correct data and control signals as instructions advanced through the pipeline. Jeshmeera and I shared this responsibility—she created half of the pipeline registers along with the hazard detection and forwarding units, while I implemented the remaining registers and adapted the single-cycle modules to operate correctly within a multi-stage environment.

Although I led the initial conversion from single-cycle to pipelined operation, both of us contributed significantly to the integration and debugging of the complete design. Aileen provided crucial support during verification, using her testbench expertise to ensure correct stage interactions and to identify issues that appeared during multi-instruction program execution. Together, this collaboration produced a fully functional pipelined CPU that preserved single-cycle behaviour while improving throughput.

# Repo and Documentation Support

Alongside my design responsibilities, I also contributed to keeping the repository and documentation clear, structured, and easy to navigate. Throughout the project I regularly reviewed our files to ensure that formatting remained consistent across modules, removing unnecessary comments and tidying older sections of code as the implementation evolved. Particularly at the end of the project i made sure the formatting of each module was consistant and easy to read. This helped maintain a professional and readable codebase, reduced clutter, and made it easier for the group to work collaboratively without confusion. My attention to maintaining clean, well-organised files supported both the development workflow and the reliability of the final design.

# Reflection 

## Challenges Faced 

Throughout the project we encountered several challenges that significantly shaped our learning experience. One of the steepest learning curves was understanding how to use Git properly, especially when managing multiple branches and resolving merge conflicts for the first time. Working as a team also required us to improve our communication and coordination, particularly when integrating work completed in parallel. Early in the project our code was inconsistent and loosely structured, which made debugging and understanding each other’s modules much more difficult. Over time we developed clearer formatting, stronger naming conventions and a more disciplined approach to organisation, all of which greatly improved the readability and reliability of our design.

## What I would do differently 

If we were to approach the project again, we would place much more emphasis on structure and planning from the very beginning. Our team would have benefited from clearer task allocation, more consistent coding practices and a shared understanding of module responsibilities before diving into implementation. We also realised too late that relying mainly on scheduled lab sessions was not sufficient for a project of this scale, especially one involving a fully pipelined CPU with caches. Another key lesson was the importance of completing and thoroughly verifying one stage before moving on to the next. We often became eager to start the pipeline while the single-cycle processor was still unfinished, which made debugging significantly harder and extended the development timeline. With better organisation, pacing and discipline in our workflow, much of this complexity could have been avoided.


















