cmake_minimum_required(VERSION 3.28)
project(lab2_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_3 main.cpp
        Expression.cpp
        Expression.h
        Number.cpp
        Number.h
        BinaryOperation.cpp
        BinaryOperation.h)
