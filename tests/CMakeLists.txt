add_executable(run_tests
  test_cpu_state.cpp
  test_memory.cpp
  test_decoder.cpp
  test_execution.cpp
)
target_link_libraries(run_tests emulator_core gtest_main)
add_test(NAME emulator_tests COMMAND run_tests)
