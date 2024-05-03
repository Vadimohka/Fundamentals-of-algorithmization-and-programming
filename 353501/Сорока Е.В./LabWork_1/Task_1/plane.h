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
    int x;
    float y;
    int dx, dy;
    QTimer* timer;
    QRect road;
    QRect a;
    QRect b;
    QRect sky;
    QPolygon tale;
    QPolygon nos;
    QPushButton* button;
    bool startPaint;
    void paintEvent(QPaintEvent*);
    MovingRect mainPart, rightWing,leftWing;

public:
    Plane();
};

#endif // PLANE_H
