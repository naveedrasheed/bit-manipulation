
cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_EXECUTABLE_SUFFIX_CXX ".out")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bit_manipulation)
set(COVERAGE_FLAGS --coverage)
set(WARNING_FLAGS -Wall -Wextra -Werror)
set(DEBUG_FLAGS -g3 -O0)
set(SANITIZER_FLAGS -fsanitize=address -fsanitize=undefined -fsanitize=leak
                    -fno-sanitize-recover=undefined)

# Project name and version
project(bit_manipulation_solution VERSION 1.0)

add_compile_options(${COVERAGE_FLAGS} ${WARNING_FLAGS} ${DEBUG_FLAGS} ${SANITIZER_FLAGS})
add_link_options(${COVERAGE_FLAGS} ${SANITIZER_FLAGS})

include_directories(bit_manipulation/include)

add_executable(bit_manipulation_solution
    bit_manipulation/src/bit_manipulation.cpp
    bit_manipulation/tests/test_bit_manipulation.cpp
)

set_property(TARGET bit_manipulation_solution PROPERTY CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES *.cpp *.h)

add_custom_target(astyle
    COMMAND
        astyle --options=../.astylerc ${SRC_FILES}
)
