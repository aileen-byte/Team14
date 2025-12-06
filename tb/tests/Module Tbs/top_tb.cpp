#include <iostream>
#include <verilated.h>
#include "Vdut.h"     

using namespace std;

// Tick function uses Vdut, not Vtop
void tick(Vdut* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vdut* dut = new Vdut;   // <-- Vdut, NOT Vtop

    cout << "TEST START (pipelined CPU)" << endl;

    bool pass = true;

    // Reset CPU
    dut->rst = 1;
    dut->eval();
    tick(dut);
    tick(dut);
    dut->rst = 0;
    dut->eval();

    cout << "RESET DONE\n";

    const int MAX_CYCLES = 200;

    for (int cycle = 0; cycle < MAX_CYCLES; cycle++) {
        tick(dut);

        cout << "Cycle " << dec << cycle
             << "  a0=0x" << hex << dut->a0 
             << endl;
    }

    // Example PASS/FAIL check
    const int EXPECTED_A0 = 0x0000002A;  // 42, change as needed
    if (dut->a0 != EXPECTED_A0) {
        cout << "FAIL: a0=0x" << hex << dut->a0
             << " expected=0x" << EXPECTED_A0 << endl;
        pass = false;
    } else {
        cout << "PASS: a0 matches expected result" << endl;
    }

    if (pass) cout << "TEST END: ALL PASSED" << endl;
    else      cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
