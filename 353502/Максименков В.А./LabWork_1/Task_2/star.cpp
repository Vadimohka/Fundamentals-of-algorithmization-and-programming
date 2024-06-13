#include "star.h"

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i < number * 2; ++i)
    {
        int next = i + 1;
        if(i == number * 2 - 1)next = 0;
        painter->drawLine(points[i], points[next]);
    }
}

QRectF Star::boundingRect() const
{
    qreal maxRadius = (radius1 >= radius2 ? radius1 : radius2);
    return QRectF(-maxRadius, -maxRadius, 2*maxRadius, 2*maxRadius);
}

void Star::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - centerOfShape.x()) * (now.x() - centerOfShape.x()) + (now.y() - centerOfShape.y()) * (now.y() - centerOfShape.y()));
    qreal temp = radius1 / radius2;
    radius2 += distance - defaultDistance;
    radius1 = radius2 * temp;
    points = QVector<QPointF> ();
    QPointF temp1, temp2;
    for (int i = 0; i < number; ++i)
    {
        temp1 = QPointF(radius1 * cos(angle * i), radius1 * sin(angle * i));
        temp2 = QPointF(radius2 * cos(angle * i + angle/2), radius2 * sin(angle * i + angle/2));
        points.push_back(temp1);
        points.push_back(temp2);
    }
    update();
    emit updateShape();
    defaultDistance = distance;
}

qreal Star::squareOfShape()
{
    qreal temp = 2 * radius1 * sin(angle / 2);
    return (temp * radius2 * number) / 2;
}

qreal Star::perimetrOfShape()
{
    return 2*number*(sqrt(radius1 * radius1 + radius2 * radius2 - 2*radius1*radius2*cos(angle / 2)));
}

void Star::reinterpret(qreal parametr1, qreal parametr2)
{
    radius1 = parametr1;
    radius2 = parametr2;
    points = QVector<QPointF> ();
    QPointF temp1, temp2;
    for (int i = 0; i < number; ++i)
    {
        temp1 = QPointF(radius1 * cos(angle * i), radius1 * sin(angle * i));
        temp2 = QPointF(radius2 * cos(angle * i + angle/2), radius2 * sin(angle * i + angle/2));
        points.push_back(temp1);
        points.push_back(temp2);
    }
    update();
    emit updateShape();
}

Star::Star(int numberOfStar, bool isPolygon)
{
    number = numberOfStar;
    angle = (3.1415 * 2) / number;

    if (isPolygon)
    {
        radius2 = 70;
        radius1 = radius2 * cos(3.1415 / number);
    }

    QPointF temp1, temp2;
    for (int i = 0; i < number; ++i)
    {
        temp1 = QPointF(radius1 * cos(angle * i), radius1 * sin(angle * i));
        temp2 = QPointF(radius2 * cos(angle * i + angle/2), radius2 * sin(angle * i + angle/2));
        points.push_back(temp1);
        points.push_back(temp2);
    }
    if (isPolygon)
    {
        setPos(300, 200);
    }
    else
    {
        setPos(200, 200);
    }
}



