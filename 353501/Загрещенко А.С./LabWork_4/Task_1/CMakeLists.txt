cmake_minimum_required(VERSION 3.16)

project(Task_1 VERSION 1.0)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets TextToSpeech)

find_package(Qt6TextToSpeech REQUIRED)

add_executable(Task_1 main.cpp)

target_link_libraries(Task_1 Qt6::Core Qt6::Widgets Qt6::TextToSpeech)

set_target_properties(Task_1 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)