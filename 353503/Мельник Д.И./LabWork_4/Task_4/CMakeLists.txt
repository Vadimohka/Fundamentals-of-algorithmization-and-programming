cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME Vector)
project(${PROJECT_NAME})

add_executable(vector_test
        main.cpp
        vector.h
        allocator.h
)