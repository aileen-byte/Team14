#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
TEST_FOLDER="${SCRIPT_DIR}/tests"
RTL_FOLDER="${SCRIPT_DIR}/../rtl"

GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

passes=0
fails=0
skips=0

# If no test names provided, use all testbench cpp files
if [[ $# -eq 0 ]]; then
    files=(${TEST_FOLDER}/*_tb.cpp)
else
    files=("$@")
fi

rm -rf obj_dir
cd "${SCRIPT_DIR}"

for file in "${files[@]}"; do
    tb=$(basename "$file")
    module=$(basename "$file" _tb.cpp)

    # special case: "verify.cpp" → top.sv
    if [[ "$module" == "verify" ]]; then
        module="top"
    fi

    rtl="${RTL_FOLDER}/${module}.sv"

    echo "--------------------------------------"
    echo "Running testbench: ${tb}"
    echo "Module expected:   ${module}.sv"

    if [[ ! -f "$rtl" ]]; then
        echo "${YELLOW}[SKIP] Missing RTL: ${module}.sv${RESET}"
        ((skips++))
        continue
    fi

    echo "[BUILD] Verilating ${module}.sv ..."

    verilator -Wall --trace \
        -cc "$rtl" \
        --exe "$file" \
        -y "$RTL_FOLDER" \
        --prefix "Vdut" \
        -o Vdut \
        -CFLAGS "-std=c++17 -isystem /usr/include" \
        -LDFLAGS "-lgtest -lgtest_main -lpthread"

    if [[ $? -ne 0 ]]; then
        echo "${RED}[FAIL] Verilator failed for ${module}${RESET}"
        ((fails++))
        continue
    fi

    make -j -C obj_dir/ -f Vdut.mk
    if [[ $? -ne 0 ]]; then
        echo "${RED}[FAIL] Build failed for ${module}${RESET}"
        ((fails++))
        continue
    fi

    ./obj_dir/Vdut
    rc=$?

    if [[ $rc -eq 0 ]]; then
        echo "${GREEN}[PASS] ${module}${RESET}"
        ((passes++))
    else
        echo "${RED}[FAIL] ${module}${RESET}"
        ((fails++))
    fi

done

echo "--------------------------------------"
echo "Summary:"
echo "  Passed: ${GREEN}${passes}${RESET}"
echo "  Failed: ${RED}${fails}${RESET}"
echo "  Skipped: ${YELLOW}${skips}${RESET}"

if [[ $fails -eq 0 ]]; then
    echo "${GREEN}Success!${RESET}"
else
    echo "${RED}Some tests failed.${RESET}"
fi
