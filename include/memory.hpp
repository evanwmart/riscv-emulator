// memory.hpp
#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <cstdint>
#include <vector>

class Memory {
public:
  Memory(size_t size);

  uint32_t loadWord(uint32_t address) const;
  void storeWord(uint32_t address, uint32_t value);

  // Additional methods for halfword/byte as needed

private:
  std::vector<uint8_t> mem;
};

#endif
