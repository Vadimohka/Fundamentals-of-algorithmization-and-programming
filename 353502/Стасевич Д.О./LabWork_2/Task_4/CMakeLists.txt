cmake_minimum_required(VERSION 3.27)
project(task3)

set(CMAKE_CXX_STANDARD 17)

add_executable(task3 main.cpp
        Expression.cpp
        Expression.h
        Number.cpp
        Number.h
        BinaryOperation.cpp
        BinaryOperation.h)
