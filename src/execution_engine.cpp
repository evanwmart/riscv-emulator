#include "execution_engine.hpp"
#include <iostream>

#include "riscv_constants.hpp"

void executeInstruction(CPUState &cpu, Memory &mem, const DecodedInstruction &inst) {
    switch (inst.opcode) {
        case OPCODE_ALUR: { // R-Type Arithmetic/Logical Instructions
            uint32_t rs1 = cpu.getReg(inst.rs1);
            uint32_t rs2 = cpu.getReg(inst.rs2);
            uint32_t result = 0;

            switch (inst.funct3) {
                case FUNCT3_ADD_SUB:
                    if (inst.funct7 == FUNCT7_ADD) {
                        result = rs1 + rs2;
                    } else if (inst.funct7 == FUNCT7_SUB) {
                        result = rs1 - rs2;
                    }
                    break;
                case FUNCT3_AND:
                    result = rs1 & rs2;
                    break;
                case FUNCT3_OR:
                    result = rs1 | rs2;
                    break;
                case FUNCT3_XOR:
                    result = rs1 ^ rs2;
                    break;
                case FUNCT3_SLL:
                    result = rs1 << (rs2 & 0x1F);
                    break;
                case FUNCT3_SRL_SRA:
                    if (inst.funct7 == FUNCT7_SRL) {
                        result = rs1 >> (rs2 & 0x1F);
                    } else if (inst.funct7 == FUNCT7_SRA) {
                        result = static_cast<int32_t>(rs1) >> (rs2 & 0x1F);
                    }
                    break;
                case FUNCT3_SLT:
                    result = (static_cast<int32_t>(rs1) < static_cast<int32_t>(rs2)) ? 1 : 0;
                    break;
                case FUNCT3_SLTU:
                    result = (rs1 < rs2) ? 1 : 0;
                    break;
                default:
                    std::cerr << "Unimplemented R-Type funct3: " << inst.funct3 << "\n";
            }

            cpu.setReg(inst.rd, result);
            cpu.setPC(cpu.getPC() + 4);
            break;
        }

        case OPCODE_ALUI: { // I-Type Arithmetic/Logical Instructions
            uint32_t rs1 = cpu.getReg(inst.rs1);
            int32_t imm = inst.imm; // Sign-extended immediate
            uint32_t result = 0;

            switch (inst.funct3) {
                case FUNCT3_ADDI:
                    result = rs1 + imm;
                    break;
                case FUNCT3_ANDI:
                    result = rs1 & imm;
                    break;
                case FUNCT3_ORI:
                    result = rs1 | imm;
                    break;
                case FUNCT3_XORI:
                    result = rs1 ^ imm;
                    break;
                case FUNCT3_SLTI:
                    result = (static_cast<int32_t>(rs1) < imm) ? 1 : 0;
                    break;
                case FUNCT3_SLTIU:
                    result = (rs1 < static_cast<uint32_t>(imm)) ? 1 : 0;
                    break;
                case FUNCT3_SLLI:
                    result = rs1 << (imm & 0x1F);
                    break;
                case FUNCT3_SRLI: // SRLI and SRAI share the same funct3
                    if (inst.funct7 == FUNCT7_SRL) {
                        result = rs1 >> (imm & 0x1F); // Logical right shift
                    } else if (inst.funct7 == FUNCT7_SRA) {
                        result = static_cast<int32_t>(rs1) >> (imm & 0x1F); // Arithmetic right shift
                    }
                    break;
                default:
                    std::cerr << "Unimplemented I-Type funct3: " << inst.funct3 << "\n";
            }

            cpu.setReg(inst.rd, result);
            cpu.setPC(cpu.getPC() + 4);
            break;
        }

        case OPCODE_LOAD: { // Load Instructions
            uint32_t rs1 = cpu.getReg(inst.rs1);
            uint32_t address = rs1 + inst.imm;
            uint32_t result = 0;

            switch (inst.funct3) {
                case FUNCT3_LB:
                    result = static_cast<int8_t>(mem.loadWord(address) & 0xFF);
                    break;
                case FUNCT3_LH:
                    result = static_cast<int16_t>(mem.loadWord(address) & 0xFFFF);
                    break;
                case FUNCT3_LW:
                    result = mem.loadWord(address);
                    break;
                case FUNCT3_LBU:
                    result = mem.loadWord(address) & 0xFF;
                    break;
                case FUNCT3_LHU:
                    result = mem.loadWord(address) & 0xFFFF;
                    break;
                default:
                    std::cerr << "Unimplemented Load funct3: " << inst.funct3 << "\n";
            }

            cpu.setReg(inst.rd, result);
            cpu.setPC(cpu.getPC() + 4);
            break;
        }

        case OPCODE_STORE: { // Store Instructions
            uint32_t rs1 = cpu.getReg(inst.rs1);
            uint32_t rs2 = cpu.getReg(inst.rs2);
            uint32_t address = rs1 + inst.imm;

            switch (inst.funct3) {
                case FUNCT3_SB:
                    mem.storeWord(address, rs2 & 0xFF);
                    break;
                case FUNCT3_SH:
                    mem.storeWord(address, rs2 & 0xFFFF);
                    break;
                case FUNCT3_SW:
                    mem.storeWord(address, rs2);
                    break;
                default:
                    std::cerr << "Unimplemented Store funct3: " << inst.funct3 << "\n";
            }

            cpu.setPC(cpu.getPC() + 4);
            break;
        }

        case OPCODE_BRANCH: { // Branch Instructions
            uint32_t rs1 = cpu.getReg(inst.rs1);
            uint32_t rs2 = cpu.getReg(inst.rs2);
            int32_t offset = inst.imm;

            switch (inst.funct3) {
                case FUNCT3_BEQ:
                    if (rs1 == rs2) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                case FUNCT3_BNE:
                    if (rs1 != rs2) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                case FUNCT3_BLT:
                    if (static_cast<int32_t>(rs1) < static_cast<int32_t>(rs2)) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                case FUNCT3_BGE:
                    if (static_cast<int32_t>(rs1) >= static_cast<int32_t>(rs2)) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                case FUNCT3_BLTU:
                    if (rs1 < rs2) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                case FUNCT3_BGEU:
                    if (rs1 >= rs2) cpu.setPC(cpu.getPC() + offset);
                    else cpu.setPC(cpu.getPC() + 4);
                    break;
                default:
                    std::cerr << "Unimplemented Branch funct3: " << inst.funct3 << "\n";
            }
            break;
        }

        default:
            std::cerr << "Unimplemented opcode: 0x" << std::hex << inst.opcode << "\n";
            break;
    }
}
