# Aileens's personal statement 

CID: 02561984

### Contributions

Single-cycle processor 

  - [Control Unit](#control-unit)

  - [Data Mem](#data-mem)

  - [Jalr Mask](#jalr-mask)

  - [Load Select](#load-select)

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

During Lab 4, I was incharge of implementing the testbench portion of the lab. This meant I helped connect the simplified verion of the CPU in the top and created teh initial testbench. 

## Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/62fbb526-c526-4252-8709-36710a8e8c9f" />

## Control Unit 

## Data Mem

## Jalr mask

## Load Select

## Top Implementation For Single Cycle


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

Alongside my design responsibilities, I also contributed to keeping the repository and documentation clear, structured, and easy to navigate. Throughout the project I regularly reviewed our files to ensure that formatting remained consistent across modules, removing unnecessary comments and tidying older sections of code as the implementation evolved. This helped maintain a professional and readable codebase, reduced clutter, and made it easier for the group to work collaboratively without confusion. My attention to maintaining clean, well-organised files supported both the development workflow and the reliability of the final design.

# Reflection 

## Challenges Faced 

## What I would do differently 





















