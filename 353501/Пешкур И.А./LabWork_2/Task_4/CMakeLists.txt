cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

add_executable( Task3_4_1 Task3_4_1.cpp )

add_library( binaryoperation STATIC binaryoperation.cpp )
add_library( expression STATIC expression.cpp )
add_library( number STATIC number.cpp )

target_link_libraries( Task3_4_1 PRIVATE binaryoperation expression number )