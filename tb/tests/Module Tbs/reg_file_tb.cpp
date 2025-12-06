#include <iostream>
#include <verilated.h>
#include "Vreg_file.h"

using namespace std;

// Helper for clock tick
void tick(Vreg_file* dut) {
    dut->clk = 0; dut->eval();
    dut->clk = 1; dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vreg_file* dut = new Vreg_file;

    cout << "TEST START (reg_file)" << endl;

    bool pass = true;

    // INITIAL READ (all registers = 0)

    dut->AD1 = 5;
    dut->AD2 = 10;
    dut->eval();

    cout << "INIT READ: RD1=" << dut->RD1 << " RD2=" << dut->RD2 << endl;
    if (dut->RD1 != 0 || dut->RD2 != 0) {
        cout << "FAIL: Registers not zero-initialized" << endl;
        pass = false;
    } else {
        cout << "PASS: Registers zero-initialized" << endl;
    }

    
    // WRITE TO REGISTER 5
    dut->AD3 = 5;       // write to x5
    dut->WD3 = 1234;
    dut->WE3 = 1;

    tick(dut);          // perform the write

    // Read back
    dut->AD1 = 5;
    dut->eval();

    cout << "WRITE x5: RD1=" << dut->RD1 << " expected=1234" << endl;
    if (dut->RD1 != 1234) {
        cout << "FAIL: Write or read incorrect" << endl;
        pass = false;
    } else {
        cout << "PASS: Write/read x5" << endl;
    }


    // WRITE to x0 (should NOT change)
    dut->AD3 = 0;       // attempt to write x0
    dut->WD3 = 9999;
    dut->WE3 = 1;

    tick(dut);

    // Read x0
    dut->AD1 = 0;
    dut->eval();

    cout << "WRITE x0 (forbidden): RD1=" << dut->RD1 << " expected=0" << endl;

    if (dut->RD1 != 0) {
        cout << "FAIL: x0 changed (should always be 0)" << endl;
        pass = false;
    } else {
        cout << "PASS: x0 is hardwired to 0" << endl;
    }

    // WRITE to x10 → check a0 output

    dut->AD3 = 10;      // x10
    dut->WD3 = 7777;
    dut->WE3 = 1;

    tick(dut);

    // a0 should mirror register 10
    dut->eval();

    cout << "WRITE x10: a0=" << dut->a0 << " expected=7777" << endl;

    if (dut->a0 != 7777) {
        cout << "FAIL: a0 incorrect" << endl;
        pass = false;
    } else {
        cout << "PASS: a0 output matches x10" << endl;
    }

    // Ensure writing x10 didn't break x5
    dut->AD1 = 5;      // read x5 again
    dut->eval();

    cout << "RECHECK x5: RD1=" << dut->RD1 << " expected=1234" << endl;

    if (dut->RD1 != 1234) {
        cout << "FAIL: Write to x10 corrupted x5" << endl;
        pass = false;
    } else {
        cout << "PASS: Registers isolated" << endl;
    }


    // END OF TEST
    if (pass)
        cout << "TEST END: ALL PASSED" << endl;
    else
        cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
