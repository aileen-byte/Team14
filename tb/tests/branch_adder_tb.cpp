#include <iostream> 
#include <verilated.h> 
#include <cstdlib> 
#include <ctime> 
#include <cstdint> 
#include "Vbranch_adder.h"

using namespace std; 

int total_tests = 0; 
int passed_tests = 0; 

void check(Vbranch_adder* dut, uint32_t pc, uint32_t ImmOp){
    total_tests ++; 
    dut->pc = pc; 
    dut->ImmOp = ImmOp; 
    dut->eval(); 

    uint32_t expected = pc + ImmOp; 

        if (dut->branch_pc != expected) {
        cout << "FAIL: pc=" << pc << " ImmOp=" << ImmOp << " , branch_pc=" << dut->branch_pc << " (expected " << expected << ")\n";
        } 
        else {
        cout << "PASS: pc=" << pc << " ImmOp=" << ImmOp << " , branch_pc=" << dut->branch_pc << "\n";
        passed_tests++;
        }
}

int main(int argc, char** argv){
    Verilated::commandArgs(argc,argv); 
    Vbranch_adder* dut = new Vbranch_adder; 

    cout << "TEST BEGIN" << endl; 
    check(dut,0,4); 
    check(dut,8,16); 
    check(dut,100,200); 
    check(dut,0xFFFFFFFE, 2); 
    check(dut, 0xABCD1234, 0x4); //overflow test 

    srand(time(NULL));
    

    cout << "RANDOM TESTS BEIGIN" << endl; 

    for (int i = 0; i < 20; i++) {
        uint32_t pc    = (uint32_t)rand();
        uint32_t ImmOp = (uint32_t)rand();
        check(dut, pc, ImmOp);
    }

    cout << "RANDOM TESTS END" << endl; 

    cout << "TEST END" << endl; 

    if(passed_tests == total_tests){
        cout << "ALL TESTS PASSED - BRANCH_ADDER WORKS" << endl; 
    }
    else{
        cout << "NOT ALL TEST PASSED (" << passed_tests << "/" << total_tests << ")" << endl; 
    }

    delete dut; 
    return 0; 

}
