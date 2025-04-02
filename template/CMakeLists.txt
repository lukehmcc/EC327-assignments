cmake_minimum_required(VERSION 3.10)
project(EC327_Exam1_Extra LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and configure GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

set(SOURCES
)

set(TEST_SOURCES
  tests/test.cpp
)

# Create main executable (without test files)
add_executable(main "src/main.cpp" ${SOURCES})

# Create test executable (only test files)
add_executable(tests ${SOURCES} ${TEST_SOURCES})
target_link_libraries(tests GTest::GTest GTest::Main)

# Register tests with CTest
gtest_discover_tests(tests)

# Single-command run support (for your main program)
add_custom_target(run ALL
    COMMAND ./main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running main program..."
)

# Single-command run support (for your main program)
add_custom_target(test ALL
    COMMAND ./tests
    DEPENDS tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running main program..."
)
