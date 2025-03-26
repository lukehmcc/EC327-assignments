cmake_minimum_required(VERSION 3.10)
project(EC327_Exam1_Extra LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and configure GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

# Add all CPP files in src/ (automatic discovery)
file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")

# Create main executable
add_executable(exam_extra ${SOURCES} ${TEST_SOURCES})

# Single-command run support (for your main program)
add_custom_target(run ALL
    COMMAND ./exam_extra
    DEPENDS exam_extra
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running main program..."
)

