cmake_minimum_required(VERSION 3.15)
project(Assignment3_brackets)

set(CMAKE_CXX_STANDARD 17)

file(COPY test_data/ DESTINATION test_data/)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Create the executable for sorting
add_executable(check_brackets_array main_array.cpp BracketCheck.h BracketCheck.cpp DSStack_array.h DSStack_array.cpp DSList.h)
add_executable(check_brackets_list main_list.cpp BracketCheck.h BracketCheck.cpp DSStack_array.h DSStack_array.cpp DSList.h)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests_list test_DSList.cpp DSList.h)
add_test(NAME TestList COMMAND tests_list)
add_executable(tests_stack test_DSStack_array.cpp DSStack_array.cpp)
add_test(NAME TestStack COMMAND tests_stack)
add_executable(tests_checker test_BracketCheck.cpp BracketCheck.cpp DSStack_array.cpp DSList.h)
add_test(NAME TestCheck COMMAND tests_checker)
