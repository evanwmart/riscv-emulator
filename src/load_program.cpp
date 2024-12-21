#include "memory.hpp"
#include <fstream>
#include <stdexcept>

bool loadProgram(Memory &mem, const std::string &filename, uint32_t loadAddr = 0) {
  std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
  if (!ifs.is_open()) {
    return false;
  }
  auto fileSize = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  if (loadAddr + fileSize >= mem.size()) {
    throw std::runtime_error("Program too large to fit in memory");
  }

  std::vector<char> buffer(fileSize);
  ifs.read(buffer.data(), fileSize);

  for (int i = 0; i < fileSize; i++) {
    mem.storeByte(loadAddr + i, static_cast<uint8_t>(buffer[i]));
  }
  return true;
}
