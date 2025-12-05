.text
.globl main
.equ base_pdf, 0x100
.equ base_data, 0x10000
.equ max_count, 200

main:
    LI      a1, base_data       # a1 = base address of data array
    LI      a2, 0               # a2 = offset into of data array
    LI      a3, base_pdf        # a3 = base address of pdf array
    LI      a4, max_count       # a4 = maximum count to terminate
    