// cpu_state.hpp
#ifndef CPU_STATE_HPP
#define CPU_STATE_HPP

#include <cstdint>
#include <array>

class CPUState {
public:
  CPUState();

  uint32_t getReg(unsigned index) const;
  void setReg(unsigned index, uint32_t value);

  uint32_t getPC() const;
  void setPC(uint32_t value);

private:
  std::array<uint32_t, 32> regs;
  uint32_t pc;
};

#endif
