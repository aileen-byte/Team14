#include <iostream>
#include <verilated.h>
#include "VME_WR_Reg.h"

using namespace std;

void tick(VME_WR_Reg* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    VME_WR_Reg* dut = new VME_WR_Reg;

    cout << "TEST START (ME_WR_Reg)" << endl;

    // RESET TEST
    dut->reset = 1;

    // Apply non-zero values to ensure reset overrides them
    dut->RegWriteM = 1;
    dut->MemtoRegM = 1;
    dut->ALUOutM = 1234;
    dut->ReadDataM = 4321;
    dut->WriteRegM = 12;
    dut->ResultSrcM = 2;
    dut->ExtImmM = 111;
    dut->PCPlus4M = 222;

    tick(dut);

    bool reset_ok =
        dut->RegWriteW == 0 &&
        dut->MemtoRegW == 0 &&
        dut->ALUOutW == 0 &&
        dut->ReadDataW == 0 &&
        dut->WriteRegW == 0 &&
        dut->ResultSrcW == 0 &&
        dut->ExtImmW == 0 &&
        dut->PCPlus4W == 0;

    cout << "RESET: ALUOutW=" << dut->ALUOutW
         << " ReadDataW=" << dut->ReadDataW << endl;

    if (!reset_ok)
        cout << "FAIL: RESET did not clear outputs" << endl;
    else
        cout << "PASS: RESET clears all outputs" << endl;

    // NORMAL LATCH TEST    
    dut->reset = 0;

    dut->RegWriteM = 1;
    dut->MemtoRegM = 0;
    dut->ALUOutM = 999;
    dut->ReadDataM = 888;
    dut->WriteRegM = 5;
    dut->ResultSrcM = 1;
    dut->ExtImmM = 777;
    dut->PCPlus4M = 1000;

    tick(dut);

    bool normal_ok =
        dut->RegWriteW == 1 &&
        dut->MemtoRegW == 0 &&
        dut->ALUOutW == 999 &&
        dut->ReadDataW == 888 &&
        dut->WriteRegW == 5 &&
        dut->ResultSrcW == 1 &&
        dut->ExtImmW == 777 &&
        dut->PCPlus4W == 1000;

    cout << "NORMAL: ALUOutW=" << dut->ALUOutW
         << " ReadDataW=" << dut->ReadDataW << endl;

    if (!normal_ok)
        cout << "FAIL: NORMAL latch mismatch" << endl;
    else
        cout << "PASS: NORMAL latch" << endl;


    // SECOND SAMPLE TEST
    dut->RegWriteM = 0;
    dut->MemtoRegM = 1;
    dut->ALUOutM = 2020;
    dut->ReadDataM = 5050;
    dut->WriteRegM = 31;
    dut->ResultSrcM = 3;
    dut->ExtImmM = 4444;
    dut->PCPlus4M = 8080;

    tick(dut);

    bool sample_ok =
        dut->RegWriteW == 0 &&
        dut->MemtoRegW == 1 &&
        du->ALUOutW == 2020 &&
        dut->ReadDataW == 5050 &&
        dut->WriteRegW == 31 &&
        dut->ResultSrcW == 3 &&
        dut->ExtImmW == 4444 &&
        dut->PCPlus4W == 8080;

    cout << "SAMPLE2: ALUOutW=" << dut->ALUOutW
         << " ReadDataW=" << dut->ReadDataW << endl;

    if (!sample_ok)
        cout << "FAIL: SAMPLE2 latch mismatch" << endl;
    else
        cout << "PASS: SAMPLE2 latch" << endl;

    // -------------------------
    // END OF TEST
    // -------------------------
    cout << "TEST END (ME_WR_Reg)" << endl;

    delete dut;
    return 0;
}
