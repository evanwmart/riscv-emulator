// profiler.hpp
#ifndef PROFILER_HPP
#define PROFILER_HPP

#include <cstdint>

#include <string>
#include <unordered_map>

class Profiler {
public:
  void incrementInstructionCount(const std::string &instrName);
  void incrementCycleCount(int cycles);
  void recordMemoryAccess(uint32_t address);
  void report() const;

private:
  std::unordered_map<std::string, int> instructionCount;
  int totalCycles = 0;
  std::unordered_map<uint32_t, int> memoryAccessFrequency;
};

#endif
