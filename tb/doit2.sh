#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Constants
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=(${TEST_FOLDER}/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

# Cleanup
rm -rf obj_dir

cd $SCRIPT_DIR

# Iterate through files
for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)
    
    # If verify.cpp -> we are testing the top module
    if [ $name == "verify.cpp" ]; then
        name="top"
    fi

    # Detect system-installed GoogleTest
    if [ -f /usr/include/gtest/gtest.h ]; then
        GTEST_INCLUDE="/usr/include"
        # Libraries might be in /usr/lib or /usr/lib/x86_64-linux-gnu
        if [ -f /usr/lib/libgtest.a ]; then
            GTEST_LIB="/usr/lib"
        elif [ -f /usr/lib/x86_64-linux-gnu/libgtest.a ]; then
            GTEST_LIB="/usr/lib/x86_64-linux-gnu"
        else
            echo "${RED}Error: GoogleTest libraries not found. Make sure you built libgtest.a and libgtest_main.a${RESET}"
            exit 1
        fi
    else
        echo "${RED}Error: GoogleTest headers not found.${RESET}"
        exit 1
    fi

    # Translate Verilog -> C++ including testbench
    verilator   -Wall --trace \
                -cc ${RTL_FOLDER}/${name}.sv \
                --exe ${TEST_FOLDER}/${name}_tb.cpp \
                -y ${RTL_FOLDER} \
                --prefix "Vdut" \
                -o Vdut \
                -CFLAGS "-std=c++17 -isystem ${GTEST_INCLUDE}" \
                -LDFLAGS "-L${GTEST_LIB} -lgtest -lgtest_main -lpthread"

    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk
    
    # Run executable simulation file
    ./obj_dir/Vdut
    
    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        ((passes++))
    else
        ((fails++))
    fi
    
done

# Exit as a pass or fail (for CI purposes)
if [ $fails -eq 0 ]; then
    echo "${GREEN}Success! All ${passes} test(s) passed!"
else
    total=$((passes + fails))
    echo "${RED}Failure! Only ${passes} test(s) passed out of ${total}."
fi