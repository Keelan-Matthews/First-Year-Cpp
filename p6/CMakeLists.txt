cmake_minimum_required(VERSION 3.20)
project(p6)

set(CMAKE_CXX_STANDARD 98)

add_executable(p6 main.cpp train.cpp train.h trolley.cpp trolley.h manager.cpp manager.h tooSlow.h tooFast.h storageEmpty.h storageFull.h)
