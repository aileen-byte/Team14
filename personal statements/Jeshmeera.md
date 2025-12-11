# Jeshmeera's personal statement 

CID: 02561534 

### Contributions
Single-cycle processor 

  - [Program Counter](#program-counter)
  
  - [F1 Testbench](#f1-testbench)

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

I also implemented the relevant code in the top-level module. Most notably, in the top-level module, we used the provided mux2 to select between the sequential address and the branch target based on PCsrc, and we (co-author Pippa) implemented this directly in the top. This was a purposeful design choice we made to simplify the design and avoid creating an unnecessary additional module.

### Testing 

I also created simple testbenches for each module to verify their basic functionality and ensure that every component behaved correctly before integration into the full processor. This was something we conciously aimed to do with most modules to minimise future sources of error. 

NOTE: ADD TESTBENCHES AND RESULTS HERE 
### Testing PC Plus4 

<img width="698" height="1024" alt="image" src="https://github.com/user-attachments/assets/6a760b63-6387-484a-87fe-81e67a8bee98" />


<img width="338" height="190" alt="image" src="https://github.com/user-attachments/assets/07238a8c-a916-4805-ba73-3154e739c284" />

### Testing PC Reg 

<img width="644" height="1441" alt="image" src="https://github.com/user-attachments/assets/93a11e7d-dfa0-43a1-802c-3f666a57379a" />


<img width="196" height="140" alt="image" src="https://github.com/user-attachments/assets/2278f068-0263-4311-a5c7-94c7963a321d" />

### Testing Branch Adder

<img width="624" height="1063" alt="image" src="https://github.com/user-attachments/assets/7e334aab-6a15-4b50-8def-f3869038542e" />


<img width="212" height="113" alt="image" src="https://github.com/user-attachments/assets/75fabba3-8b29-489e-8e63-1fcd62d81017" />


## F1 Testbench

I helped Aileen implement the assembly code for the F1 lights program [(here)](..README.md/f1) and then wrote a testbench to run and verify the assembled code. This task was especially valuable, as it helped me understand how the SystemVerilog modules interacted with the testbench, the assembly program, and the generated hex data.

## Pipeline Registers 

In the pipelined processor, the pipeline registers separate the five execution stages and ensure that each instruction’s data and control signals are correctly forwarded each clock cycle. Our four registers:  IF/ID, ID/EX, EX/ME, and ME/WB store instruction fields, operands, immediates, ALU results, and control signals, allowing multiple instructions to execute concurrently. By holding these intermediate values between stages, the pipeline registers form the core structure that enables correct instruction flow and higher throughput compared to the single-cycle design.

### Pipelined CPU diagram 

<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/db612f5d-4e9b-4287-a086-24f910e52c40" />

The structure of our pipeline registers was directly influenced by the pipelined datapath diagrams presented in Digital Design and Computer Architecture (RISC-V Edition) by Harris and Harris. This diagram strongly shaped our organisation and wiring of each register, helping us maintain proper instruction flow and accurately replicate the behaviour of a standard RISC-V pipelined processor.

Venice and I acted as the lead designers for this section. We followed this layout closely when designing our pipeline registers, ensuring that each register captured the correct data and control signals on every clock edge. The textbook diagrams made clear which signals needed to be carried between stages: such as instruction fields, immediates, ALU results, and writeback controls and how these values must remain stable for the subsequent stage while the next instruction progresses behind it.

I took on the task of designing the IF/ID and ID/EX registers while Venice completed the remaining two, a deliberate decision that allowed us to implement the pipeline quickly and efficiently and minimise errors before moving on to the Hazard Unit. 

Aileen played a crucial role in debugging and testing the pipelined design, making small but essential corrections where Venice and I had overlooked details to ensure proper functionality.

### IF/ID Register 

In our CPU, the IF/ID register captures both the fetched instruction and the incremented program counter (PC+4), ensuring that the Decode stage receives stable and consistent inputs each cycle. By latching these values on the clock edge, the register prevents changes in the Fetch stage from affecting the Decode stage mid-cycle, allowing the pipeline to operate correctly and enabling multiple instructions to be processed simultaneously. It also supports flushing during control hazards, ensuring incorrect instructions do not propagate further into the pipeline.

### ID/EX Register 

In our design, the ID/EX register stores the decoded control signals, register operands, and immediate values, ensuring that the Execute stage receives all the information it needs to perform ALU operations and evaluate branch conditions. By capturing these signals at the clock edge, it isolates the Execute stage from changes in the Decode stage, allowing instructions to progress smoothly through the pipeline. This register also carries forward branch-related signals and memory control information, making it a crucial link between instruction decoding and the core computational logic of the processor.

## Hazard Unit 

When Designing the Base implementation of the Hazard detection unit i followed the hazard handling approach outlined in the textbook, shown in the diagram [here](#pipelined-cpu-diagram). It detects when the pipeline must stall or flush to maintain correct execution, identifies load-use hazards by checking wether a load in the Execute stage writes a register needed by the Decode stage, and if som it stalls Fetch and Decode and flushes Execute. It also handles branch and jump hazards by flushing the Decode and Execute stages whenever PCSrcE indicates a control transfer. Together, these mechanisms ensure the pipelined processor never uses incorrect operands and preserves correct RISC-V program flow. 

Aileen as implementation lead, acted as a co-author in this section, making small but essential alterations to the module to ensure correct functionality. 

Through implementing the Hazard Unit, I developed a clearer understanding of how data and control hazards arise in a pipelined design, how load-use dependencies must be resolved with precise timing, and how stalls and flushes work together to preserve correct execution. 

Although this section stood out as one of the more challenging concepts I had to implement, it proved to be an essential learning experience that strengthened my understanding of hazard handling from the textbook and solidified my SystemVerilog skills.

## Forwarding Unit

When designing the base implementation of the Forwarding Unit, I followed the data-forwarding strategy outlined in the textbook, represnted by the diagram [here](#pipelined-cpu-diagram). I deliberately implemented the hazard detection and forwarding logic as separate modules to keep the design modular, easier to debug, and consistent with the structure recommended in the textbook.

The goal of this module was to resolve data hazards without stalling by forwarding results from later pipeline stages back into the Execute stage. It compares the Execute-stage source registers with the destination registers in the Memory and Writeback stages and determines whether those stages will produce a result. Using this information, it generates the ForwardAE and ForwardBE signals to select the correct ALU operands, ensuring the pipeline continues flowing even when instructions depend on recently computed values.

Aileen, as implementation lead, acted as a co-author in this section and made small but important adjustments to ensure correct forwarding behaviour across all instruction types.

Through implementing this module, I developed a deeper understanding of data dependencies in pipelines and how forwarding paths help maintain high performance without sacrificing correctness.

## Testing 

As with the single-cycle design, I created simple testbenches for the pipeline modules to verify their functionality in isolation. 

NOTE: ADD TESTBENCHES AND RESULTS HERE 

###Testing the IF/ID Reg

<img width="577" height="1206" alt="image" src="https://github.com/user-attachments/assets/d1d6b152-b56c-4ab3-801f-e667b5c35317" />


<img width="185" height="115" alt="image" src="https://github.com/user-attachments/assets/6b0c7d9e-a251-459e-bc37-9a03c6aadfa9" />


###Testing the ID/EX Reg 

<img width="241" height="1456" alt="image" src="https://github.com/user-attachments/assets/30cdf999-4ca3-41c6-bcaf-f50a7e438d18" />


<img width="225" height="118" alt="image" src="https://github.com/user-attachments/assets/4201d960-30fe-4877-939d-9fcb01dab5ac" />

### Testing the Hazard

<img width="739" height="1445" alt="image" src="https://github.com/user-attachments/assets/0bf5167e-be03-45e2-ad58-e4aaa52c421a" />


<img width="311" height="187" alt="image" src="https://github.com/user-attachments/assets/f27bc215-1a71-44fc-985c-f0023edf4e3d" />

### Testing the Forwarding Unit 

<img width="336" height="1330" alt="image" src="https://github.com/user-attachments/assets/fe0c946c-fa58-461b-b7ae-109df6c15cb9" />


<img width="234" height="145" alt="image" src="https://github.com/user-attachments/assets/3a2775bf-26a1-49f2-8ee5-0ccb01caa4a7" />


# Auxilary Tasks 

## Repo and Documentation Support

I took primary responsibility for maintaining a clear and consistent repository structure throughout the project. From the beginning, we ensured that we all wrote in our seperate branch which took some time getting used to. This organisation helped minimise confusion as our project grew and made it easier to track progress and verify individual contributions.

In addition to structuring the repository, I wrote the README file, which serves as our team statement and main documentation for the project. Venice assisted with shaping the initial structure, but I wrote its content, ensuring that it accurately reflected our testing strategy, and individual responsibilities. I also produced the memory hierarchy diagram and the finite state machine diagram, which helped illustrate key parts of our architecture in a clear and accessible way. I also made it a core responsibility to ensure that each section of the project was supported with sufficient evidence.

Throughout the development process, Venice and I shared responsibility for maintaining consistency across our codebase. We ensured that modules were named coherently, followed similar formatting conventions, and were documented in a way that made the design easy to understand and extend. This collaborative effort contributed to a more professional and readable project, reducing errors and improving our overall workflow.

# Reflection 

## Challenges Faced 

One of the first challenges I encountered was learning to use GitHub effectively, as this was my first time working with it in a collaborative project. Early on, I found it difficult to manage branches, track changes, and merge work cleanly, but as the project progressed I became much more confident. By the end, I had a far better understanding of how to maintain a tidy repository, resolve conflicts, and work synchronously with my team using proper commit practices.

Communication within the team was also a learning curve. At the beginning, we didn’t fully appreciate how critical clear communication is especially when working on GitHub because failing to coordinate properly can lead to duplicated work or accidentally overwriting code that someone else has already fixed. As the project progressed, we improved significantly in this area by discussing implementations before coding, updating each other on changes, and reviewing each other’s work. This helped us avoid unnecessary conflicts and ensured that our modules were aligned both functionally and structurally.

Another major challenge arose when I attempted to build modules before I fully understood how the underlying hardware concepts worked. For example, during the pipelining stage, I initially struggled to decide which signals needed to be carried through the pipeline registers and how the control logic interacted between stages. I realised that my partial understanding wasn’t enough, so I went back to the lecture PowerPoints and revisited the relevant sections of the textbook. Taking the time to study the diagrams and descriptions in detail gave me a much clearer mental model, and once I did that, the implementation became far more manageable.

Another significant challenge we faced was correcting the forwarding logic. Although the hazard detection unit was implemented, the ALU inputs were not properly using the ForwardAE and ForwardBE signals, which caused dependent instructions to read stale register values instead of the most recent results. As a team, we traced the issue back to inconsistencies in how forwarding was handled across modules, and Pippa implemented the necessary changes to align the design with the standard RISC-V forwarding convention: prioritising EX/MEM, then MEM/WB, and otherwise using the register file. This ensured that the ALU consistently received the correct operands, leaving only true load-use hazards to be managed by a one-cycle stall in the hazard unit.

## What I would do differently 

If I were to revisit the design, one change I would make is in the PC unit. Instead of implementing the PC+4 adder and branch adder as two separate modules, I would create a single general-purpose adder module. This would simplify the design, reduce duplicated logic, and make debugging easier, as there would be fewer modules to maintain. The top-level could then select the appropriate inputs based on the control signals, allowing the same adder to serve multiple purposes including PC increments, branch target calculation, and any future additions that require arithmetic resulting in a cleaner and more modular design.

I would also make sure to develop a solid understanding of all key modules especially the pipeline registers, hazard unit, and forwarding unit before beginning the designing stage, as having this clarity from the start would have saved a significant amount of time and prevented many of the issues I encountered early on, like deciding which signals were significant and how to wire everything correctly. 












