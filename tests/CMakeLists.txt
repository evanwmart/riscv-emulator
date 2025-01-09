# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Define the test executable
add_executable(run_tests
  test_cpu_state.cpp
  test_memory.cpp
  test_decoder.cpp
  test_execution.cpp
)

# Link the emulator core library and Google Test framework
target_link_libraries(run_tests emulator_core GTest::gtest GTest::gtest_main)

# Register the test suite with CTest
add_test(NAME EmulatorTests COMMAND run_tests)
