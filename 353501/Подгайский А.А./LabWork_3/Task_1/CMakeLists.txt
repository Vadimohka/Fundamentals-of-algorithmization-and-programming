cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
qt_standard_project_setup()

qt_add_executable(helloapp
  main.cpp mainwindow.cpp Converter.cpp LongDoubleValidator.cpp mainwindow.h mainwindow.ui
)

add_executable(test test.cpp Converter.cpp)

target_link_libraries(test PRIVATE Qt6::Core)

target_link_libraries(helloapp PRIVATE Qt6::Widgets Qt6::Core)

# set_target_properties(helloapp PROPERTIES
#     WIN32_EXECUTABLE ON
#     MACOSX_BUNDLE ON
# )