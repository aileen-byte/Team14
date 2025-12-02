#include <iostream>
#include <verilated.h>
#include "VID_EX_Reg.h"

using namespace std;

void tick(VID_EX_Reg* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VID_EX_Reg* dut = new VID_EX_Reg;

    cout << "TEST START" << endl;

    // Reset
    dut->rst = 1;
    dut->FlushE = 0;
    dut->StallD = 0;

    tick(dut);

    if (dut->RegWriteE != 0 || dut->Rs1E != 0) {
        cout << "FAIL: RESET clear" << endl;
    } else {
        cout << "PASS: RESET clear" << endl;
    }

    // Normal update
    dut->rst = 0;
    dut->FlushE = 0;
    dut->StallD = 0;

    dut->RegWriteD = 1;
    dut->ResultSrcD = 2;
    dut->MemWriteD = 1;
    dut->JumpD = 0;
    dut->BranchD = 1;
    dut->ALUControlD = 5;
    dut->ALUSrcD = 1;

    dut->RD1D = 111;
    dut->RD2D = 222;
    dut->PCD = 1000;
    dut->Rs1D = 3;
    dut->Rs2D = 4;
    dut->RdD = 7;
    dut->ExtImmD = 55;
    dut->PCPlus4D = 1004;

    tick(dut);

    if (dut->RegWriteE == 1 && dut->Rs1E == 3 && dut->RD1E == 111) {
        cout << "PASS: NORMAL update" << endl;
    } else {
        cout << "FAIL: NORMAL update" << endl;
    }

    // Stall
    dut->StallD = 1;

    dut->RegWriteD = 0;
    dut->Rs1D = 9;      // Should NOT overwrite
    dut->RD1D = 999;    // Should NOT overwrite

    tick(dut);

    if (dut->RegWriteE == 1 && dut->Rs1E == 3 && dut->RD1E == 111) {
        cout << "PASS: STALL hold" << endl;
    } else {
        cout << "FAIL: STALL hold" << endl;
    }

    // Flush
    dut->StallD = 0;
    dut->FlushE = 1;

    tick(dut);

    if (dut->RegWriteE == 0 && dut->Rs1E == 0 && dut->RD1E == 0) {
        cout << "PASS: FLUSH clear" << endl;
    } else {
        cout << "FAIL: FLUSH clear" << endl;
    }

    cout << "TEST END" << endl;

    delete dut;
    return 0;
}

