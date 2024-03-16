#ifndef ELLIPS_H
#define ELLIPS_H

#include <QGraphicsEllipseItem>

class Ellips:  public QGraphicsEllipseItem
{
public:
    Ellips(int x, int y, int hei, int wid, QGraphicsEllipseItem*parent = nullptr);
};

#endif // ELLIPS_H
