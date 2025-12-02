#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    int i;
    int clk;

    Verilated::commandArgs(argc,argv);
    // init top verilog instance
    Vdut* top = new Vdut;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("test.vcd");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 0;

    // run simulation for many clock cycles
    for(i=0; i<10000; i++) {
    
        // dump variables into VCD file and toggle clock
        for (clk=0; clk<2; clk++) {
            top->clk = !top->clk;
            top->eval ();
            tfp->dump (2*i+clk); // unit is in ps!!!
        }

        if ((Verilated::gotFinish())) 
        break;                // ... exit if finish OR 'q' pressed
    }
    vbdClose(); // ++++
    tfp->close();
    exit(0);
}