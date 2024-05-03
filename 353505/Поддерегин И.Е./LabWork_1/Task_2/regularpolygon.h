#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "shape.h"

class RegularPolygon : public Shape
{
    Q_OBJECT
public:
    explicit RegularPolygon(QPointF point, QObject *parent = nullptr);
    ~RegularPolygon();

    qreal square() override;
    qreal perimeter() override;

    void setSquare();
    void setPerimeter(QVector<QPointF> points);

    void setVertexCount(int vertexCount) override;

protected:
    int m_vertexCount = 6;
    qreal m_angleIncrement;
    qreal m_square;
    qreal m_perimeter;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF m_radius;
};

#endif // REGULARPOLYGON_H
