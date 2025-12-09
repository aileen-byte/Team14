A README.md that show evidences of the CPU working properly with the program.
A short narrative to state the challenges you encountered as a team.
Comments about any design decisions you made that are not obvious.
A reflection on what you might do differently if you were to start again.

# Team 14 – RISC-V CPU Project

[Go to](#single-cycle-risc-v-processor) Single Cycle CPU

[Go to Pipelined CPU]()

[Go to Pipelined and Cache CPU]()

## Repo structure 
As a team, we each worked on our own branches while keeping main for finalized, tested CPU versions. After completing a section, we merged our branch into main and removed any no-longer-needed branches to maintain a clear, tidy repository for examination.

COMMMENT: address the github structure and where everything is located 

## Details and personal statements 
| Name                  | CID      | Email                                   | Link to personal statement |
|-----------------------|----------|-----------------------------------------|-----------------------------|
| Aileen Sangalli       | 02561984 | aileen.sangalli24@imperial.ac.uk        |                             |
| Jeshmeera Siventhiran | 02561534 | jeshmeera.siventhiran24@imperial.ac.uk  |                             |
| Phillippa Flintoff     | 02596628 | phillippa.flintoff24@imperial.ac.uk      |                             |
| Venice Gainfort-Head  | 02559434 | venice.gainfort-head24@imperial.ac.uk   |                             |

## Introduction 

Our project implements a fully functional 5-stage pipelined RISC-V RV32I processor, supporting all base user-level instructions defined in the RISC-V Unprivileged ISA. The design follows the classical pipeline structure of Fetch, Decode, Execute, Memory, and Writeback, and incorporates full hazard detection, stalling, and data forwarding to ensure correct execution of dependent instructions. We implemented the complete processor in SystemVerilog, following a modular architecture that allowed us to iteratively verify, refine, and extend each stage.

We further enhanced the design by refining the pipeline’s hazard management and forwarding paths to maintain high instruction throughput with minimal stalling. In addition, we implemented a simple Level-1 cache that interfaces with the Memory stage, reducing load/store latency and improving overall processor performance.

## Overall CPU Diagram 

<img width="1730" height="1517" alt="image" src="https://github.com/user-attachments/assets/84beb0f5-f25e-4e65-8608-31cf88b1cb7a" />

## Single Cycle RISC-V Processor 

### Task allocation 

| Modules      | Aileen | Jeshmeera | Phillippa | Venice |
|--------------|--------|-----------|----------|--------|
| ALU          |        |           |          | w      |
| Branch_adder |        | w         |          |        |
| Control Unit | w      | w         | w        |        |
| Data_mem     | w      |           |          | w      |
| Instr_mem    | c      |           | w        |        |
| JALR_mask    | w      |           |          |        |
| Load_selc    | w      |           |          |        |
| mux4         |        |           |          | w      |
| pc_plus_4    |        | w         |          |        |
| pc_reg       |        | w         |          |        |
| reg_file     | c      |           |          | w      |
| sign_extend  |        |           | w        |        |
| top          |        | w         | w        | w      |

w - main module writer 
c - contributor 

### Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/49efff98-43ca-4516-9d4f-21e770b9ed4d" />

## Standard Components 

One of the earliest parts of the project we completed was the arithmetic logic unit (ALU), which became the foundation for almost everything that followed. Our ALU supports all RV32I base instructions we needed for the reference programs, covering arithmetic, logical, shift and comparison operations. We chose not to implement FENCE, CSR or environment instructions, as these would have required a large amount of additional hardware for functionality that our single-core design would never use. Keeping the ALU focused on the core RV32I operations helped us maintain clarity while building the rest of the pipeline around it.

The register file was similarly straightforward, but it quickly became one of the most useful tools in debugging. It provides two read ports and one write port, allowing the pipeline to access operands during decode and commit results during writeback. Although the internal implementation follows the standard RISC-V design, we added the ability for Vbuddy to write to s1 and read from a0 so that the reference programs could interact with the CPU easily. This small modification saved us a lot of time when testing and observing behaviour during development.

One subtle but important aspect we had to account for was that RISC-V is little-endian. Although this seems like a small architectural detail, it shaped several parts of our design, especially in the sign-extend unit and the memory stage. Ensuring that bytes and half-words were correctly aligned and assembled in little-endian order was essential for instructions like LB, LH, SB and SH to behave correctly. We quickly learned that even a small mistake in how we handled byte ordering could lead to confusing bugs in both the register file and data memory. Dealing with these issues gave us a much stronger appreciation for how low-level details such as endianness affect the entire pipeline.

## Pipeline 

##Cache 

## Evidence of CPU Working 

## Design Overview 

## Challenges Faced 

### 1. Integrating individually correct modules into a pipelined system

Even though most modules worked in isolation (ALU, control unit, sign-extend, register file), the moment we put them together in a 5-stage pipeline, interactions between stages exposed bugs we simply couldn’t see in unit tests. Understanding how a mistake in one stage (e.g., a wrong immediate bit, a mis-latched control signal) propagated through the pipeline taught us the importance of debugging at the system level rather than module level. To solve this issue we worked together as a team to debug, as everyone knew how each of their individual components worked the best. 

### 2. Designing and validating the hazard and forwarding logic 

Data hazards ended up being more difficult than we expected. Our forwarding logic worked in isolation, but once we connected it to the full pipeline, small mistakes like comparing the wrong registers or forwarding from the wrong stage caused subtle, cycle dependent bugs. We spent a lot of time together in GTKWave stepping through instructions to see where values were going wrong. Getting the whole team on the same page about how data should move through the pipeline was what finally helped us fix the issues.

## Reflection

One of the key lessons we learned was the importance of incremental verification. Early in the project we occasionally attempted to implement multiple features at once, only to discover that doing so made debugging significantly harder. Over time, we adopted a more disciplined approach: implement one feature at a time, verify it thoroughly, and only then move on. This method dramatically improved our efficiency and confidence in the correctness of each module.

Working as a team also helped us develop complementary strengths. Some members focused more on RTL correctness, while others specialised in understanding pipeline timing or debugging waveform traces. By sharing knowledge and explaining design decisions to each other, we became more comfortable reasoning about hazards, pipeline flushing, ALU control, and instruction decoding. These collaborative discussions led to cleaner design choices and a deeper collective understanding of the microarchitecture.
