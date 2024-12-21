#include "cpu_state.hpp"

CPUState::CPUState() {
  // Initialize registers and PC to 0, for example
  regs.fill(0);
  pc = 0;
}

uint32_t CPUState::getReg(unsigned index) const {
  return regs[index];
}

void CPUState::setReg(unsigned index, uint32_t value) {
  // If index == 0, remain zero if strictly RISC-V compliant
  if (index != 0) {
    regs[index] = value;
  }
}

uint32_t CPUState::getPC() const {
  return pc;
}

void CPUState::setPC(uint32_t value) {
  pc = value;
}
