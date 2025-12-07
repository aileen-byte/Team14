#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <string>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    std::string program = "program.hex";

    // Parse +PROGRAM=
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg.rfind("+PROGRAM=", 0) == 0) {
            program = arg.substr(9);
        }
    }

    std::cout << "[RUN] Loading program: " << program << "\n";

    Vtop *top = new Vtop;

    // Reset CPU
    top->rst = 1;
    for (int i = 0; i < 5; i++) {
        top->clk = 0; top->eval();
        top->clk = 1; top->eval();
    }
    top->rst = 0;

    // Run for max 50k cycles
    for (int i = 0; i < 50000; i++) {
        top->clk = 0; top->eval();
        top->clk = 1; top->eval();
    }

    std::cout << "[DONE] a0 = " << top->a0 << "\n";
    delete top;
    return 0;
}
