#include "profiler.hpp"
#include <iostream>
#include <cstdint>  

void Profiler::incrementInstructionCount(const std::string &instrName) {
    instructionCount[instrName]++;
}

void Profiler::incrementCycleCount(int cycles) {
    totalCycles += cycles;
}

void Profiler::recordMemoryAccess(uint32_t address) {
    memoryAccessFrequency[address]++;
}

void Profiler::report() const {
    std::cout << "===== Profiler Report =====\n";
    std::cout << "Total Cycles: " << totalCycles << "\n";

    std::cout << "Instruction Counts:\n";
    for (auto &pair : instructionCount) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }

    std::cout << "Memory Accesses:\n";
    for (auto &pair : memoryAccessFrequency) {
        std::cout << "  0x" << std::hex << pair.first << ": "
                  << std::dec << pair.second << "\n";
    }
}
