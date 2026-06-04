# ⚙️ C P U _ S I M U L A T I O N

> **SYSTEM_ARCHITECTURE:** 8-BIT  
> **ENVIRONMENT:** Native Windows / MSYS2 UCRT64  
> **MAINTAINER:** devshreyas.exe

---

# 📖 01. Overview

A from-scratch custom **8-bit CPU architecture** designed in **Verilog** and simulated using **C++**.

This project completely bypasses WSL and instead uses a **native Windows MSYS2 UCRT64 toolchain** for hardware simulation, compilation, waveform analysis, and future FPGA deployment.

The goal is to build and understand a complete CPU architecture from the ground up by implementing and testing each hardware component independently before integrating them into a full processor design.

---

# 🧩 02. Core Components

The CPU datapath is currently divided into modular, independently tested hardware units.

## ALU (Arithmetic Logic Unit)

An 8-bit combinational logic core capable of executing four primary operations:

- ADD (`+`)
- SUBTRACT (`-`)
- BITWISE AND (`&`)
- BITWISE OR (`|`)

### Features

- 8-bit inputs and outputs
- Opcode-controlled execution
- Fully combinational design
- Verilator-compatible simulation

---

## Register File

A compact high-speed memory block containing four 8-bit registers.

### Features

- Synchronous clock-based writes
- Instantaneous dual-port reads
- 4 × 8-bit storage cells
- Suitable for CPU datapath integration

---

## Program Counter (PC)

The heartbeat of the CPU.

An 8-bit sequential register responsible for tracking instruction addresses.

### Features

- Automatic increment on rising clock edge
- Hard reset support
- Instruction fetch address generation

---

# 🛠️ 03. Tech Stack

| Component | Technology |
|------------|------------|
| Hardware Description | Verilog (`.v`) |
| Testbench Environment | C++ (`main.cpp`) |
| Simulation Engine | Verilator 5+ |
| Waveform Analysis | GTKWave |
| Build System | GNU Make |
| Compiler | GCC (MinGW-w64) |
| Platform | MSYS2 UCRT64 |

---

# 💻 04. Environment Setup

This project requires a **native Windows MSYS2 UCRT64** environment.

## Install Dependencies

```bash
pacman -S \
mingw-w64-ucrt-x86_64-verilator \
mingw-w64-ucrt-x86_64-gcc \
mingw-w64-ucrt-x86_64-gtkwave \
mingw-w64-ucrt-x86_64-cmake \
make
```

> [!IMPORTANT]
> Ensure the **MSYS2 UCRT64 `bin` directory** is added to your Windows **Environment Variables (PATH)** so that tools such as Verilator, GCC, Make, and GTKWave can be executed directly from VS Code and the terminal.

---

# 🚀 05. Compilation & Execution

Each hardware module is tested independently using its corresponding Verilog source file and C++ testbench.

## 1️⃣ Generate the C++ Simulation Model

```bash
verilator -Wall -Wno-EOFNEWLINE --trace -cc <module_name>.v --exe main.cpp
```

Example:

```bash
verilator -Wall -Wno-EOFNEWLINE --trace -cc alu.v --exe main.cpp
```

---

## 2️⃣ Compile the Executable

```bash
make -j -C obj_dir -f V<module_name>.mk V<module_name>
```

Example:

```bash
make -j -C obj_dir -f Valu.mk Valu
```

---

## 3️⃣ Run the Simulation

```bash
./obj_dir/V<module_name>
```

Example:

```bash
./obj_dir/Valu
```

---

## 4️⃣ Visualize Waveforms

```bash
gtkwave <trace_file>.vcd
```

Example:

```bash
gtkwave alu_trace.vcd
```

---

## 5️⃣ Hardware Synthesis (Future Deployment)

Once simulation results are verified and all modules function correctly, the Verilog design can be synthesized into a physical FPGA bitstream using vendor-specific tools such as:

- Xilinx Vivado
- Intel Quartus Prime
- Lattice Radiant

The generated bitstream can then be flashed onto a compatible FPGA development board for real hardware execution.

---

# ⚠️ Important Notice

> [!WARNING]
> This project is currently under active development and experimentation. Interfaces, modules, directory structures, and build procedures may change without notice as the CPU architecture evolves.

> [!CAUTION]
> Earlier beta builds and experimental releases have been removed to prevent users from downloading outdated or unstable versions. Only the latest verified code should be used for testing and development.

> [!TIP]
> Always pull the newest version of the repository before running simulations or submitting bug reports.

---

# ❤️ Thank You

A huge thank you to everyone who has followed the project, tested early builds, reported issues, and patiently waited through the development process.

Your feedback helps improve the architecture, tooling, and documentation with every iteration.

**Thank you for your patience and support.**

---

# 🔬 Interactive 8-Bit ALU Visualizer

Before moving on to the next CPU module, you can experiment with the ALU using the interactive visualizer below.

Features:

- Adjustable Input A (0–255)
- Adjustable Input B (0–255)
- Opcode Selection:
  - ADD
  - SUB
  - AND
  - OR
- Real-time decimal output
- 8-bit binary visualization
- Bit alignment display for logic operations

```json
{
  "component": "LlmGeneratedComponent",
  "props": {
    "height": "600px",
    "prompt": "Objective: Create an interactive 8-bit ALU visualizer that demonstrates binary math operations. Data State: Initialize Input A to 15, Input B to 10. Opcodes are ADD, SUB, AND, OR. Strategy: Form Layout. Inputs: Two sliders or number inputs for A and B (restricted to 0-255 to maintain 8-bit limit). A dropdown or set of buttons for the Opcode (ADD, SUB, AND, OR). Behavior: Calculate the decimal result based on the inputs and selected opcode. Visually display the 8-bit binary representation of Input A, Input B, and the final Result, stacked vertically so the user can see how the bits align for operations like AND/OR. Ensure the binary strings are padded with zeros to strictly show 8 bits.",
    "id": "im_8168d81413ea0c2e"
  }
}
```

---

## 📜 License

This project is intended for educational, research, and hardware design experimentation purposes.

Feel free to fork, study, modify, and expand upon the architecture.

---

**Built with Verilog, simulated with Verilator, and powered by curiosity.**