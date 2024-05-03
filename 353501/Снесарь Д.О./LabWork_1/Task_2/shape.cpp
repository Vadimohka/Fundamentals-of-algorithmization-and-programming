#include "shape.h"

Shape::Shape()
{
    s = 0;
    p = 0;
}

int Shape::getId()
{
    return 1;
}



void Shape::draw(QPainter *pntr)
{
    QPolygonF polygon;
    for(int i = 0; i < points.count(); ++i){
        polygon << points[i];
    }
    pntr->drawPolygon(polygon);
   // pntr->drawEllipse(center, 3,3);
}

void Shape::move(QPointF nPoint)
{
    // if(center.x() > 0 && center.y() > 0){
    for(int i = 0; i < points.count(); ++i){
        points[i] = QPointF(points[i] + nPoint - center);
    }
    center = nPoint;
    // }

    /*  if(center.x() <= 0){
        QPointF temp(5, 0);
        center += temp;
        for(int i = 0; i < points.count(); ++i){
            points[i] += temp;
        }
    }

    if(center.y() <= 0){
        QPointF temp(0, 5);
        center += temp;
        for(int i = 0; i < points.count(); ++i){
            points[i] += temp;
        }
    }
*/
}

void Shape::setSize(QPointF nPoint)
{

}




QPointF Shape::getPoint(int n)
{
    if(points.size() > n)
        return points[n];
    else qDebug() << "error points";
}

QVector<QPointF> Shape::getPointsVector()
{
    return points;
}



void Shape::setCenterEdit(QPointF newPoint, int pointN)
{
    points[pointN] = newPoint;
    center = QPointF(0, 0);
    for(int i = 0; i < points.size(); i++)
    {
        center += points[i];
    }
    center /= points.size();

}

void Shape::rotateR()
{
    double angle = 0.05;
    for(int i = 0; i < points.size() ; i++)
    {
        double newx = (points[i].x() - center.x())*cos(angle) - (points[i].y() - center.y())*sin(angle) + center.x();
        double newy = (points[i].y() - center.y())*cos(angle) + (points[i].x() - center.x())*sin(angle) + center.y();
        points[i].setX(newx);
        points[i].setY(newy);
    }
}

void Shape::rotateL()
{
    double angle = - 0.05;
    for(int i = 0; i < points.size() ; i++)
    {
        double newx = (points[i].x() - center.x())*cos(angle) - (points[i].y() - center.y())*sin(angle) + center.x();
        double newy = (points[i].y() - center.y())*cos(angle) + (points[i].x() - center.x())*sin(angle) + center.y();
        points[i].setX(newx);
        points[i].setY(newy);
    }


}

void Shape::upScale()
{
    double scale = 1.01;

    for(int i = 0; i < points.count(); ++i){
        points[i] = (points[i] - center) * scale + center;
    }

}

void Shape::downScale()
{

    double scale = 0.99;
    for(int i = 0; i < points.count(); ++i){
        points[i] = (points[i] - center) * scale + center;
    }
}

double Shape::getS()
{
    s = 0;
    for (int i = 0; i < points.size() - 1; ++i){
        s += points[i].x() * points[i + 1].y() - points[i].y() * points[i + 1].x();
    }
    s += points[0].y() * points[points.size() - 1].x() - points[0].x() * points[points.size() - 1].y();
    s = qAbs(s) / 2;
    return s;
}

double Shape::getP()
{
    p = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        p += sqrt((points[i].y() - points[i + 1].y()) * (points[i].y() - points[i + 1].y()) + (points[i].x() - points[i + 1].x()) * (points[i].x() - points[i + 1].x()));
    }

    p += sqrt((points[0].y() - points[points.size() - 1].y()) * (points[0].y() - points[points.size() - 1].y()) + (points[0].x() - points[points.size() - 1].x()) * (points[0].x() - points[points.size() - 1].x()));
    return p;
}



int Shape::getAngle()
{
    return curAngle;
}

