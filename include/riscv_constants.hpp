#ifndef RISCV_CONSTANTS_HPP
#define RISCV_CONSTANTS_HPP

#include <cstdint>

// Opcodes
constexpr uint32_t OPCODE_LUI     = 0b0110111;
constexpr uint32_t OPCODE_AUIPC   = 0b0010111;
constexpr uint32_t OPCODE_JAL     = 0b1101111;
constexpr uint32_t OPCODE_JALR    = 0b1100111;
constexpr uint32_t OPCODE_BRANCH  = 0b1100011;
constexpr uint32_t OPCODE_LOAD    = 0b0000011;
constexpr uint32_t OPCODE_STORE   = 0b0100011;
constexpr uint32_t OPCODE_ALUI    = 0b0010011; // Arithmetic Immediate
constexpr uint32_t OPCODE_ALUR    = 0b0110011; // Arithmetic Register
constexpr uint32_t OPCODE_MISC_MEM = 0b0001111;
constexpr uint32_t OPCODE_SYSTEM  = 0b1110011;

// Funct3 values for various instructions

// Branch instructions
constexpr uint32_t FUNCT3_BEQ  = 0b000;
constexpr uint32_t FUNCT3_BNE  = 0b001;
constexpr uint32_t FUNCT3_BLT  = 0b100;
constexpr uint32_t FUNCT3_BGE  = 0b101;
constexpr uint32_t FUNCT3_BLTU = 0b110;
constexpr uint32_t FUNCT3_BGEU = 0b111;

// Load instructions
constexpr uint32_t FUNCT3_LB  = 0b000;
constexpr uint32_t FUNCT3_LH  = 0b001;
constexpr uint32_t FUNCT3_LW  = 0b010;
constexpr uint32_t FUNCT3_LBU = 0b100;
constexpr uint32_t FUNCT3_LHU = 0b101;

// Store instructions
constexpr uint32_t FUNCT3_SB = 0b000;
constexpr uint32_t FUNCT3_SH = 0b001;
constexpr uint32_t FUNCT3_SW = 0b010;

// ALU immediate instructions
constexpr uint32_t FUNCT3_ADDI  = 0b000;
constexpr uint32_t FUNCT3_SLTI  = 0b010;
constexpr uint32_t FUNCT3_SLTIU = 0b011;
constexpr uint32_t FUNCT3_XORI  = 0b100;
constexpr uint32_t FUNCT3_ORI   = 0b110;
constexpr uint32_t FUNCT3_ANDI  = 0b111;

// Shift immediate instructions (special handling for SLLI, SRLI, SRAI)
constexpr uint32_t FUNCT3_SLLI = 0b001;
constexpr uint32_t FUNCT3_SRLI = 0b101; // SRLI/SRAI share this funct3

// ALU register-register instructions
constexpr uint32_t FUNCT3_ADD_SUB = 0b000; // ADD/SUB differ by funct7
constexpr uint32_t FUNCT3_SLL     = 0b001;
constexpr uint32_t FUNCT3_SLT     = 0b010;
constexpr uint32_t FUNCT3_SLTU    = 0b011;
constexpr uint32_t FUNCT3_XOR     = 0b100;
constexpr uint32_t FUNCT3_SRL_SRA = 0b101; // SRL/SRA differ by funct7
constexpr uint32_t FUNCT3_OR      = 0b110;
constexpr uint32_t FUNCT3_AND     = 0b111;

// Funct7 values for specific instructions
constexpr uint32_t FUNCT7_ADD  = 0b0000000;
constexpr uint32_t FUNCT7_SUB  = 0b0100000;
constexpr uint32_t FUNCT7_SRL  = 0b0000000;
constexpr uint32_t FUNCT7_SRA  = 0b0100000;
constexpr uint32_t FUNCT7_SLL  = 0b0000000;

// System instructions (e.g., ECALL, EBREAK)
constexpr uint32_t FUNCT3_SYSTEM = 0b000; // ECALL/EBREAK determined by imm[11:0]
constexpr uint32_t IMM_ECALL     = 0b000000000000;
constexpr uint32_t IMM_EBREAK    = 0b000000000001;

#endif // RISCV_CONSTANTS_HPP
