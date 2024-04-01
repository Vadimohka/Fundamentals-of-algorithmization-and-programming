#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPainter>
#include <QWidget>

class Circle : public QWidget
{
public:
    void size(int newX, int newY, int newRadius);
    void color(int x, int y, int z);
protected:
    void paintEvent(QPaintEvent *event);
private:
    int x;
    int y;
    int radius;
    int color1;
    int color2;
    int color3;
};

#endif // CIRCLE_H
