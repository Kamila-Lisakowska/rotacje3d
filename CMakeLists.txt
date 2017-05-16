cmake_minimum_required(VERSION 3.7)
project(robot)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Robot.cpp
        Robot.h
        lacze_do_gnuplota.cpp
        lacze_do_gnuplota.h
        main.cpp
        Matrix.cpp
        Matrix.h
        Scena.cpp
        Scena.h
        Vector2d.cpp
        Vector2d.h Path.cpp Path.h)

add_executable(robot ${SOURCE_FILES})