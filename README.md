A README.md that show evidences of the CPU working properly with the program.
A short narrative to state the challenges you encountered as a team.
Comments about any design decisions you made that are not obvious.
A reflection on what you might do differently if you were to start again.

# Team 14 – RISC-V CPU Project

## Repo structure 

## Details and personal statements 
| Name                  | CID      | Email                                   | Link to personal statement |
|-----------------------|----------|-----------------------------------------|-----------------------------|
| Aileen Sangalli       | 02561984 | aileen.sangalli24@imperial.ac.uk        |                             |
| Jeshmeera Siventhiran | 02561534 | jeshmeera.siventhiran24@imperial.ac.uk  |                             |
| Phillipa Flintoff     | 02596628 | phillipa.flintoff24@imperial.ac.uk      |                             |
| Venice Gainfort-Head  | 02559434 | venice.gainfort-head24@imperial.ac.uk   |                             |



## overall CPU 

## testing 


## Introduction 

Our project implements a fully functional 5-stage pipelined RISC-V RV32I processor, supporting all base user-level instructions defined in the RISC-V Unprivileged ISA. The design follows the classical pipeline structure of Fetch, Decode, Execute, Memory, and Writeback, and incorporates full hazard detection, stalling, and data forwarding to ensure correct execution of dependent instructions. We implemented the complete processor in SystemVerilog, following a modular architecture that allowed us to iteratively verify, refine, and extend each stage.

A central focus of our project was achieving correct behaviour under all pipeline interactions, particularly load-use hazards, branch mispredictions, and back-to-back ALU dependencies. To handle these reliably, we built a dedicated Hazard Unit that generates stall and flush signals, as well as a Forwarding Unit that selects the correct operand sources from later pipeline stages. These components ensure that the CPU maintains high throughput while preserving architectural correctness.

To support debugging and verification, we integrated our processor with GTKWave and produced detailed cycle accurate traces for each reference program. This workflow was essential for diagnosing subtle pipeline bugs such as incorrectly forwarded values, missed flushes on taken branches, and misaligned immediate values. Through this process, we developed a deep understanding of pipeline timing behaviour and the interactions between control and data paths.

## Single cycle 
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
