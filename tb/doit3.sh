#!/bin/bash
set -e

echo "=============================================="
echo " Verilating CPU + GoogleTest verify.cpp"
echo "=============================================="

verilator -Wall --Wno-fatal --trace \
  --top-module top \
  --cc \
  rtl/top.sv \
  rtl/instr_mem.sv \
  rtl/data_mem.sv \
  rtl/pc_reg.sv \
  rtl/pc_plus4.sv \
  rtl/mux.sv \
  rtl/mux3.sv \
  rtl/mux4.sv \
  rtl/control_unit.sv \
  rtl/sign_extend.sv \
  rtl/jalr_mask.sv \
  rtl/reg_file.sv \
  rtl/ALU.sv \
  rtl/IF_ID_Reg.sv \
  rtl/ID_EX_Reg.sv \
  rtl/EX_ME_Reg.sv \
  rtl/ME_WR_Reg.sv \
  rtl/HazardUnit.sv \
  rtl/ForwardingUnit.sv \
  --exe tb/tests/verify.cpp \
  -LDFLAGS "-lgtest -lgtest_main -pthread"

echo "=============================================="
echo " Building model with make"
echo "=============================================="
make -C obj_dir -f Vtop.mk -j

echo "=============================================="
echo " Running verification"
echo "=============================================="
./obj_dir/Vtop
