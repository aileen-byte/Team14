main:
    li s0, 0x00010000
    li t1, 100
    sb t1, 0(s0)
    lbu t3, 0(s0)
    add a0, t3, zero   # a0 should be 100