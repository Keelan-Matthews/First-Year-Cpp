cmake_minimum_required(VERSION 3.20)
project(a3)

set(CMAKE_CXX_STANDARD 98)

add_executable(a3 main.cpp Babushka.cpp Babushka.h BlueBabushka.cpp BlueBabushka.h DarkBlueBabushka.cpp DarkBlueBabushka.h LightBlueBabushka.cpp LightBlueBabushka.h GoldBabushka.cpp GoldBabushka.h GreenBabushka.cpp GreenBabushka.h RedBabushka.cpp RedBabushka.h YellowBabushka.cpp YellowBabushka.h BabushkaException.h DisplacementException.cpp DisplacementException.h OverflowException.cpp OverflowException.h RotateException.cpp RotateException.h UnderflowException.cpp UnderflowException.h ControllerException.cpp ControllerException.h Controller.cpp Controller.h)
