# Aileens's personal statement 

CID: 02561984

//not sure where to put her use of writing the hex? 
// also dont know where the main initial testbench is? 
// cashe is confusing also not sure what to add in pipe thats ur job :)

### Contributions

Single-cycle processor 

  - [Control Unit](#control-unit)

  - [Jalr Mask](#jalr-mask)

  - [Load Select](#load-select)

  - [Top Implementation](#top-implementation-for-single-cycle)

Pipelined processor 

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

The original control unit fof lab 4 was designed by Pippa and was designed only to recognise addi and bne, providing minimal control signals suitable for the early single-cycle prototype. In the upgraded single-cycle implementation, I upgraded the control unit significantly and extended it to handle a much wider subset of the RISC-V RV32I instruction set, with additional control signals introduced to support memory sizes, jump behaviour, and write-back selection.

The enhanced control unit now correctly decodes R-type instructions, enabling arithmetic and logical operations such as add, sub, and xor, using both register operands. It also adds full support for I-type arithmetic (e.g., addi, xori) and immediate-based addressing required for loads and jalr.

Memory access behaviour has been expanded as well: the control logic now distinguishes between byte, half-word, and word stores using the MemWriteSize signal, and supports byte loads through the LoadSize signal and the load-select unit. This feature was fully supported by also changing the data memory initially written by Venice. This allows correct execution of instructions such as lb, lbu, and sb.

Branching capability has also been upgraded beyond the original bne. The improved unit now generates correct control signals for both BEQ and BNE, using the ALU’s Zero flag to determine when a branch is taken. Additionally, full jump support has been added through JAL and JALR, where the control unit selects PC+4 as the return address and sets the PC source accordingly.

Finally, U-type instructions such as LUI are now decoded through the UpperImmediate path, enabling immediate construction of 32-bit constants.

Overall, the extended control unit transforms the basic prototype into a much more complete RISC-V single-cycle processor capable of handling arithmetic, memory operations, branching, and immediate-based addressing across a broad set of instructions. // specifically mention which were the requirement and which were extra 

## Jalr mask

The jalr_mask module ensures correct alignment of the jump target address for the jalr instruction. RISC-V requires the least significant bit of a JALR target to be zero, so this module clears bit 0 of the computed address while leaving the remaining bits unchanged. This guarantees proper alignment and prevents misaligned control flow.

## Load Select

The load_selec module determines how data is returned from memory for different load instructions. Based on the address offset (byte_num), it selects the correct byte from the word read from memory. Using the size signal, it then performs the appropriate extension: zero-extension for lbu, sign-extension for lb, or returns the full word for lw. This ensures that load instructions of different sizes produce correctly formatted 32-bit values for the register file.

## Top Implementation For Single Cycle

As the person responsible for connecting the design in the top module and creating the testbenches, my role was to integrate all components of the single-cycle processor so that they operate as in the reference diagram. The top module brings together the PC logic, Instruction Memory, Control Unit, Register File, ALU, Immediate Generator, Data Memory, and the multiplexers that link each stage.

While integrating these modules, I ensured that all signals aligned with testbench requirements. This included adding named register outputs such as x0 and t registers to allow my automated tests to verify program correctness. The top module therefore acts as the complete implementation of the datapath shown in the reference diagram and enables full functional testing of the processor.

# Pipeline CPU Contributions

<img width="1087" height="739" alt="image" src="https://github.com/user-attachments/assets/6f0836fb-eda3-430a-a995-8bc63b91eda5" />
Jeshmeera and Venice were incharge of the initial pipeline build and I came in to assist later during the wiring and testing stage to ensure all the modules had been implemented correctly especially within the top module. 

## Top Implementation For Pipeline


# Repo and Documentation Support

As the repository manager, I oversaw the organisation, version control and overall consistency of the project throughout development. I was responsible for ensuring that all work was carried out in the correct branches, that merges were made cleanly and that the repository remained structured, readable and easy for the team to navigate. This included reviewing commit histories, resolving merge conflicts and maintaining a clear workflow so that each stage of the processor could be developed and tested without disruption.

I also took charge of the full testing pipeline. This involved writing and running the testbenches, interpreting results and identifying issues that needed to be addressed in the datapath or control logic. As part of this role, I reviewed the final versions of every module and stage, ensuring that they adhered to the RISC-V specification and behaved correctly under all the scenarios defined in Peter Cheung’s test suite. Many of the final refinements to the top-level design and control logic were made as a result of these tests, ensuring that edge cases, load and store behaviour, branching and jump instructions, and pipeline hazards were all handled correctly.

# Reflection 

## Challenges Faced 

## What I would do differently 





















