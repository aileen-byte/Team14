#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp" 

int main(int argc, char **argv, char **env) {

    Verilated::commandArgs(argc, argv);
    Vdut *top = new Vdut;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("cpu.vcd");


    if (vbdOpen() != 1) return -1;  
    vbdHeader("F1 CPU Demo");


    top->clk = 0;
    top->rst = 1;

    int cycles = 0;
    while (!Verilated::gotFinish() && cycles < 20000) {

        for (int clk = 0; clk < 2; clk++) {
            top->clk = !top->clk;
            top->eval();
            tfp->dump(2 * cycles + clk);
        }

        if (cycles == 5)
            top->rst = 0;

        // VBuddy LED 
        vbdBar(top->a0 & 0xFF);

        if (vbdGetkey() == 'q')
            break;

        cycles++;
    }

    vbdClose();

    tfp->close();
    delete top;
    return 0;
}
