﻿# CMakeList.txt : CMake project for CPPTest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CPPTest")

# Add source to this project's executable.
add_executable(app CPPTest.cpp)

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

if (CMAKE_SHELL)
    if (WIN32) 
        if (TEST_WIN_VARIABLE STREQUAL "Windows_NT")
            message(STATUS "Windows variables test passed")
        else()
            message( FATAL_ERROR "Windows variable is not parsed" )
        endif()
    else()
        string(LENGTH "${TEST_VARIABLE}" VALUE_LEN)
        if ((VALUE_LEN GREATER 0) AND (NOT TEST_VARIABLE STREQUAL "$USER"))
            message(STATUS "Unix variables test passed")
        else()
            message( FATAL_ERROR "Unix variable is not parsed" )
        endif()
    endif()
endif()