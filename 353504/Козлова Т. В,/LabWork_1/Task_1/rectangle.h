#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class Rectangle : public QWidget
{
public:
    Rectangle(int x, int y, int width, int height, QWidget* parent = nullptr);
    ~Rectangle();

    void startMoveDown();
    void startMoveUp();

protected:
    void movingDown();
    void movingUp();

    int x;
    int y;
    int buffY = y;
    int width;
    int height;
    QTimer* timerDown;
    QTimer* timerUp;
};

#endif // RECTANGLE_H
