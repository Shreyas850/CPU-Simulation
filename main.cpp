#include <iostream>
#include <memory>
#include "Valu.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// VERILATOR REQUIRES THIS FUNCTION WHEN TRACING IS ENABLED
double sc_time_stamp() { return 0; }

int main(int argc, char** argv) {
    // 1. Setup Verilator and tracing
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Valu>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("alu_trace.vcd");

    // 2. Set our test numbers
    uint8_t test_a = 15; // Binary: 00001111
    uint8_t test_b = 10; // Binary: 00001010

    std::cout << "--- CPU SIMULATION: ALU TEST ---\n";
    std::cout << "Input A = " << (int)test_a << "\n";
    std::cout << "Input B = " << (int)test_b << "\n\n";

    // 3. Cycle through all 4 opcodes (0 to 3)
    for (int time = 0; time < 4; time++) {
        top->a = test_a;
        top->b = test_b;
        top->op = time; // 0=ADD, 1=SUB, 2=AND, 3=OR

        // Evaluate the hardware logic
        top->eval();
        
        // Dump the data to the waveform file
        tfp->dump(time);

        // Print the result to the console
        std::cout << "Time " << time << " | Opcode: " << time 
                  << " | Output: " << (int)top->out << "\n";
    }

    // 4. Cleanup
    tfp->close();
    std::cout << "\nSimulation complete! Saved to alu_trace.vcd\n";
    return 0;
}