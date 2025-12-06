#include <iostream>
#include <verilated.h>
#include "Vsign_extend.h"

using namespace std;

void eval_and_print(Vsign_extend* dut, const char* label) {
    dut->eval();
    cout << label << ": ImmOp=" << hex << dut->ImmOp << dec << endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vsign_extend* dut = new Vsign_extend;

    cout << "TEST START (sign_extend)" << endl;

    bool pass = true;

    // -----------------------------
    // I-TYPE TEST (addi)
    // imm[11:0] is instr[31:20]
    // Example immediate = 0xFFF (−1)
    // -----------------------------
    dut->ImmSrc = 0;  
    dut->instr = 0b1111111111110000000000000; // upper bits include imm[31:20]

    dut->eval();
    int expected_I = 0xFFFFFFFF;  // sign-extended -1

    cout << "I-TYPE:  ImmOp=" << hex << dut->ImmOp << dec << endl;

    if (dut->ImmOp != expected_I) {
        cout << "FAIL: I-TYPE sign extend" << endl;
        pass = false;
    } else {
        cout << "PASS: I-TYPE" << endl;
    }

    // -----------------------------
    // S-TYPE TEST
    // imm = {instr[31:25], instr[11:7]}
    // Example: imm = 0x00A (10)
    // -----------------------------
    dut->ImmSrc = 1;
    dut->instr =
        (0b0000000 << 25) |  // instr[31:25]
        (0b01010 << 7);      // instr[11:7]

    dut->eval();

    int expected_S = 10;

    cout << "S-TYPE: ImmOp=" << dut->ImmOp << endl;

    if (dut->ImmOp != expected_S) {
        cout << "FAIL: S-TYPE" << endl;
        pass = false;
    } else {
        cout << "PASS: S-TYPE" << endl;
    }

    // -----------------------------
    // B-TYPE TEST (branch)
    // Example immediate = 16
    // -----------------------------
    dut->ImmSrc = 2;

    // For B-type, immediate = bits:
    // imm[12] = instr[31]
    // imm[11] = instr[7]
    // imm[10:5] = instr[30:25]
    // imm[4:1] = instr[11:8]
    // imm[0] = 0

    // encode imm = 16 = 0b0000000000010000
    // imm[4:1] = 0b1000 → instr[11:8]
    // imm[10:5] = 0
    // imm[11] = 0 → instr[7]
    // imm[12] = 0 → instr[31]

    dut->instr =
        (0 << 31) |     // imm[12]
        (0 << 7)  |     // imm[11]
        (0 << 25) |     // imm[10:5]
        (0b1000 << 8);  // imm[4:1]

    dut->eval();

    int expected_B = 16;

    cout << "B-TYPE: ImmOp=" << dut->ImmOp << endl;

    if (dut->ImmOp != expected_B) {
        cout << "FAIL: B-TYPE" << endl;
        pass = false;
    } else {
        cout << "PASS: B-TYPE" << endl;
    }

    // -----------------------------
    // J-TYPE TEST (jal)
    // imm = 4096 (0x1000)
    // -----------------------------
    dut->ImmSrc = 3;

    // Construct fields for imm = 1<<20
    dut->instr =
        (0 << 31) |            // imm[20]
        (0b00010000 << 12) |   // imm[19:12]
        (0 << 20) |            // imm[11]
        (0 << 21);             // imm[10:1]


    dut->eval();

    uint32_t expected_J = 4096;

    cout << "J-TYPE: ImmOp=" << dut->ImmOp << " expected=" << expected_J << endl;

    if (dut->ImmOp != expected_J) {
        cout << "FAIL: J-TYPE" << endl;
        pass = false;
    } else {
        cout << "PASS: J-TYPE" << endl;
    }

    // -----------------------------
    // U-TYPE TEST (lui)
    // imm = instr[31:12] << 12
    // -----------------------------
    dut->ImmSrc = 4;
    dut->instr = 0xABCDE << 12;  // upper bits loaded

    dut->eval();

    cout << "U-TYPE: ImmOp=" << hex << dut->ImmOp << dec << endl;

    int expected_U = (0xABCDE << 12);

    if (dut->ImmOp != expected_U) {
        cout << "FAIL: U-TYPE" << endl;
        pass = false;
    } else {
        cout << "PASS: U-TYPE" << endl;
    }

    // -----------------------------
    // END TEST
    // -----------------------------
    if (pass)
        cout << "TEST END: ALL PASSED" << endl;
    else
        cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
