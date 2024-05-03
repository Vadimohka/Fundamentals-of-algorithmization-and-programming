#include "circle.h"
#include <QPainter>
Circle::Circle(qreal radius, QGraphicsItem *parent)
    : Shape(parent), radius(radius)
{
    calculate_points();
}

void Circle::calculate_points()
{
    // Circle can be represented as an ellipse with equal semi-axes
    qreal semiAxis = radius;

    // Initialize points vector with center as the only point
    points.resize(1);
    points[0] = QPointF(0, 0);

    // Set the center of mass of the circle to its geometric center
    setCenter(QPointF(0, 0));
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPointF rotationCenter(centX + rotatecenterx, centY + rotatecentery);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(rotationCenter);
    painter->rotate(rotate_angle);
    painter->translate(-rotationCenter);

    QPointF move(moveX+rotatecenterx, moveY + rotatecentery);
    QPointF rot(0+ rotatecenterx, 0+ rotatecentery);
   
    painter->drawEllipse(move, radius * m_scaleFactor, radius * m_scaleFactor);

   
    painter->drawEllipse(rot, 1, 1);

    painter->restore();
}

qreal Circle::area(){
    return M_PI * (radius * radius);
}
qreal Circle::perimeter(){
    return 2 * M_PI * radius;
}