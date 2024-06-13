cmake_minimum_required(VERSION 3.16)

project(tt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(helloapp
  board.cpp
board.h
brick.cpp
brick.h
game.cpp
game.h
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
observer.cpp
observer.h
qbrick.cpp
qbrick.h
qgameboard.cpp
qgameboard.h
qgameoverwindow.cpp
qgameoverwindow.h
qresetbutton.cpp
qresetbutton.h
subject.cpp
subject.h
)

target_link_libraries(helloapp PRIVATE Qt6::Widgets)

set_target_properties(helloapp PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON

)
