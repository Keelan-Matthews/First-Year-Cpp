cmake_minimum_required(VERSION 3.20)
project(p5)

set(CMAKE_CXX_STANDARD 98)

add_executable(p5 main.cpp component.cpp component.h locomotive.cpp locomotive.h cargo.cpp cargo.h passenger.cpp passenger.h train.cpp train.h)
