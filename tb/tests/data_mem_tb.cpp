#include <iostream>
#include <verilated.h>
#include "Vdata_mem.h"

using namespace std;

// Clock tick helper
void tick(Vdata_mem* dut) {
    dut->clk = 0; dut->eval();
    dut->clk = 1; dut->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vdata_mem* dut = new Vdata_mem;

    cout << "TEST START (data_mem)" << endl;

    bool pass = true;

    // -----------------------------
    // INITIAL READ TEST (should be 0)
    // -----------------------------
    dut->ALUResult = 100;
    dut->WE = 0;
    dut->eval();

    cout << "INIT READ: RD=" << dut->RD << endl;

    if (dut->RD != 0) {
        cout << "FAIL: Memory is not zero-initialized" << endl;
        pass = false;
    } else {
        cout << "PASS: Default read is 0" << endl;
    }


    // WRITE TEST: write value 1234 to address 100    
    dut->ALUResult = 100;
    dut->WriteData = 1234;
    dut->WE = 1;

    tick(dut); // perform the write

    // Read back
    dut->WE = 0;
    dut->eval();

    cout << "WRITE+READ: RD=" << dut->RD << endl;

    if (dut->RD != 1234) {
        cout << "FAIL: Write or read incorrect" << endl;
        pass = false;
    } else {
        cout << "PASS: Correct write/read" << endl;
    }


    // NO-WRITE TEST: WE=0 should NOT modify memory
    dut->ALUResult = 100;
    dut->WriteData = 9999; 
    dut->WE = 0;

    tick(dut);   // should NOT write

    dut->eval();
    cout << "NO-WRITE: RD=" << dut->RD << endl;

    if (dut->RD == 9999) {
        cout << "FAIL: Memory wrote when WE=0" << endl;
        pass = false;
    } else {
        cout << "PASS: Write disabled works" << endl;
    }


    // MULTIPLE ADDRESS TEST
    // Write 2222 to address 50
    dut->ALUResult = 50;
    dut->WriteData = 2222;
    dut->WE = 1;

    tick(dut);

    // Read back
    dut->WE = 0;
    dut->eval();

    cout << "WRITE ADDR 50: RD=" << dut->RD << endl;

    if (dut->RD != 2222) {
        cout << "FAIL: Wrong value at address 50" << endl;
        pass = false;
    } else {
        cout << "PASS: Correct write at address 50" << endl;
    }


    // CHECK ADDRESS 100 STILL HOLDS OLD VALUE
    dut->ALUResult = 100;
    dut->eval();

    cout << "RECHECK ADDR 100: RD=" << dut->RD << endl;

    if (dut->RD != 1234) {
        cout << "FAIL: Write to address 50 corrupted address 100" << endl;
        pass = false;
    } else {
        cout << "PASS: Memory separation correct" << endl;
    }


    // END OF TEST
    if (pass)
        cout << "TEST END: ALL PASSED" << endl;
    else
        cout << "TEST END: SOME FAILURES" << endl;

    delete dut;
    return 0;
}
