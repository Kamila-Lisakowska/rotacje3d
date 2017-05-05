cmake_minimum_required(VERSION 3.7)
project(rotacje3d)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Cuboid.cpp Cuboid.h Vector3d.cpp Vector3d.h Matrix.cpp Matrix.h)
add_executable(rotacje3d ${SOURCE_FILES})