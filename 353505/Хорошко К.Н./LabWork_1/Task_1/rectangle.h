#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <QWidget>

class Rectangle : public QWidget
{

public:
    Rectangle();
    ~Rectangle();
    void size(int newX1, int newY1, int newW, int newH);
    void color(int x, int y, int z);
protected:
    void paintEvent(QPaintEvent *event);


private:
    int x1;
    int y1;
    int W;
    int H;
    int color1;
    int color2;
    int color3;
};

#endif // RECTANGLE_H
