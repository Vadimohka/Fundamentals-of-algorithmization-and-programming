#ifndef SHAPEMOVE_H
#define SHAPEMOVE_H

#include <QRectF>
#include <QPainter>

constexpr int STARTING_X = 10;

class ParentShape
{
private:
    qint16 a = 1;
    QRectF rect;
    int x1 = STARTING_X;

protected:
    int getX();
    void setX(int a);

public:
    void move_shape(int w);
    QRectF paint();
};
#endif // SHAPEMOVE_H
