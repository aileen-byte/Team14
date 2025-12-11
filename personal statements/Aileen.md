# Aileens's personal statement 

CID: 02561984

### Contributions

Single-cycle processor 

  - [Instruction Implementation](#instruction-implementation)

  - [Address Processing](#address-processing)

  - [Single Cycle Top Implementation](#single-cycle-top-implementation)

  - [Testing, Cleaning and Debugging](#testing-debugging-and-cleaning) 

  - [F1 Assembly Code](#f1-assembly-code) 

Pipelined processor  

  - [Testing, Debugging and Cleaning](#testing-debugging-and-cleaning)  

Cache 

   - [Cache Implementation](#cache-implementation) 

###  Auxiliary Tasks 

  - [Repo and Documentation Support](#repo-and-documentation-support)

### Reflection  

   - [Challenges Faced](#challenges-faced)

   - [What I would do differently](#what-i-would-do-differently)




# Contributions 

Although I was initially allocated the task of writing testbenches in Lab 4, my role evolved over the progress of the project into that of an implementation lead. I took on responsibility for ensuring that the wiring and integration across modules was correct, resolving structural issuess and maintaining consistency throughout the design. I also wrote several non-obvious but essential modules that were not clearly defined at the offset, stepping in wherever addittional functionality was required to support the overall processor implementation. 

### Single Cycle CPU Diagram 

<img width="702" height="392" alt="image" src="https://github.com/user-attachments/assets/62fbb526-c526-4252-8709-36710a8e8c9f" />

Throughout the single cycle processor implementation we all made it a common goal to follow the design of the processor presneted in the textbook, as shown in the image above. This became essential when making sure we shared the same design expectations which then helped us achieve more consistent and coherent implementation accross all modules. 

## Instruction Implementation 

In Lab 4, Pippa was responsible for the control unit, which only needed to support the minimal instruction set required at that stage, specifically ADDI and BNE. I significantly expanded the control unit to handle the required RV32I instructions for the coursework [(here)](../README.md#instructions-implemented), as well as several additional instructions that were not explicitly required but greatly improved the completeness and capability of our processor.

The required upgrades included full support for R-type arithmetic instructions (e.g., ADD, SUB), essential I-type arithmetic operations (ADDI, XORI), correct handling of JAL and JALR for jump control flow, and decoding for load and store instructions necessary for the provided test programs. To support these memory operations, I introduced new control signals such as MemWriteSize and LoadSize, enabling correct handling of byte-sized and unsigned loads (LB, LBU) and corresponding stores (SB). These additions required coordinated changes to the data memory module initially implemented by Venice.

Beyond the required functionality, I also implemented extra instruction support—such as LUI for U-type immediate construction and additional branching behaviour like BEQ—to more closely align our design with the full RV32I specification and to ensure smoother program execution across a wider range of test cases.

###  Jalr Mask

When implementing the jump instructions, I created the jalr_mask module to simplify handling of JALR’s alignment requirements. RISC-V mandates that the least significant bit of a JALR target address is zero, so this module clears bit 0 while leaving the remaining bits unchanged. This ensures proper alignment of the jump target and prevents misaligned control flow in the processor.

### Load Select

I created the load_select module to handle the different behaviours required by RISC-V load instructions in a clean and modular way. Different loads, lb, lbu, and lw, return data of different sizes, so this module selects the correct byte based on the address offset (byte_num) and applies the appropriate extension: zero extension for lbu, sign-extension for lb, or returning the full word for lw. This ensures that all load instructions produce properly formatted 32-bit values for the register file and keeps the main datapath simpler and easier to manage.

## Address Processing

The original data memory module was written by Venice and the instruction memory module by Pippa, but I later modified both to properly support little-endian byte addressing. In our early single-cycle design we initially assumed simple word-aligned behaviour, which worked for basic instructions but became insufficient once byte and half-word loads and stores were introduced. I updated both memories to correctly index individual bytes and assemble them in little-endian order, enabling accurate execution of instructions such as lb, lbu, and sb and ensuring full compatibility with the RISC-V memory model.

## Single Cycle Top Implementation

Although each module’s original author handled its initial top-level integration, I later revisited the top implementation after adding the extra instructions, jalr_mask, and load_select. I incorporated these new modules and made minor adjustments throughout the top-level wiring to ensure the entire processor could correctly support the expanded instruction set.

## Testing, Debugging and Cleaning

I reviewed the entire processor implementation, added the little-endian address handling, and took responsibility for ensuring that the design passed all required tests. This involved making minor adjustments where necessary, checking each module for logical consistency, and verifying that all signal dependencies in the top-level wiring were correct. During debugging, I relied heavily on GTKWave, exposing relevant signals and tracing execution through the assembly and disassembly to confirm that the observed behaviour matched expectations. When discrepancies appeared, I traced the signals back to their source assignments and systematically worked through the logic until the issue was resolved.

## F1 assembly code 

I also wrote the assembly program required to produce the F1 lights output on Vbuddy (co-authur Jeshmeera), using the state diagram to verify that the control flow and timing behaved exactly as intended.

# Pipleined Processor 

### Pipelined Diagram 

<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/9fc8532d-b5bd-46e0-80f8-09a11a37b343" />

As mentioned earlier, we had all agreed to follow the textbook’s datapath diagrams throughout the project, ensuring that our modules remained consistent with a shared architectural design and reducing ambiguity during implementation and debugging.

## Testing, Debugging and Cleaning

I carefully reviewed the wiring and overall processor implementation, simplifying the structure where possible and removing unnecessary code segments to keep the design clean and maintainable. I frequently referred back to the textbook to ensure our architecture remained consistent with the recommended RISC-V datapath. Before running any tests, I made sure to understand exactly what outputs and behaviours were expected, which proved extremely valuable during debugging because I knew precisely what the processor should be doing at each step. 

Throughout the debugging process, I applied the same systematic approach I developed during the single-cycle implementation. Using GTKWave, I exposed key internal signals, traced execution through the assembly and disassembly, and checked that the pipeline behaved exactly as expected. When discrepancies appeared, I followed the signal flow back to its source and made targeted adjustments to restore correct behaviour across modules and top-level wiring.

# Cache 

## Cache Implementation 

<img width="1920" height="1315" alt="image" src="https://github.com/user-attachments/assets/c52eea47-1a95-4e12-8e75-649ffc8f4ae2" />

To implement the two-way set-associative cache, I began by studying the lecture material and the diagrams particularly the one shown above to fully understand how the tag, set index, valid bits, and hit logic interact in hardware. I first translated the conceptual table structure into SystemVerilog, decoding the memory address into its tag and set index fields. From there, I allocated the cache as a two-way structure, where each way stores a used bit, dirty bit, valid bit, tag, and data, mirroring the organisation in the textbook diagrams.

Once the structure was in place, I introduced the necessary registers to update cache lines on hits and misses. I then implemented the hit/miss detection logic in a combinational block, comparing the incoming tag against both ways and generating the appropriate hit signals. This same block also handled updating the used bit for the replacement policy and preparing the data output during hits. For misses, I added the logic required to generate the correct signals to the main memory—requesting a refill, writing back dirty lines, and updating the cache line with new data once the memory response arrives.

Throughout this process, I continuously referred back to the lecture diagrams to ensure the implementation followed the standard two-way set-associative design principles while adapting them to fit our RISC-V processor’s memory interface and control requirements.

### Unit tests 

I also wrote a set of targeted tests to validate the full cache behaviour checking hit and miss detection, verifying correct line replacement, and ensuring that data was properly written back to and fetched from main memory allowing me to confirm that each part of the cache operated correctly before integrating it into the full processor.

# Auxilary tasks 

## Repo and Documentation Support

As repo master, I oversaw the overall structure and organisation of the repository, ensuring consistency, readability, and clarity across all modules, documentation, and branches.

I also created testbenches designed to monitor key outputs such as a0, and produced the PDF needed for the Vbuddy system display, ensuring that our processor’s behaviour could be validated both programmatically and visually.

# Reflection 

## Challenges Faced 

One challenge I faced as the implementation lead was not communicating early enough while everyone was writing their modules. I often waited until after components were completed to review or integrate them, which made it harder to fully understand each module’s behaviour and led to extra debugging later on. Earlier communication would have helped me track design decisions in real time and made integration far smoother.

Another challenge came from our team’s overall organisation. At times we lacked a clear, linear development structure, which led to overlapping work, duplicated effort, or uncertainty about which version of a module was the most up to date. Establishing a more structured workflow early on would have helped us stay more synchronised and avoid unnecessary rewrites or conflicts.

I also struggled with the sheer number of signals involved in the pipelined processor. The volume of control and datapath signals quickly became overwhelming, especially during debugging when it wasn’t immediately obvious where a fault originated. This experience highlighted the importance of breaking down complex issues into smaller parts and tracing signals step-by-step—an approach I intend to develop further to handle large hardware designs more confidently.

## What I would do differently 

If I were to approach the project again, one of my main priorities would be to take a step back and look at the bigger picture before diving into low-level debugging. On the day I was debugging the pipeline, I became too focused on the small details, which made it harder to identify the root cause of certain issues. I’ve realised that many of these problems could have been solved more quickly by first understanding the overall behaviour of the system, rather than immediately tracing individual signals.

I would also make it a priority to take breaks when I start to feel tired. There were several moments where exhaustion led me to overthink simple problems or miss obvious mistakes. Giving myself short breaks would have helped me stay clear-headed, work more efficiently, and ultimately reduce the time spent debugging.















