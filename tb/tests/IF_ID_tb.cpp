#include <iostream> 
#include <verilated.h> 
#include "VIF_ID_Reg.h"

using namespace std;

void tick(VIF_ID_Reg* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VIF_ID_Reg* dut = new VIF_ID_Reg;

    cout << "TEST START" << endl; 

    // Reset test
    dut->rst = 1;
    dut->FlushD = 0;
    dut->StallF = 0;
    dut->PCF = 123;
    dut->PCPlus4F = 456;
    dut->InstrF = 789;
    tick(dut);
    cout << "RESET: PCD=" << dut->PCD << " InstrD=" << dut->InstrD << endl; 
    if (dut->PCD != 0 || dut->InstrD != 0) {
        cout << "FAIL: RESET clear" << endl;
    } 
    else {
        cout << "PASS: RESET clear" << endl;
    }



    // Normal latch test
    dut->rst = 0;
    dut->PCF = 10;
    dut->PCPlus4F = 14;
    dut->InstrF = 99;
    tick(dut);
    cout << "NORMAL: PCD=" << dut->PCD << " InstrD=" << dut->InstrD << endl; 
    if (dut->PCD != 10 || dut->InstrD != 99) {
        cout << "FAIL: NORMAL latch" << endl;
    } 
    else {
     cout << "PASS: NORMAL latch" << endl;
    }

    // Stall test
    dut->StallF = 1;
    dut->PCF = 50;
    dut->InstrF = 12345;
    tick(dut);
    cout << "STALL: PCD should still be 10 : " << dut->PCD << endl; 
    if (dut->PCD != 10 || dut->InstrD != 99) {
    cout << "FAIL: STALL hold" << endl;
    } 
    else {
        cout << "PASS: STALL hold" << endl;
    }

    // Flush test
    dut->StallF = 0;
    dut->FlushD = 1;
    tick(dut);
    cout << "FLUSH: PCD=" << dut->PCD << " InstrD=" << dut->InstrD << endl; 
    if (dut->PCD != 0 || dut->InstrD != 0) {
        cout << "FAIL: FLUSH clear" << endl;
    } 
    else {
        cout << "PASS: FLUSH clear" << endl;
    }

    cout << "TEST END" << endl; 

    delete dut;
    return 0;
}