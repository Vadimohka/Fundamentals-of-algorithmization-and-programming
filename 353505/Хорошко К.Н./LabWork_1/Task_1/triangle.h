#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QWidget>
#include <QPainter>

class Triangle : public QWidget
{
public:
    void size(int newX1, int newY1, int newX2, int newY2, int newX3, int newY3);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
};

#endif // TRIANGLE_H
