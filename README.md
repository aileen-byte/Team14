A README.md that show evidences of the CPU working properly with the program.
A short narrative to state the challenges you encountered as a team.
Comments about any design decisions you made that are not obvious.
A reflection on what you might do differently if you were to start again.

# Team 14 – RISC-V CPU Project

## Introduction 

Our project implements a fully functional 5-stage pipelined RISC-V RV32I processor, supporting all base user-level instructions defined in the RISC-V Unprivileged ISA. The design follows the classical pipeline structure of Fetch, Decode, Execute, Memory, and Writeback, and incorporates full hazard detection, stalling, and data forwarding to ensure correct execution of dependent instructions. We implemented the complete processor in SystemVerilog, following a modular architecture that allowed us to iteratively verify, refine, and extend each stage.

A central focus of our project was achieving correct behaviour under all pipeline interactions, particularly load-use hazards, branch mispredictions, and back-to-back ALU dependencies. To handle these reliably, we built a dedicated Hazard Unit that generates stall and flush signals, as well as a Forwarding Unit that selects the correct operand sources from later pipeline stages. These components ensure that the CPU maintains high throughput while preserving architectural correctness.

To support debugging and verification, we integrated our processor with GTKWave and produced detailed cycle accurate traces for each reference program. This workflow was essential for diagnosing subtle pipeline bugs such as incorrectly forwarded values, missed flushes on taken branches, and misaligned immediate values. Through this process, we developed a deep understanding of pipeline timing behaviour and the interactions between control and data paths.

## Evidence of CPU Working 

## Design Overview 

## Reflection

One of the key lessons we learned was the importance of incremental verification. Early in the project we occasionally attempted to implement multiple features at once, only to discover that doing so made debugging significantly harder. Over time, we adopted a more disciplined approach: implement one feature at a time, verify it thoroughly, and only then move on. This method dramatically improved our efficiency and confidence in the correctness of each module.

Working as a team also helped us develop complementary strengths. Some members focused more on RTL correctness, while others specialised in understanding pipeline timing or debugging waveform traces. By sharing knowledge and explaining design decisions to each other, we became more comfortable reasoning about hazards, pipeline flushing, ALU control, and instruction decoding. These collaborative discussions led to cleaner design choices and a deeper collective understanding of the microarchitecture.
