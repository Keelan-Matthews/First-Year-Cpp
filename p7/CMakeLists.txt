cmake_minimum_required(VERSION 3.20)
project(p7)

set(CMAKE_CXX_STANDARD 98)

add_executable(p7 main.cpp dispatch.cpp dispatch.h dList.cpp dList.h trainCar.cpp trainCar.h train.cpp train.h)
