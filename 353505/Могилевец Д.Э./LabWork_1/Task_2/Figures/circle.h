#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometryshape.h"

class Circle : public GeometryShape
{
public:
    Circle();
private:
    qreal radius;
    void draw(QPainter&) override;
    void deltaRotation(qreal) override;
    void deltaScale(qreal, qreal) override;
    void deltaShift(QPointF) override;
    void updateArea() override;
    void updatePerimetr() override;
    void updateMassCenter() override;
};

#endif // CIRCLE_H
