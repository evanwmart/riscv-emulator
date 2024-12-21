// execution_engine.hpp
#ifndef EXECUTION_ENGINE_HPP
#define EXECUTION_ENGINE_HPP

#include "cpu_state.hpp"
#include "memory.hpp"
#include "instruction_decoder.hpp"

void executeInstruction(CPUState &cpu, Memory &mem, const DecodedInstruction &inst);

#endif
