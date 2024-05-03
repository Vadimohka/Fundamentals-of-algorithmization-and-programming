#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

class Rectangle : public QGraphicsItem
{
public:
    Rectangle();

    void MoveUp();
    void MoveDown();

    bool MovesDown = false;
    bool MovesUp = false;
    int xpos = 0;
    int ypos = 0;

    int Checky();
};
#endif // RECTANGLE_H
