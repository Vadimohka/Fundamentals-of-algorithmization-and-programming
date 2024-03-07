#ifndef POLYGON_H
#define POLYGON_H

#include "geometryshape.h"

class Polygon : public GeometryShape
{
public:
    Polygon();
    ~Polygon();
protected:
    void draw(QPainter&) override;
    void deltaRotation(qreal) override;
    void deltaScale(qreal, qreal) override;
    void deltaShift(QPointF) override;
    void updateArea() override;
    void updatePerimetr() override;
    void updateMassCenter() override;
    int amountOfVertexes;
    QPointF* vertexes;
};

#endif // POLYGON_H
