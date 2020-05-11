# CMakeList.txt : CMake project for CPPTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPPTest")

# Add source to this project's executable.
add_executable (CPPTest "CPPTest.cpp" "CPPTest.h")

message(STATUS "Value of TEST_CMAKE_TASK is: ${TEST_CMAKE_TASK}")

# TODO: Add tests and install targets if needed.
