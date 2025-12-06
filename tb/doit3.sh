#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEST_DIR="${SCRIPT_DIR}/tests"
RTL_DIR="${SCRIPT_DIR}/../rtl"

GREEN="$(tput setaf 2)"
RED="$(tput setaf 1)"
YELLOW="$(tput setaf 3)"
RESET="$(tput sgr0)"

passes=0
fails=0
skipped=0

if [[ $# -eq 0 ]]; then
    mapfile -t files < <(ls "${TEST_DIR}"/*_tb.cpp 2>/dev/null || true)
else
    files=("$@")
fi

rm -rf "${SCRIPT_DIR}/obj_dir"

for tb in "${files[@]}"; do

    tb_base="$(basename "$tb")"
    module="${tb_base%_tb.cpp}"   # strip only _tb.cpp
    rtl="${RTL_DIR}/${module}.sv"

    echo "--------------------------------------"
    echo "Running testbench: ${tb_base}"
    echo "Module expected:   $(basename "$rtl")"

    if [[ ! -f "$rtl" ]]; then
        echo "${YELLOW}[SKIP] Missing RTL: $(basename "$rtl")${RESET}"
        ((skipped++))
        continue
    fi

    echo "[BUILD] Verilating $(basename "$rtl") ..."

    if ! verilator -Wall --trace \
            -cc "$rtl" \
            --exe "$tb" \
            -y "$RTL_DIR" \
            --top-module "$module" \
            -o Vdut; then
        echo "${RED}[FAIL] Verilator failed for ${module}${RESET}"
        ((fails++))
        rm -rf "${SCRIPT_DIR}/obj_dir"
        continue
    fi

    if ! make -C "${SCRIPT_DIR}/obj_dir" -f Vdut.mk >/dev/null; then
        echo "${RED}[FAIL] Build failed for ${module}${RESET}"
        ((fails++))
        rm -rf "${SCRIPT_DIR}/obj_dir"
        continue
    fi

    if "${SCRIPT_DIR}/obj_dir/Vdut"; then
        echo "${GREEN}[PASS] ${module}${RESET}"
        ((passes++))
    else
        echo "${RED}[FAIL] Simulation failed for ${module}${RESET}"
        ((fails++))
    fi

    rm -rf "${SCRIPT_DIR}/obj_dir"

done

echo "--------------------------------------"
echo "Passed:  ${passes}"
echo "Failed:  ${fails}"
echo "Skipped: ${skipped}"

exit $((fails))
