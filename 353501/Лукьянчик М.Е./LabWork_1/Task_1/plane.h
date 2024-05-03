#ifndef PLANE_H
#define PLANE_H

#include <QObject>
#include <QWidget>
#include "moveplane.h"
#include <QRect>

class QPushButton;
class QTimer;
class Plane : public MovePlane
{
    Q_OBJECT
private slots:
    void startEvent();
    void delbutton();
    void beginAnimation();
private:
    int x;
    float y;
    QTimer* timer;
    QRect road;
    QRect backroad;
    QRect sign;
    QRect flag;
    QRect sky;
    QRect a;
    QRect b;
    QPushButton* button;
    bool startPaint;
    void paintEvent(QPaintEvent*);
    MovePlane mainPart, rightWing,leftWing;

public:
    Plane();
};

#endif // PLANE_H
