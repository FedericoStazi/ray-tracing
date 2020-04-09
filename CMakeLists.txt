cmake_minimum_required(VERSION 3.15)
project(cpp_graphics)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_graphics main.cpp Geometry/Vector2.cpp Geometry/Vector2.h Geometry/Vector3.cpp Geometry/Vector3.h Geometry/TimeFunction.cpp Geometry/TimeFunction.h)