#include "execution_engine.hpp"
#include <cstdint>
#include <iostream>  // optional for debugging

void executeInstruction(CPUState &cpu, Memory &mem, const DecodedInstruction &inst) {
  switch (inst.opcode) {
    case 0x33: { // R-type (ADD, SUB, etc.)
      // Example: ADD vs. SUB depends on inst.funct7 / inst.funct3
      uint32_t rs1Val = cpu.getReg(inst.rs1);
      uint32_t rs2Val = cpu.getReg(inst.rs2);
      uint32_t rdVal  = 0;

      if (inst.funct3 == 0x0 && inst.funct7 == 0x00) {
        // ADD
        rdVal = rs1Val + rs2Val;
      } else if (inst.funct3 == 0x0 && inst.funct7 == 0x20) {
        // SUB
        rdVal = rs1Val - rs2Val;
      }
      // more R-type instructions ...

      cpu.setReg(inst.rd, rdVal);
      cpu.setPC(cpu.getPC() + 4);
    } break;

    case 0x03: { // I-type load (LB, LH, LW)
      // ...
      cpu.setPC(cpu.getPC() + 4);
    } break;

    // handle other opcodes...

    default:
      std::cerr << "Unimplemented opcode: 0x" << std::hex << inst.opcode << "\n";
      // Possibly throw an exception or set error state
      break;
  }
}
