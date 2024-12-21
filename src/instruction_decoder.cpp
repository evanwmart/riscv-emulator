#include "instruction_decoder.hpp"

static inline uint32_t getField(uint32_t instr, int start, int length) {
  return (instr >> start) & ((1 << length) - 1);
}

DecodedInstruction decode(uint32_t instr) {
  DecodedInstruction d;
  d.opcode = getField(instr, 0, 7);
  d.rd     = getField(instr, 7, 5);
  d.funct3 = getField(instr, 12, 3);
  d.rs1    = getField(instr, 15, 5);
  d.rs2    = getField(instr, 20, 5);
  d.funct7 = getField(instr, 25, 7);

  // Compute immediate for relevant instruction types (I-type, S-type, B-type, etc.)
  // This is just an example for I-type immediate:
  if (d.opcode == 0x13 /* I-type */) {
    int32_t imm12 = getField(instr, 20, 12);
    // sign-extend
    if (imm12 & 0x800) {
      imm12 |= 0xFFFFF000;
    }
    d.imm = imm12;
  }
  // Similarly handle S-type, B-type, U-type, J-type, etc.

  return d;
}
