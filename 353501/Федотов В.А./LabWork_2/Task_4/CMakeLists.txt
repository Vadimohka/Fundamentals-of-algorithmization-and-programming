cmake_minimum_required(VERSION 3.16)
project(Task4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Task4 main.cpp 
../Task3/expression.h
../Task3/number.h
../Task3/number.cpp
../Task3/binaryOperation.h
../Task3/binaryOperation.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
