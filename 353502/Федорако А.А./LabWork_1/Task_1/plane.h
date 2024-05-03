#ifndef PLANE_H
#define PLANE_H

#include "moving_rectangle.h"

class Plane : public MovingRectangle, public QObject {
public:
    Plane();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void changeChassis();
    void setChassis(bool newChassis);
    bool getChassis();
    void addPointUp();
    void addPointDown();
    void addPointLeft();
    void addPointRight();
    double getNowPossitionPlaneOnX();
    double getNowPossitionPlaneOnY();
private:
    bool chassis;
    double firstPossitionPlaneOnX;
    double firstPossitionPlaneOnY;
    double nowPossitionPlaneOnX;
    double nowPossitionPlaneOnY;
};


#endif // PLANE_H
