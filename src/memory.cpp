#include "memory.hpp"
#include <stdexcept>

Memory::Memory(size_t size) {
  mem.resize(size, 0);
}

uint32_t Memory::loadWord(uint32_t address) const {
  if (address + 3 >= mem.size()) {
    throw std::out_of_range("Memory load out of range");
  }
  // Combine 4 bytes into a 32-bit word (assuming little-endian)
  return (mem[address]) |
         (mem[address + 1] << 8) |
         (mem[address + 2] << 16) |
         (mem[address + 3] << 24);
}

void Memory::storeWord(uint32_t address, uint32_t value) {
  if (address + 3 >= mem.size()) {
    throw std::out_of_range("Memory store out of range");
  }
  mem[address]     = (value & 0xFF);
  mem[address + 1] = ((value >> 8) & 0xFF);
  mem[address + 2] = ((value >> 16) & 0xFF);
  mem[address + 3] = ((value >> 24) & 0xFF);
}
