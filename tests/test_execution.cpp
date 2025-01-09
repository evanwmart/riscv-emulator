#include <gtest/gtest.h>
#include "cpu_state.hpp"
#include "memory.hpp"
#include "instruction_decoder.hpp"
#include "execution_engine.hpp"
#include "riscv_constants.hpp"

TEST(ExecutionEngineTests, AddInstruction) {
    CPUState cpu;
    Memory mem(1024); // 1KB memory
    DecodedInstruction inst = {OPCODE_ALUR, 0, 1, 2, FUNCT3_ADD_SUB, FUNCT7_ADD, 0};

    // Set initial register values
    cpu.setReg(1, 10); // rs1 = 10
    cpu.setReg(2, 20); // rs2 = 20

    executeInstruction(cpu, mem, inst);

    EXPECT_EQ(cpu.getReg(0), 30); // rd = rs1 + rs2 = 10 + 20
    EXPECT_EQ(cpu.getPC(), 4);    // PC incremented
}

TEST(ExecutionEngineTests, SubInstruction) {
    CPUState cpu;
    Memory mem(1024);
    DecodedInstruction inst = {OPCODE_ALUR, 0, 1, 2, FUNCT3_ADD_SUB, FUNCT7_SUB, 0};

    cpu.setReg(1, 20);
    cpu.setReg(2, 10);

    executeInstruction(cpu, mem, inst);

    EXPECT_EQ(cpu.getReg(0), 10); // rd = rs1 - rs2 = 20 - 10
    EXPECT_EQ(cpu.getPC(), 4);
}

TEST(ExecutionEngineTests, LoadAndStore) {
    CPUState cpu;
    Memory mem(1024);

    // Store 32-bit value
    DecodedInstruction storeInst = {OPCODE_STORE, 0, 1, 2, FUNCT3_SW, 0, 16}; // offset = 16
    cpu.setReg(1, 100);           // rs1 = base address
    cpu.setReg(2, 0xDEADBEEF);    // rs2 = data to store

    executeInstruction(cpu, mem, storeInst);
    EXPECT_EQ(mem.loadWord(100 + 16), 0xDEADBEEF); // Verify stored value

    // Load 32-bit value
    DecodedInstruction loadInst = {OPCODE_LOAD, 0, 1, 0, FUNCT3_LW, 0, 16}; // offset = 16
    executeInstruction(cpu, mem, loadInst);

    EXPECT_EQ(cpu.getReg(0), 0xDEADBEEF); // Verify loaded value
    EXPECT_EQ(cpu.getPC(), 8);           // PC incremented
}

TEST(ExecutionEngineTests, BranchInstruction) {
    CPUState cpu;
    Memory mem(1024);

    // Test BEQ (branch taken)
    DecodedInstruction beqInst = {OPCODE_BRANCH, 0, 1, 2, FUNCT3_BEQ, 0, 8}; // Offset = 8
    cpu.setReg(1, 42);
    cpu.setReg(2, 42); // Equal values

    executeInstruction(cpu, mem, beqInst);
    EXPECT_EQ(cpu.getPC(), 8); // Branch taken

    // Test BNE (branch not taken)
    DecodedInstruction bneInst = {OPCODE_BRANCH, 0, 1, 2, FUNCT3_BNE, 0, 8};
    cpu.setReg(1, 42);
    cpu.setReg(2, 43); // Unequal values

    executeInstruction(cpu, mem, bneInst);
    EXPECT_EQ(cpu.getPC(), 12); // PC incremented by 4 (no branch)
}
