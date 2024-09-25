cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories({PROJECT_SOURCE_DIR}/Lab_1)
include_directories({PROJECT_SOURCE_DIR}/Lab_2)

add_executable(untitled main.cpp Lab_1/Lab_1.cpp Lab_2/Lab_2_1.cpp Lab_2/Lab_2_2.cpp)