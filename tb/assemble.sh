#!/bin/bash

ASM_FILE="$1"

if [ -z "$ASM_FILE" ]; then
    echo "Usage: $0 <assembly file>"
    exit 1
fi

if [ ! -f "$ASM_FILE" ]; then
    echo "ERROR: Assembly file $ASM_FILE not found!"
    exit 1
fi

echo "-----------------------------------------"
echo " Assembling program: $ASM_FILE"

# Extract test name: tb/asm/1_addi_bne.s → 1_addi_bne
TEST_NAME=$(basename "$ASM_FILE" .s)
echo " Test name detected: $TEST_NAME"
echo "-----------------------------------------"

# Correct directory!
OUTDIR="tb/tests/$TEST_NAME"

# Create directory
mkdir -p "$OUTDIR"

PROG_HEX="$OUTDIR/program.hex"

# Assemble using RISC-V GNU tools
riscv64-unknown-elf-as "$ASM_FILE" -o program.o
riscv64-unknown-elf-objcopy -O verilog program.o program.hex

# Move program.hex into test directory
mv program.hex "$PROG_HEX"

echo "Wrote: $PROG_HEX"
echo "-----------------------------------------"

rm -f program.o
