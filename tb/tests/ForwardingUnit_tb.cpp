#include <iostream>
#include <verilated.h>
#include "VForwardingUnit.h"

using namespace std;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VForwardingUnit* dut = new VForwardingUnit;

    cout << "TEST START" << endl; 

    // M-Stage forwarding
    dut->RsE = 5;
    dut->WriteRegM = 5;
    dut->RegWriteM = 1;
    dut->RegWriteW = 0;
    dut->eval();
    cout << "FORWARD AE=M  : " << (int)dut->ForwardAE << endl;

    // W-Stage forwarding
    dut->RsE = 7;
    dut->WriteRegW = 7;
    dut->RegWriteW = 1;
    dut->RegWriteM = 0;
    dut->eval();
    cout << "FORWARD AE=W : " << (int)dut->ForwardAE << endl;

    // No forward
    dut->RsE = 4;
    dut->WriteRegM = 9;
    dut->RegWriteM = 1;
    dut->eval();
    cout << "FORWARD AE=0 : " << (int)dut->ForwardAE << endl;

    cout << "TEST END" << endl; 

    delete dut;
    return 0;
}
