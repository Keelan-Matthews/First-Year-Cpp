cmake_minimum_required(VERSION 3.20)
project(p8)

set(CMAKE_CXX_STANDARD 98)

add_executable(p8 main.cpp DynamicList.cpp DynamicList.h Node.cpp Node.h)
