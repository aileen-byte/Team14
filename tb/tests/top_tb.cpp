#include <iostream>
#include <verilated.h>
#include "Vdut.h"

using namespace std;

void tick(Vdut* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vdut* dut = new Vdut;

    cout << "=== PIPELINED CPU TEST START ===" << endl;

    // Reset CPU
    dut->rst = 1;
    dut->clk = 0;
    dut->eval();      // No ticking while in reset
    dut->rst = 0;         

    cout << "Reset complete." << endl;

    const int MAX_CYCLES = 2000;
    const uint32_t EXPECTED_A0 = 0x000000FE;

    bool aborted = true;

    for (int cycle = 0; cycle < MAX_CYCLES; cycle++) {
        cout << "Cycle " << dec << cycle
             << " | PC = 0x" << hex << dut->pc_o
             << " | Instr = 0x" << dut->instr_o
             << " | a0 = 0x" << dut->a0
             << endl;

        tick(dut);

        // PASS condition — finish early
        if (dut->a0 == EXPECTED_A0) {
            aborted = false;
            break;
        }
    }

    if (aborted) {
        cout << "ABORT: Max cycles (" << MAX_CYCLES << ") reached." << endl;
        cout << "Final a0 = 0x" << hex << dut->a0 << endl;
        delete dut;
        return 1;
    }

    // PASS check
    cout << "PASS: a0 = 0x" << hex << dut->a0
         << " matches expected result" << endl;

    cout << "=== TEST COMPLETE ===" << endl;

    delete dut;
    return 0;
}
