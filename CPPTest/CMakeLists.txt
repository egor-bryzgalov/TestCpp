# CMakeList.txt : CMake project for CPPTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPPTest")

# Add source to this project's executable.
add_executable (CPPTest "CPPTest.cpp" "CPPTest.h")

message(STATUS "Value of CMAKE_SHELL is: ${CMAKE_SHELL}")
message(STATUS "Value of TEST_ONE is: ${TEST_ONE}")
message(STATUS "Value of TEST_TWO is: ${TEST_TWO}")
message(STATUS "Value of TEST_VARIABLE is: ${TEST_VARIABLE}")
message(STATUS "Value of TEST_WIN_VARIABLE is: ${TEST_WIN_VARIABLE}")

if (NOT TEST_ONE STREQUAL "one;two")
    message( FATAL_ERROR "Test one failed" )
endif()

if (NOT TEST_TWO STREQUAL "/one/two/three")
    message( FATAL_ERROR "Test two failed" )
endif()

if (WIN32) 
    if (CMAKE_SHELL AND (TEST_WIN_VARIABLE STREQUAL "Windows_NT"))
        message(STATUS "Windows variables test passed")
    else()
        message( FATAL_ERROR "Windows variable is not parsed" )
    endif()
else()
    if (CMAKE_SHELL AND (TEST_VARIABLE STREQUAL "value"))
        message(STATUS "Unix variables test passed")
    else()
        message( FATAL_ERROR "Unix variable is not parsed" )
    endif()
endif()
