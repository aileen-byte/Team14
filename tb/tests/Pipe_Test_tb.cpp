#include <iostream>
#include <verilated.h>
#include "Vtop.h"

using namespace std;

void tick(Vtop* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop* dut = new Vtop;

    cout << "TEST START (pipelined CPU)" << endl;

    bool pass = true;

    // -----------------------------
    // Reset the CPU
    // -----------------------------
    dut->rst = 1;
    dut->eval();
    tick(dut);
    tick(dut);

    dut->rst = 0;
    dut->eval();

    cout << "RESET DONE\n";

    // -----------------------------
    // Run CPU for a number of cycles
    // ----------------------------
    const int MAX_CYCLES = 200;

    for (int cycle = 0; cycle < MAX_CYCLES; cycle++) {

        tick(dut);   // perform clock tick

        // Print execution trace
        cout << "Cycle " << cycle
             << " | PC=" << hex << dut->pc
             << " Instr=" << dut->instr
             << " a0=" << dut->a0
             << endl;

        // Optional: Terminate early if program finishes (e.g., a0 == some value)
        // if (dut->a0 == EXPECTED_VALUE) break;
    }

    // ----------------------------
    // Simple PASS / FAIL condition
    // User should choose expected result based on program.hex
    // ----------------------------
    const int EXPECTED_A0 = 0x0000002A;   // example: a0 should become 42

    if (dut->a0 != EXPECTED_A0) {
        cout << "FAIL: a0=" << hex << dut->a0
             << " expected=" << EXPECTED_A0 << endl;
        pass = false;
    } else {
        cout << "PASS: a0 matches expected result" << endl;
    }

    // End of test
    if (pass)
        cout << "TEST END: ALL PASSED" << endl;
    else
        cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
