#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QWidget>
#include "movingrect.h"
#include <QRect>
#include <QPolygon>
class QPushButton;
class QTimer;
class Plane : public MovingRect
{
    Q_OBJECT
private slots:
    void startEvent();
    void beginAnimation();
private:
    QPolygon nose;
    int dx;
    int dy;
    QPolygon tail;
    int x;
    float y;
    QTimer* timer;
    QRect road;
    QRect a;
    QRect b;
    QPushButton* button;
    bool startPaint;
    void paintEvent(QPaintEvent*);
    MovingRect mainPart, rightWing,leftWing;

public:
    Plane();
};

#endif // PLANE_H
