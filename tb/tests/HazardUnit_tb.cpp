#include <iostream>
#include <verilated.h>
#include "VHazardUnit.h"

using namespace std;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VHazardUnit* dut = new VHazardUnit;

    cout << "TEST START" << endl;

    // LW Stall test
    dut->RsD = 5;
    dut->WriteRegE = 5;
    dut->MemtoRegE = 1;
    dut->BranchD = 0;
    dut->eval();
    cout << "LW STALL: StallF=" << dut->StallF << endl;

    // Branch stall test
    dut->RsD = 3;
    dut->WriteRegE = 3;
    dut->MemtoRegE = 0;
    dut->BranchD = 1;
    dut->RegWriteE = 1;
    dut->eval();
    cout << "BRANCH STALL: StallF=" << dut->StallF << endl;

    // No Hazard
    dut->RsD = 2;
    dut->WriteRegE = 9;
    dut->BranchD = 0;
    dut->MemtoRegE = 0;
    dut->eval();
    cout << "NO HAZARD: StallF=" << dut->StallF << endl; 

    cout << "TEST END" << endl; 

    delete dut;
    return 0;
}
