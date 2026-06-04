#include <iostream>
#include <memory>
#include "Vpc.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

double sc_time_stamp() { return 0; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vpc>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("pc_trace.vcd");

    top->clk = 0;
    int time = 0;

    auto tick = [&]() {
        top->clk = 0; top->eval(); tfp->dump(time++);
        top->clk = 1; top->eval(); tfp->dump(time++);
    };

    std::cout << "--- CPU SIMULATION: PROGRAM COUNTER ---\n";

    // 1. Hold reset high to start at 0
    top->reset = 1;
    tick();
    std::cout << "Tick 1 (Reset ON) : PC = " << (int)top->pc_out << "\n";

    // 2. Turn off reset, let it count up
    top->reset = 0;
    for (int i = 2; i <= 5; i++) {
        tick();
        std::cout << "Tick " << i << " (Running)   : PC = " << (int)top->pc_out << "\n";
    }

    // 3. Hit the reset button again while running
    top->reset = 1;
    tick();
    std::cout << "Tick 6 (Reset HIT): PC = " << (int)top->pc_out << "\n";

    tfp->close();
    std::cout << "\nSimulation complete! Saved to pc_trace.vcd\n";
    return 0;
}