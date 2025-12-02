#include <iostream> 
#include <verilated.h> 
#include <cstdlib> 
#include <ctime> 
#include <cstdint> 
#include "Vpc_reg.h"

using namespace std;

int total_tests = 0; 
int passed_tests = 0;

void tick(Vpc_reg* dut) {
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

void check(Vpc_reg* dut, uint32_t next_pc, bool expect_reset) {
    total_tests++;

    dut->next_pc = next_pc;
    tick(dut);

    uint32_t expected = expect_reset ? 0 : next_pc;

    if (dut->pc != expected) {
        cout << "FAIL: next_pc=" << next_pc << " , pc=" << dut->pc << " (expected " << expected << ")\n";
    } 
    else {
        cout << "PASS: next_pc=" << next_pc << ", pc=" << dut->pc << "\n";
        passed_tests++;
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vpc_reg* dut = new Vpc_reg;

    cout << "TEST BEGIN" << endl; 

    dut->rst = 1;
    dut->next_pc = 123;
    tick(dut);
    check(dut, 123, true);

    dut->rst = 0;

    check(dut, 4,  false);
    check(dut, 8,  false);
    check(dut, 16, false);
    check(dut, 0x1000, false);

    srand(time(NULL)); 

    cout << "RANDOM TESTS BEGIN" << endl; 

    for (int i = 0; i < 20; i++) {
        uint32_t val = rand();
        check(dut, val, false);
    }

    cout << "RANDOM TESTS END" << endl; 
    cout << "TEST END" << endl; 

    if(passed_tests == total_tests){
        cout << "ALL TESTS PASSED - PC_REG WORKS" << endl; 
    }
    else{
        cout << "NOT ALL TEST PASSED (" << passed_tests << "/" << total_tests << ")" << endl; 
    }

    delete dut;
    return 0;
}
