cmake_minimum_required(VERSION 3.9.1)

project(TalkingClock)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(talking_clock talking_clock.cpp time.cpp time.h)