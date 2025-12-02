 
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
    la   t0, PATTERNS     #4 # t0 is the start of the pattern table
    addi t1, x0, 0        #8 # t1 holds current value
    addi t2, x0, 9        #12 # t2 is max

loop:
    # compute address = base + (i*4) -> basically shift 
    add  t3, t1, t1      #16 # t3 = 2*i
    add  t3, t3, t3      #20 # t3 = 4*i
    add  t3, t0, t3      #24 # t3 = base + offset

    lbu   a0, 0(t3)      #28 # load BYTE → a0 = LED output

    # update t1 -> we've moved to the next one
    addi t1, t1, 1      #32        

    # if i == 9 → reset
    bne  t1, t2, loop   #36

    addi t1, x0, 0      #40
    jal  ra, loop       #42




