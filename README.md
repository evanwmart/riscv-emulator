# riscv-emulator

---

## To-Do List

### 🚀 Core Functionality
- [ ] Decode and execute RV32I instructions (arithmetic, logical, memory, and control instructions)
- [ ] Simulate registers, program counter (PC), and memory
- [ ] Handle and extend support for RV32I edge cases (e.g., unaligned memory access, system calls)

### 🛠 CLI Debugging Features
- [ ] Implement `run` command: Execute the program from start to end
- [ ] Implement `step` command: Execute the next instruction
- [ ] Add `breakpoint add <address>` and `breakpoint remove <address>` commands
- [ ] Add `memory read <address>` and `memory write <address> <value>` commands
- [ ] Add `register read <name>` and `register write <name> <value>` commands
- [ ] Display execution state after every command
- [ ] Implement error handling for invalid commands or addresses

### 📊 Profiling Tools
- [ ] Track cycle counts for instructions
- [ ] Record memory access patterns
- [ ] Simulate and track branch prediction statistics (hits/misses)
- [ ] Generate and display an execution flow summary after program run

### 🏗 Modular Design
- [ ] Encapsulate components into modular classes (`CPUState`, `Memory`, `Profiler`, etc.)
- [ ] Use CMake to manage build process
- [ ] Implement interfaces for adding custom instructions or ISA extensions

### 🧪 Testing and Validation
- [ ] Create unit tests for `CPUState` and `Memory` modules
- [ ] Add tests for instruction decoding
- [ ] Write integration tests for full instruction execution
- [ ] Test and validate CLI commands
- [ ] Create sample test programs (e.g., Fibonacci, matrix multiplication)
- [ ] Compare outputs with reference implementations to ensure correctness

### 📚 Documentation
- [ ] Add high-level project overview in README
- [ ] Write detailed usage instructions (CLI commands, expected inputs/outputs)
- [ ] Add a section explaining the modular design for future developers
- [ ] Document profiling output structure and how to interpret reports
- [ ] Generate Doxygen-based API documentation

### 🎯 Performance Goals
- [ ] Optimize instruction execution to achieve 10,000 instructions/second
- [ ] Minimize profiling overhead to less than 5% of runtime
- [ ] Test and optimize emulator performance on large RISC-V programs

### 🖥 Portability
- [ ] Test build and execution on Linux
- [ ] Test build and execution on macOS
- [ ] Test build and execution on Windows

### 🛡 Stability and Error Handling
- [ ] Validate memory access boundaries to avoid out-of-range issues
- [ ] Implement error handling for unsupported opcodes
- [ ] Log runtime errors and provide useful debug output

---

## Current Status

### Completed
- Basic instruction decoding and execution (RV32I)
- Memory and register file simulation
- CLI structure with basic debugging commands
- Initial profiling tools for cycle and memory tracking
- Unit testing for core components

### In Progress
- Full implementation of CLI debugging commands
- Profiling tools (branch prediction and execution flow analysis)
- Comprehensive testing and validation

### Planned
- Extensibility for custom instructions/ISA
- Enhanced documentation and user guide
- Optimization for performance goals

---
