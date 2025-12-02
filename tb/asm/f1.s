.text 
.global _start 
_start: 
    addi t1, x0, 0 # t1 holds current index 
    addi t2, x0, 9 # t2 is max
    addi t3, x0, 0  

loop:
    beq t1, x0, is_s0
    add t3, t3, t3  
    addi t3, t3, 1 
    addi a0, t3, 0  
    
    addi t1, t1, 1 
 
    bne t1, t2, loop 
    addi t1, x0, 0 
    addi t3, x0, 0
    jal ra, loop 

is_s0:
    addi a0, x0, 0
    addi t1, t1, 1
    jal ra, loop



