#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QPainter>
#include <QWidget>
#include <QVector>
#include "mainwindow.h"

class Rectangle : public QWidget
{
    Q_OBJECT
public:
    Rectangle(int x, int y, int w, int h);
    void setW(int w);
    void setH(int h);
    void setX(int x);
    void setY(int y);
    static void foo(int* arr, int n, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr);
protected:
    void paintEvent(QPaintEvent *event);
private:
    int w, h, x, y;
};

#endif // RECTANGLE_H
