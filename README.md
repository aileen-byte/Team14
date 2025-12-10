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
| Control Unit | w      |           | w        |        |
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
|f1_asm.s      | w      | w         |          |        |       

w - main module writer 

c - contributor 

### Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/49efff98-43ca-4516-9d4f-21e770b9ed4d" />

### Instructions Implemented 

| Type | Pseudoinstruction | RISC-V Instruction     | Description              | Operation                       |
|------|--------------------|-------------------------|--------------------------|----------------------------------|
| J    | jal label          | jal ra, label           | jump and link            | PC = LABEL, ra = PC + 4          |
| I    | jalr rs1           | jalr ra, rs1, 0         | jump and link register   | PC = rs1, ra = PC + 4            |
| I    | lbu                | lbu rd, Imm(rs1)        | load byte unsigned       | rd = ZeroExt([Address]7:0)       |
| I    | addi               | addi rd, rs1, Imm       | add immediate            | rd = rs1 + signext(Imm)          |
| S    | sb                 | sb rs2, Imm(rs1)        | store byte               | [Address]7:0 = rs2[7:0]          |
| B    | bne                | bne rs1, rs2, label     | branch if not equal      | if (rs1 ≠ rs2) PC = BTA          |
| U    | lui                | lui rd, upImm           | load upper immediate     | rd = {upImm, 12'b0}              |
| R    | add                | add rd, rs1, rs2        | add                      | rd = rs1 + rs2                   |


Extra: 

| Type | Pseudoinstruction | RISC-V Instruction     | Description         | Operation                       |
|------|--------------------|-------------------------|---------------------|----------------------------------|
| I    | ori                | ori rd, rs1, imm        | or immediate        | rd = rs1 OR signext(imm)         |
| B    | beq                | beq rs1, rs2, label     | branch if equal     | if (rs1 == rs2) PC = BTA          |

### Testing 
See below our single cpu passing all of the five tests given in verify.cpp: 

<img width="946" height="635" alt="image" src="https://github.com/user-attachments/assets/61517bb8-e4b3-4d5a-a9f8-b58a875b726a" />

#### Testing videos 
##### f1 lights  

https://github.com/user-attachments/assets/1cd3efb5-847b-40b7-86f0-a89b948396de

#### guassian.mem 

https://github.com/user-attachments/assets/57de37f1-a582-495e-95b6-ba75b1612954

#### triangle.mem 

https://github.com/user-attachments/assets/d6829022-59fc-400f-8bea-2608a3759b34

#### noisy.mem 

https://github.com/user-attachments/assets/4b7d8409-93f4-4ae9-9395-f1d673b66e5c

#### sine.mem 
We tested this using the data from lab 2. 

https://github.com/user-attachments/assets/e6092f2c-c3c5-410d-b5ad-00c11a1076be

## Pipelined RISC-V Processor

### Task allocation 

| Modules        | Aileen | Jeshmeera | Phillippa | Venice |
|----------------|--------|-----------|----------|--------|
| Control Unit   | w      |           |          |        |
| mux3           |        |           |          | w      |
| pc_source      | w      |           |          |        | 
| IF_ID_Reg      | c      | w         |          |        | 
| ID_EX_Reg      | c      | w         |          |        |
| EX_Me_Reg      | c      |           |          | w      | 
| ME_WR_Reg      | c      |           |          | w      | 
| HazardUnit     | c      | w         |          |        | 
| ForwardingUnit | c      | w         |          |        | 
| top            |        |           | w        |        |   

w - main module writer 

c - contributor 

### Pipelined CPU Diagram 

<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/c2bdd5ac-5599-413b-8615-76af48574edf" />

## Cache 

## Design Overview 

## Challenges Faced 

### 1. Integrating individually correct modules into a pipelined system

Even though most modules worked in isolation (ALU, control unit, sign-extend, register file), the moment we put them together in a 5-stage pipeline, interactions between stages exposed bugs we simply couldn’t see in unit tests. Understanding how a mistake in one stage (e.g., a wrong immediate bit, a mis-latched control signal) propagated through the pipeline taught us the importance of debugging at the system level rather than module level. To solve this issue we worked together as a team to debug, as everyone knew how each of their individual components worked the best. 

### 2. Designing and validating the hazard and forwarding logic 

Data hazards ended up being more difficult than we expected. Our forwarding logic worked in isolation, but once we connected it to the full pipeline, small mistakes like comparing the wrong registers or forwarding from the wrong stage caused subtle, cycle dependent bugs. We spent a lot of time together in GTKWave stepping through instructions to see where values were going wrong. Getting the whole team on the same page about how data should move through the pipeline was what finally helped us fix the issues.

## Reflection

One of the key lessons we learned was the importance of incremental verification. Early in the project we occasionally attempted to implement multiple features at once, only to discover that doing so made debugging significantly harder. Over time, we adopted a more disciplined approach: implement one feature at a time, verify it thoroughly, and only then move on. This method dramatically improved our efficiency and confidence in the correctness of each module.

Working as a team also helped us develop complementary strengths. Some members focused more on RTL correctness, while others specialised in understanding pipeline timing or debugging waveform traces. By sharing knowledge and explaining design decisions to each other, we became more comfortable reasoning about hazards, pipeline flushing, ALU control, and instruction decoding. These collaborative discussions led to cleaner design choices and a deeper collective understanding of the microarchitecture.
