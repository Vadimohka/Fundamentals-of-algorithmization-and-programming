cmake_minimum_required(VERSION 3.27)
project(coursework)

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

add_executable(coursework src/main.cpp
        lib/Board.cpp
        include/Board.h
        include/Pieces.h
        lib/Move.cpp
        include/Move.h
        include/Squares.h
        lib/Pieces.cpp
        lib/evaluation.cpp
        lib/search.cpp
        lib/move_generation.cpp
        include/SquareValues.h
        src/startmenu.cpp
        src/startmenu.h
        src/startmenu.ui
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/textboard.cpp
        src/textboard.h
        src/textboard.ui
        src/movelineedit.cpp
        src/movelineedit.h
        src/movelineedit.ui
        src/endmenu.cpp
        src/endmenu.h
        src/endmenu.ui
)
target_link_libraries(coursework
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

