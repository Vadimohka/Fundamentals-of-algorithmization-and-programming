#include "star.h"

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->rotate(angle);
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


qreal Star::squareOfFigure()
{
    qreal temp = 2 * radius1 * sin(Angle / 2);
    return (temp * radius2 * number) / 2;
}

qreal Star::perimetrOfFigure()
{
    return 2*number*(sqrt(radius1 * radius1 + radius2 * radius2 - 2*radius1*radius2*cos(Angle / 2)));
}

void Star::resize(qreal changeSize)
{
    radius1 *= changeSize;
    radius2 *= changeSize;
    points = QVector<QPointF> ();
    QPointF temp1, temp2;
    for (int i = 0; i < number; ++i)
    {
        temp1 = QPointF(radius1 * cos(Angle * i), radius1 * sin(Angle * i));
        temp2 = QPointF(radius2 * cos(Angle * i + Angle/2), radius2 * sin(Angle * i + Angle/2));
        points.push_back(temp1);
        points.push_back(temp2);
    }
    update();
    emit updateFigure();
}

Star::Star(int numberOfStar, bool isPolygon)
{
    number = numberOfStar;
    Angle = (3.1415 * 2) / number;

    if (isPolygon)
    {
        radius2 = 70;
        radius1 = radius2 * cos(3.1415 / number);
    }

    QPointF temp1, temp2;
    for (int i = 0; i < number; ++i)
    {
        temp1 = QPointF(radius1 * cos(Angle * i), radius1 * sin(Angle * i));
        temp2 = QPointF(radius2 * cos(Angle * i + Angle/2), radius2 * sin(Angle * i + Angle/2));
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



