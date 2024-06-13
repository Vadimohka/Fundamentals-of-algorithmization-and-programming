#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <cmath>

class Rectangle : public QWidget
{
    Q_OBJECT
public:
    explicit Rectangle(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);
private:
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    int x5,y5;
    int x6,y6;
    int x7,y7;
    int x8,y8;
    int a,b;
    double phi;
signals:

public slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

};

#endif // RECTANGLE_H
