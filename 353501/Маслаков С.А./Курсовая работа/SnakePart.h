#include "snake.h"
#include <QGraphicsPixmapItem>
#ifndef SNAKE_GAME_SNAKEPART_H
#define SNAKE_GAME_SNAKEPART_H
class Snake;
class SnakePart: public QGraphicsPixmapItem
{
public:
    SnakePart(QString);
    QString snakeName;
};



#endif //SNAKE_GAME_SNAKEPART_H
