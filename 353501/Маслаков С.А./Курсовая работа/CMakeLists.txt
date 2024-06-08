cmake_minimum_required(VERSION 3.26)
project(Snake_game)

set(CMAKE_PREFIX_PATH "/Users/sagot/Qt/6.6.1/macos")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)
qt_standard_project_setup()

qt_add_executable(Snake_game
        food.cpp
        food.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        snake.cpp
        snake.h
        Pepper.cpp
        Pepper.h
        ItemsContainer.cpp
        ItemsContainer.h
        SnakeAI.cpp
        SnakeAI.h
        SnakePart.cpp
        SnakePart.h
        menuwindow.cpp
        menuwindow.h
        menuwindow.ui
        Stone.cpp
        Stone.h
        leaderboardwindow.cpp
        leaderboardwindow.h
        leaderboardwindow.ui
        database.cpp
        database.h)
qt_add_resources(Snake_game "images"
        PREFIX "/"
        FILES
        images/f1.png
        images/f2.png
        images/f3.png
        images/f4.png
        images/f5.png
        images/f6.png
        images/logo.png
        images/snakeUnit1.png
        images/snakeUnit1Head.png
        images/snakeUnit2.png
        images/snakeUnit2Head.png
        images/snakeUnit2.png
        images/snakeUnit2Head.png
        images/snakeUnit3.png
        images/snakeUnit3Head.png
        images/snakeUnit4.png
        images/snakeUnit4Head.png
        images/snakeUnit5.png
        images/snakeUnit5Head.png
        images/snakeUnit6Head.png
        images/snakeUnit6.png
        images/snakeUnit7Head.png
        images/snakeUnit7.png
        images/snakeUnit8Head.png
        images/snakeUnit8.png
        images/snakeUnit9Head.png
        images/snakeUnit9.png
        images/snakeUnit10Head.png
        images/snakeUnit10.png
        images/skinBut.png
        images/pepper.png
        images/stone.png
        images/back.jpg
        images/pausebut.png
)
target_link_libraries(Snake_game PRIVATE Qt6::Widgets Qt6::Sql)

set_target_properties(Snake_game PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)