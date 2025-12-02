#include <iostream>
#include <verilated.h> 
#include <cstdlib> 
#include <cstdint>
#include "Vpc_plus4.h"


using namespace std;

int total_tests = 0; 
int passed_tests = 0; 

void check(Vpc_plus4* dut, uint32_t pc_value){
    total_tests ++; 
    dut->pc = pc_value; 
    dut->eval(); 

    uint32_t expected = pc_value + 4; 

    if(dut->inc_pc != expected){
        cout << "FAIL: pc=" << pc_value << " inc_pc=" << dut->inc_pc << " expected=" << expected << endl; 
    }
    else{
        cout << "PASS: pc=" << pc_value << " inc_pc=" << dut->inc_pc << endl; 
        passed_tests++; 
    }
}

int main(int argc, char** argv){
    Verilated::commandArgs(argc, argv); 
    Vpc_plus4* dut = new Vpc_plus4; 

    cout << "TEST BEGIN" << endl; 
    check(dut,0); 
    check(dut,4); 
    check(dut,20); 
    check(dut,100); 
    check(dut, 0xFFFFFFFC); //overflow test 

    srand(time(NULL));

    cout << "RANDOM TESTS BEIGIN" << endl; 

    for (int i = 0; i < 20; i++) {
        uint32_t pc    = rand();
        check(dut, pc);
    }

    cout << "RANDOM TESTS END" << endl; 
    cout << "TEST END" << endl; 

    if(passed_tests == total_tests){
        cout << "ALL TESTS PASSED - PC_PLUS4 WORKS" << endl; 
    }
    else{
        cout << "NOT ALL TEST PASSED (" << passed_tests << "/" << total_tests << ")" << endl; 
    }

    delete dut; 
    return 0; 
}