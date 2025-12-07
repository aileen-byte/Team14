#!/bin/bash
set -e

TOP=top
OBJDIR=obj_dir
CPP_DRIVER="tb/c/run_hex.cpp"

############################################################
# 1) BUILD CPU
############################################################
build_cpu() {
    echo "=============================================="
    echo " Verilating CPU"
    echo "=============================================="

    # verilator -Wall --trace --cc \
    verilator -Wall --Wno-fatal --cc \
        --Wno-UNUSEDSIGNAL \
        --Wno-CASEINCOMPLETE \
        --Wno-WIDTHTRUNC \
        --trace \
        --top-module $TOP \
        rtl/*.sv \
        --exe $CPP_DRIVER

    echo "=============================================="
    echo " Building model"
    echo "=============================================="
    make -C $OBJDIR -f V${TOP}.mk -j
}

############################################################
# 2) RUN SINGLE PROGRAM
############################################################
run_program() {
    HEXFILE="$1"

    if [ ! -f "$HEXFILE" ]; then
        echo "❌ ERROR: hex file not found: $HEXFILE"
        exit 1
    fi

    echo "=============================================="
    echo " Running: $HEXFILE"
    echo "=============================================="

    ./$OBJDIR/V${TOP} +PROGRAM="$HEXFILE"
}

############################################################
# 3) RUN ALL OFFICIAL TEST PROGRAMS
############################################################
run_tests() {
    echo "=============================================="
    echo " Running ALL coursework tests"
    echo "=============================================="

    TESTS=(
        "tb/tests/1_addi_bne/program.hex"
        "tb/tests/2_li_add/program.hex"
        "tb/tests/3_lbu_sb/program.hex"
        "tb/tests/4_jal_ret/program.hex"
        "tb/tests/5_pdf/program.hex"
    )

    for T in "${TESTS[@]}"; do
        echo "---- Testing $T ----"
        ./$OBJDIR/V${TOP} +PROGRAM="$T"
        echo ""
    done
}

############################################################
# 4) RUN F1 PROGRAM (you must assemble it to hex first)
############################################################
run_f1() {
    if [ ! -f "tb/asm/f1_assembly_simple.hex" ]; then
        echo "❌ You must assemble f1_assembly_simple.s to hex first!"
        exit 1
    fi

    run_program tb/asm/f1_assembly_simple.hex
}

############################################################
# HELP MENU
############################################################
help_msg() {
    echo "Usage:"
    echo "  ./doit.sh build                     Build CPU"
    echo "  ./doit.sh run <hexfile>             Run a specific hex file"
    echo "  ./doit.sh test                      Run all tb/tests/* programs"
    echo "  ./doit.sh f1                        Run F1 program (if hex exists)"
    echo ""
}

############################################################
# MAIN
############################################################
case "$1" in
    build)
        build_cpu
        ;;
    run)
        build_cpu
        run_program "$2"
        ;;
    test)
        build_cpu
        run_tests
        ;;
    f1)
        build_cpu
        run_f1
        ;;
    *)
        help_msg
        ;;
esac
