#include "shape.h"

Shape::Shape() = default;

QRectF Shape::boundingRect() const
{
    return QRectF();
}

void Shape::upScale()
{
    scale += 0.01;
}

void Shape::downScale()
{
    if(scale >= 0.1){
        scale -= 0.01;
    }
}

void Shape::rotateLeft()
{
    rotation -= 1;
}

void Shape::rotateRight()
{
    rotation += 1;
}

void Shape::changeX(qreal value)
{
    shiftX = value;
}

void Shape::changeY(qreal value)
{
    shiftY = value;
}

void Shape::changeSide1(qreal value)
{
    side1 = value;
}

void Shape::changeSide2(qreal value)
{
    side2 = value;
}

void Shape::changeSide3(qreal value)
{
    side3 = value;
}

void Shape::changeAngle(qreal value)
{
    anglePoly = value;
}

void Shape::changePoints(int value)
{
    numPoints = value;
}

void Shape::changeRadius1(qreal value)
{
    radius1 = value;
}

void Shape::changeRadius2(qreal value)
{
    radius2 = value;
}

void Shape::setDetached(bool isChecked)
{
    detached = isChecked;
    if(detached){
        lastShiftX = shiftX;
        lastShiftY = shiftY;
        lastRotation = rotation;
    }
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF polygon;
    calculatePoints();

    shift = QPointF(shiftX, shiftY);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(0, -300);

    shiftDetached = QPointF(lastShiftX, lastShiftY);

    painter->translate(shift);
    painter->rotate(rotation);
    painter->translate(-shift);

    if(detached)
    {
        for(auto &point : points){
            polygon << point * scale + shiftDetached;
        }
    }
    else
    {
        for(auto &point : points){
            polygon << point * scale + shift;
        }
    }

    painter->drawPolygon(polygon);
    painter->drawEllipse(shift, 1, 1);
}

void Shape::calculatePoints()
{

}

void Shape::setCenterOfMass()
{
    qreal centerX = 0;
    qreal centerY = 0;

    int size = points.size();
    for(int i = 0; i < size; i++){
        centerX += (pointsX[i]) / size;
        centerY += (pointsY[i]) / size;
    }

    for (int i = 0; i < size; ++i) {
        pointsX[i] -= centerX;
        pointsY[i] -= centerY;
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
}

qreal Shape::area()
{
    int numPoints = points.size();
    if (numPoints < 3) {
        return 0.0;
    }

    qreal sum = 0.0;
    for (int i = 0; i < numPoints; ++i) {
        const QPointF& currentPoint = points[i] * scale;
        const QPointF& nextPoint = points[(i + 1) % numPoints] * scale;
        sum += (nextPoint.x() - currentPoint.x()) * (nextPoint.y() + currentPoint.y());
    }

    return std::abs(sum) / 2.0;
}

qreal Shape::perimeter()
{
    int numPoints = points.size();
    if (numPoints < 2) {
        return 0.0;
    }

    qreal sum = 0.0;
    for (int i = 0; i < numPoints; ++i) {
        const QPointF& currentPoint = points[i] * scale;
        const QPointF& nextPoint = points[(i + 1) % numPoints] * scale;
        qreal dx = nextPoint.x() - currentPoint.x();
        qreal dy = nextPoint.y() - currentPoint.y();
        sum += std::sqrt(dx * dx + dy * dy);
    }

    return sum;
}

void Shape::clear()
{

}

