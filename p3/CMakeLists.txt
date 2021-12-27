cmake_minimum_required(VERSION 3.20)
project(Practical_3)

set(CMAKE_CXX_STANDARD 98)

include_directories(".")

add_executable(Practical_3 cauldron.cpp cauldron.h ingredient.cpp ingredient.h main.cpp)
