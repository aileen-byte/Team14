#include <iostream>
#include <verilated.h>
#include "VEX_ME_Reg.h"

using namespace std;


//Simulates clock signals:
void tick(VEX_ME_Reg* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    VEX_ME_Reg* dut = new VEX_ME_Reg;

    cout << "TEST START" << endl;

    //reset
    dut->reset = 1;

    // Apply random values to inputs
    dut->RegWriteE = 1;
    dut->MemtoRegE = 1;
    dut->MemWriteE = 1;
    dut->ALUOutE = 1234;
    dut->WriteDataE = 5678;
    dut->WriteRegE = 15;
    dut->ResultSrcE = 2;
    dut->ExtImmE = 111;
    dut->PCPlus4E = 222;

    tick(dut);

    cout << "RESET: RegWriteM=" << dut->RegWriteM
         << " MemtoRegM=" << dut->MemtoRegM
         << " MemWriteM=" << dut->MemWriteM
         << " ALUOutM=" << dut->ALUOutM << endl;

    bool reset_ok = (dut->RegWriteM == 0 &&
                     dut->MemtoRegM == 0 &&
                     dut->MemWriteM == 0 &&
                     dut->ALUOutM == 0 &&
                     dut->WriteDataM == 0 &&
                     dut->WriteRegM == 0 &&
                     dut->ResultSrcM == 0 &&
                     dut->ExtImmM == 0 &&
                     dut->PCPlus4M == 0);

    if (!reset_ok)
        cout << "FAIL: RESET state invalid" << endl;
    else
        cout << "PASS: RESET clears all outputs" << endl;

    // NORMAL LATCH TEST
    dut->reset = 0;

    dut->RegWriteE = 1;
    dut->MemtoRegE = 0;
    dut->MemWriteE = 1;
    dut->ALUOutE = 999;
    dut->WriteDataE = 333;
    dut->WriteRegE = 7;
    dut->ResultSrcE = 1;
    dut->ExtImmE = 55;
    dut->PCPlus4E = 444;

    tick(dut);

    cout << "NORMAL: ALUOutM=" << dut->ALUOutM
         << " WriteRegM=" << dut->WriteRegM << endl;

    bool normal_ok = (dut->RegWriteM == 1 &&
                      dut->MemtoRegM == 0 &&
                      dut->MemWriteM == 1 &&
                      dut->ALUOutM == 999 &&
                      dut->WriteDataM == 333 &&
                      dut->WriteRegM == 7 &&
                      dut->ResultSrcM == 1 &&
                      dut->ExtImmM == 55 &&
                      dut->PCPlus4M == 444);

    if (!normal_ok)
        cout << "FAIL: NORMAL latch" << endl;
    else
        cout << "PASS: NORMAL latch" << endl;

    
    // SECOND SAMPLE INPUT
    
    dut->RegWriteE = 0;
    dut->MemtoRegE = 1;
    dut->MemWriteE = 0;
    dut->ALUOutE = 2020;
    dut->WriteDataE = 9090;
    dut->WriteRegE = 31;
    dut->ResultSrcE = 3;
    dut->ExtImmE = 777;
    dut->PCPlus4E = 808;

    tick(dut);

    cout << "SAMPLE2: ALUOutM=" << dut->ALUOut << " WriteDataM=" << dut->WriteDataM << endl;

    bool sample_ok = (dut->RegWriteM == 0 &&
                      dut->MemtoRegM == 1 &&
                      dut->MemWriteM == 0 &&
                      dut->ALUOutM == 2020 &&
                      dut->WriteDataM == 9090 &&
                      dut->WriteRegM == 31 &&
                      dut->ResultSrcM == 3 &&
                      dut->ExtImmM == 777 &&
                      dut->PCPlus4M == 808);

    if (!sample_ok)
        cout << "FAIL: SAMPLE2 latch" << endl;
    else
        cout << "PASS: SAMPLE2 latch" << endl;

    // -------------------------
    // DONE
    // -------------------------
    cout << "TEST END" << endl;

    delete dut;
    return 0;
}