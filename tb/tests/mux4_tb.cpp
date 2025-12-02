#include <iostream>
#include <verilated.h>
#include "Vmux4.h"

using namespace std;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vmux4* dut = new Vmux4;

    cout << "TEST START (mux4)" << endl;

    bool pass = true;

    // Assign test input values
    dut->in0 = 100;
    dut->in1 = 200;
    dut->in2 = 300;
    dut->in3 = 400;

    // TEST sel = 00 → in0
    dut->sel = 0b00;
    dut->eval();

    cout << "SEL=00: out=" << dut->out << " expected=100" << endl;

    if (dut->out != 100) { cout << "FAIL: sel=00\n"; pass = false; }
    else { cout << "PASS: sel=00\n"; }


    // TEST sel = 01 → in1
    dut->sel = 0b01;
    dut->eval();

    cout << "SEL=01: out=" << dut->out << " expected=200" << endl;

    if (dut->out != 200) { cout << "FAIL: sel=01\n"; pass = false; }
    else { cout << "PASS: sel=01\n"; }

    
    // TEST sel = 10 → in2
    dut->sel = 0b10;
    dut->eval();

    cout << "SEL=10: out=" << dut->out << " expected=300" << endl;

    if (dut->out != 300) { cout << "FAIL: sel=10\n"; pass = false; }
    else { cout << "PASS: sel=10\n"; }


    // TEST sel = 11 → in3
    dut->sel = 0b11;
    dut->eval();

    cout << "SEL=11: out=" << dut->out << " expected=400" << endl;

    if (dut->out != 400) { cout << "FAIL: sel=11\n"; pass = false; }
    else { cout << "PASS: sel=11\n"; }

    
    // END OF TEST
    if (pass)
        cout << "TEST END: ALL PASSED" << endl;
    else
        cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
