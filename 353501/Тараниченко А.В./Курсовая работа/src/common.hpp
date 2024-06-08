#ifndef COMMON_HPP
#define COMMON_HPP
#include <QString>
#include <QColor>
#include <QBrush>

const unsigned int GAME_BOARD_WIDTH = 7;
const unsigned int GAME_BOARD_HEIGHT= 6;
const double GAME_SQUARE_SIDE_LENGTH= 100.0;
const double GAME_SQUARE_ELLIPSE_PERCENT= 0.2;
const unsigned int PLAYER_COLOR_LABEL_WIDTH = 20;
const unsigned int PLAYER_COLOR_LABEL_HEIGHT = 20;
const unsigned int INIT_WINDOW_WIDTH= GAME_BOARD_WIDTH*static_cast<unsigned int>(GAME_SQUARE_SIDE_LENGTH);
const unsigned int INIT_WINDOW_HEIGHT= GAME_BOARD_HEIGHT*static_cast<unsigned int>(GAME_SQUARE_SIDE_LENGTH);

const QColor DEFAULT_PLAYER_1_COLOR = QColor("red");
const QColor DEFAULT_PLAYER_2_COLOR = QColor("yellow");
const QString DEFAULT_PLAYER_1_NAME = "Вадим";
const QString DEFAULT_PLAYER_2_NAME = "Альберт";


const QBrush SQUARE_COLOR = QBrush("blue");
const QBrush BACKGROUND_BRUSH = QBrush("lightGray");

const QString ABOUT_MSG =
    "Игра была сделана Андреем Тараниченко гр.353501";

const QString CONTACT_MSG =
    "taranichenko.a@gmail.com";

const QString GAME_HELP_MSG =
    "Игра 4 в ряд";

const QString START_GAME_MSG =
    "Click on board to start new game!";

#endif // COMMON_HPP

