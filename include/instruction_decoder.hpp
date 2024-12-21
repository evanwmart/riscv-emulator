// instruction_decoder.hpp
#ifndef INSTRUCTION_DECODER_HPP
#define INSTRUCTION_DECODER_HPP

#include <cstdint>

struct DecodedInstruction {
  uint32_t opcode;
  uint32_t rd;
  uint32_t rs1;
  uint32_t rs2;
  uint32_t funct3;
  uint32_t funct7;
  int32_t imm;
};

DecodedInstruction decode(uint32_t instr);

#endif
