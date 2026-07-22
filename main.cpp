#include <iostream>
#include <memory>
#include "Vcpu.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

double sc_time_stamp() { return 0; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vcpu>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("cpu_trace.vcd");

    top->clk = 0;
    int time = 0;

    auto tick = [&]() {
        top->clk = 0; top->eval(); tfp->dump(time++);
        top->clk = 1; top->eval(); tfp->dump(time++);
    };

    std::cout << "--- BARE METAL CPU: BRANCH PREDICTION TEST ---\n\n";

    top->reset = 1;
    tick();
    top->reset = 0;

    // Run for 10 cycles to allow for branches
    for (int cycle = 1; cycle <= 10; cycle++) {
        std::cout << "Executing Cycle " << cycle << "...\n";
        tick();
    }

    std::cout << "\nProgram Execution Complete.\n";
    tfp->close();
    return 0;
}