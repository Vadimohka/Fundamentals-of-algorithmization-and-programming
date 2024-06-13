cmake_minimum_required(VERSION 3.27)
project(lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/acryoz/Qt/5.15.16/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab5 main.cpp
        src/keyboard.cpp
        headers/keyboard.h
        src/keyboard.ui
        headers/layouts.h
        src/mainwindow.cpp
        headers/mainwindow.h
        src/mainwindow.ui
        src/textedit.cpp
        headers/textedit.h
        src/textedit.ui
        headers/texts.h)
target_link_libraries(lab5
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_executable(bitset othertasks/main.cpp
        othertasks/mybitset.cpp
        othertasks/mybitset.h)

add_executable(string othertasks/main_str.cpp
        othertasks/string.cpp
        othertasks/string.h
        othertasks/iterator.cpp
        othertasks/iterator.h)

