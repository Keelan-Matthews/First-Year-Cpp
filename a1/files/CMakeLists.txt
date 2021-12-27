cmake_minimum_required(VERSION 3.20)
project(COS110)

set(CMAKE_CXX_STANDARD 98)

include_directories(".")

add_executable(COS110
        "HiddenLayer.cpp"
        "HiddenLayer.h"
        "HiddenNeuron.cpp"
        "HiddenNeuron.h"
        "InputLayer.cpp"
        "InputLayer.h"
        "OutputLayer.cpp"
        "OutputLayer.h"
        "NeuralNetwork.cpp"
        "NeuralNetwork.h"
        "main.cpp")
