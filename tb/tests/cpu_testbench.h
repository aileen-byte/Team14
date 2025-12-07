#pragma once

#include <utility>

#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "gtest/gtest.h"

#define MAX_SIM_CYCLES 10000

class CpuTestbench : public ::testing::Test
{
public:
    void SetUp() override
    {
        // Create new context for simulation
        context_ = new VerilatedContext;
        ticks_ = 0;
    }

    void setupTest(const std::string& name) {
        std::string progSrc = "tb/tests/" + name + "/program.hex";
        std::string progDst = "program.hex";

        std::string copyCmd = "cp " + progSrc + " " + progDst;
        int ret = system(copyCmd.c_str());
        if (ret != 0) {
            std::cerr << "ERROR: Could not copy " << progSrc << std::endl;
            exit(1);
        }

        // Only some tests need data
        std::string dataSrc = "tb/tests/" + name + "/data.hex";
        if (access(dataSrc.c_str(), F_OK) == 0) {
            system(("cp " + dataSrc + " data.hex").c_str());
        }
    }


    // CPU instantiated outside of SetUp to allow for correct
    // program to be assembled and loaded into instruction memory
    void initSimulation()
    {
        top_ = new Vtop(context_);
        tfp_ = new VerilatedVcdC;

        // Initialise trace and simulation
        Verilated::traceEverOn(true);
        top_->trace(tfp_, 99);
        tfp_->open(("test_out/" + name_ + "/waveform.vcd").c_str());

        // Initialise inputs
        top_->clk = 1;
        top_->rst = 1;
        runSimulation(10);  // Process reset
        top_->rst = 0;
    }

    // Runs the simulation for a clock cycle, evaluates the DUT, dumps waveform.
    void runSimulation(int cycles = 1)
    {
        for (int i = 0; i < cycles; i++)
        {
            for (int clk = 0; clk < 2; clk++)
            {
                top_->eval();
                tfp_->dump(2 * ticks_ + clk);
                top_->clk = !top_->clk;
            }
            ticks_++;

            if (Verilated::gotFinish())
            {
                exit(0);
            }
        }
    }

    void TearDown() override
    {
        // End trace and simulation
        top_->final();
        tfp_->close();

        // Free memory
        if (top_) delete top_;
        if (tfp_) delete tfp_;
        delete context_;

        // Save data and program memory files to test_out directory
        std::ignore = system(("mv data.hex test_out/" + name_ + "/data.hex").c_str());
        std::ignore = system(("mv program.hex test_out/" + name_ + "/program.hex").c_str());
    }

    void setData(const std::string &data_file)
    {
        // Fill data.hex with program data
        std::ignore = system(("cp " + data_file + " data.hex").c_str());
    }

protected:
    VerilatedContext* context_;
    Vtop* top_;
    VerilatedVcdC* tfp_;
    std::string name_;
    unsigned int ticks_;
};