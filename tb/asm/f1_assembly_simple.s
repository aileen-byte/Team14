 
    .data

PATTERNS: 
    .word 0x00000000     # S0
    .word 0x00000001     # S1
    .word 0x00000003     # S2
    .word 0x00000007     # S3
    .word 0x0000000F     # S4
    .word 0x0000001F     # S5
    .word 0x0000003F     # S6
    .word 0x0000007F     # S7
    .word 0x000000FF     # S8

    .text 
    .global _start 

_start:
    la   x1, PATTERNS     # x1 is the start of the pattern table
    addi x2, x0, 0        # x2 holds current value
    addi x3, x0, 9        # x3 is max

loop:
    # compute address = base + (i*4) -> basically shift 
    add  x4, x2, x2       # x4 = 2*i
    add  x4, x4, x4       # x4 = 4*i
    add  x4, x1, x4       # x4 = base + offset

    lb   x10, 0(x4)       # load BYTE → a0 = LED output

    # updat x2 -> we've moved to the next one
    addi x2, x2, 1        

    # if i == 9 → reset
    sub  x5, x2, x3
    beq  x5, x0, reset

    jal  x0, loop         # unconditional jump

reset:
    addi x2, x0, 0
    jal  x0, loop




