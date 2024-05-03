#ifndef STAR_H
#define STAR_H

#include "regularpolygon.h"

class Star : public RegularPolygon
{
    Q_OBJECT
public:
    explicit Star(QPointF point, QObject *parent = nullptr);
    ~Star();

    void setSquare(QVector<QPointF> points);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF m_outerRadius;
    QPointF m_innerRadius;
};

#endif // STAR_H
