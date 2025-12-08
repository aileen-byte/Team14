# ============================================
#   RISC-V RV32I Processor - Team14-13 Makefile
#   (Uses doit4.sh for building + running)
# ============================================

# Build and clean targets
OBJDIR = obj_dir

clean:
	@echo "=== Cleaning build files ==="
	rm -rf $(OBJDIR) *.vcd *.fst tb/tests/*.vcd

all: build

build:
	@echo "=== Building RISC-V CPU ==="
	./tb/doit4.sh build

# ================================
# Run the ASM verification tests
# ================================

asm:
	@echo "=== Running ASM tests ==="
	./tb/doit4.sh run tb/tests/1_addi_bne/program.hex
	./tb/doit4.sh run tb/tests/2_li_add/program.hex
	./tb/doit4.sh run tb/tests/3_lbu_sb/program.hex
	./tb/doit4.sh run tb/tests/4_jal_ret/program.hex
	./tb/doit4.sh run tb/tests/5_pdf/program.hex

# ================================
# Reference PDF program
# ================================
reference:
	@echo "=== Running reference pdf.asm program ==="
	./tb/doit4.sh run tb/reference/pdf.hex

# ================================
# F1 program
# ================================
f1:
	@echo "=== Running F1 starting light program ==="
	./tb/doit4.sh run tb/f1/f1.hex