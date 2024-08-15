cmake_minimum_required(VERSION 3.22)
project(tetris_cpp)

set(CXX_STANDARD 20)
add_definitions(-std=c++20)
aux_source_directory(. src)
add_executable(tetris ${src})
