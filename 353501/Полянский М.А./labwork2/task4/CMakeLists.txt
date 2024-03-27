cmake_minimum_required(VERSION 3.10)
project(ExpressionEvaluation)

set(CMAKE_CXX_STANDARD 11)

# Add executable
add_executable(hell 
main.cpp Number.cpp  Number.h BinaryOperation.cpp BinaryOperation.h 
 Expression.h 
)
