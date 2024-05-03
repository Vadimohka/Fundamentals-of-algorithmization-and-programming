#include "abstractpolygon.h"

AbstractPolygon::AbstractPolygon()
{

}

void AbstractPolygon::setRect(double dx1, double dy1, double dx2, double dy2)
{
    double width = rect.width();
    double height = rect.height();
    if (dx1 != 0) {
        if (width - dx1 > 20) {
            rect.setRect(rect.left() + dx1, rect.top(), rect.width() - dx1, rect.height());
        }
    }
    if (dy1 != 0) {
        if (height - dy1 > 20) {
            rect.setRect(rect.left(), rect.top() + dy1, rect.width(), rect.height() - dy1);
        }

    }
    if (dx2 != 0) {
        if (width + dx2 > 20) {
            rect.setRect(rect.left(), rect.top(), rect.width() + dx2, rect.height());
        }
    }
    if (dy2 != 0) {
        if (height + dy2 > 20) {
            rect.setRect(rect.left(), rect.top(), rect.width(), rect.height() + dy2);
        }
    }
    editPolygon();
}

void AbstractPolygon::editPolygon()
{

}

double AbstractPolygon::getSquare()
{
    QPainterPath path;
    path.addPolygon(polygon);
    QPolygonF filledPolygon = path.toFillPolygon();

    double area = 0.0;
    for (int i = 0; i < filledPolygon.size(); ++i) {
        QPointF v1 = filledPolygon[i];
        QPointF v2 = filledPolygon[(i+1)%filledPolygon.size()];
        area += v1.x() * v2.y() - v1.y() * v2.x();
    }
    area = qAbs(area / 2.0);
    return area;
}

double AbstractPolygon::getPerimetr()
{
    double perimeter = 0.0;
    for (int i = 0; i < polygon.size(); ++i) {
        QPointF v1 = polygon[i];
        QPointF v2 = polygon[(i+1)%polygon.size()];
        perimeter += QLineF(v1, v2).length();
    }
    return perimeter;
}
