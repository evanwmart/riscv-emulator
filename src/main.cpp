// main.cpp
#include "CLI11.hpp"
#include "cpu_state.hpp"
#include "memory.hpp"
#include "instruction_decoder.hpp"
#include "execution_engine.hpp"

int main(int argc, char** argv) {
  CLI::App app{"RISC-V Emulator"};
  std::string programPath;
  app.add_option("-l,--load", programPath, "Load a program binary")->required();

  CLI11_PARSE(app, argc, argv);

  // Initialize CPU and memory
  CPUState cpu;
  Memory mem(0x10000); // Example: 64 KB memory

  // Load binary into memory (implement load function separately)
  // loadProgram(mem, programPath);

  // Enter a command loop for debugging
  // Implement commands: run, step, breakpoint add/remove, memory read/write, register read/write

  return 0;
}
