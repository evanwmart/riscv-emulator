add_library(emulator_core
  instruction_decoder.cpp
  cpu_state.cpp
  memory.cpp
  profiler.cpp
  # Add more source files as they are implemented
)
target_include_directories(emulator_core PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(riscv-emulator main.cpp)
target_link_libraries(riscv-emulator emulator_core)
