    .data

PATTERNS: 
    .byte 0x00      # S0 
    .byte 0x01      # S1
    .byte 0x03      # S2 
    .byte 0x07      # S3
    .byte 0x0F      # S4 
    .byte 0x1F      # S5
    .byte 0x3F      # S6 
    .byte 0x7F      # S7
    .byte 0xFF      # S8 
    .align 2

LED_ADDR: 
    .word 0x40000000
DELAY_COUNT:
    .word 0x002FFFFF

    .text 
    .global _start 

_start: 
    la  t0, LED_ADDR 
    lw  s0, 0(t0)

    la s1, PATTERNS 

    addi s2, x0, 0

fsm_loop:
    add    t1, s1, s2         
    lbu    t2, 0(t1)          

    sw     t2, 0(s0)

    jal    ra, delay

    addi   s2, s2, 1  # moves to next state 
    li     t3, 9      # checks if weve reached the last state         
    blt    s2, t3, fsm_loop

    addi   s2, x0, 0
    j      fsm_loop

delay:
    la    t0, DELAY_COUNT
    lw    t1, 0(t0)

delay_loop:
    addi t1, t1, -1
    bne  t1, x0, delay_loop
    jr    ra




