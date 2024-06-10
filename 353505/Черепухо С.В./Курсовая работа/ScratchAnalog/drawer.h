#ifndef DRAWER_H
#define DRAWER_H

#include <QPainter>
#include "sprite.h"

class Drawer
{
public:
    Drawer();

    Drawer(QPainter *painter);

    int x, y, w, h, penWidth = 1;

    QPen thePen;

    QColor color = "black";

    QPixmap *transBack, *workSpace, *tempWorkSpace;

    QPoint lastCurrent;

    void base(QPainter *painter);

    void drawPen(QPoint current);
    void drawErase(QPoint current);
    void drawRect(QPoint first, QPoint current);
    void drawEllipce(QPoint first, QPoint current);
    void drawLine(QPoint first, QPoint current);
    void saveFigure();
    void clear();

    void draw(QPainter *painter);

    Sprite saveNewSprite();
};

#endif // DRAWER_H
