cmake_minimum_required(VERSION 3.20)
project(a4)

set(CMAKE_CXX_STANDARD 98)

add_executable(a4 main.cpp Message.cpp Message.h Layer.cpp Layer.h Application.cpp Application.h Presentation.cpp Presentation.h Transport.cpp Transport.h Network.cpp Network.h Datalink.cpp Datalink.h Physical.cpp Physical.h)
