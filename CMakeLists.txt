cmake_minimum_required(VERSION 3.20)
project(geometry)

set(CMAKE_CXX_STANDARD 14)

add_executable(geometry
        main.cpp Circle.h Point.h Triangle.h Rectangle.h Container.h Figure.h utils.h)
