cmake_minimum_required(VERSION 3.20)
project(a2)

set(CMAKE_CXX_STANDARD 98)

add_executable(a2 piece.cpp piece.h main.cpp board.cpp board.h solver.cpp solver.h)
