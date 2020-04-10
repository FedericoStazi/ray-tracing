cmake_minimum_required(VERSION 3.15)
project(cpp_graphics)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_graphics main.cpp Utils/TimeGeometry/TimeVector2.cpp Utils/TimeGeometry/TimeVector2.h Utils/TimeGeometry/TimeVector3.cpp Utils/TimeGeometry/TimeVector3.h Utils/TimeGeometry/TimeFunction.cpp Utils/TimeGeometry/TimeFunction.h Utils/TimeGeometry/TimeUnitVector3.cpp Utils/TimeGeometry/TimeUnitVector3.h Utils/Color.cpp Utils/Color.h Utils/Matrix.cpp Utils/Matrix.h Utils/Geometry/Vector3.cpp Utils/Geometry/Vector3.h Utils/Geometry/UnitVector3.cpp Utils/Geometry/UnitVector3.h Utils/Geometry/Vector2.cpp Utils/Geometry/Vector2.h Utils/Geometry/Line.cpp Utils/Geometry/Line.h Utils/Geometry/Bases.cpp Utils/Geometry/Bases.h)