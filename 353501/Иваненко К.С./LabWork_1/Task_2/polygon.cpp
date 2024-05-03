#include "polygon.h"
#include <QPainter>
 
Polygone::Polygone(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    N = 0;
    scale = 1;
    rotation = 0;
    rotationX = 0;
    rotationY = 0;
    sideA = 0;
    sideB = 0;
    sideC = 0;
    area = 0;
    perimeter = 0;
    angel = 0;
    outerRadius = 0;
    innerRadius = 0;
    center = QPointF(0, 0);
    pointA = QPointF(0, 0);
    pointB = QPointF(0, 0);
    pointC = QPointF(0, 0);
    A_x = 0;
    A_y = 0;
    B_x = 0;
    B_y = 0;
    C_x = 0;
    C_y = 0;
    is_drawing_first_time = true;
}
 
Polygone::~Polygone()
{
 
}
 
// Реализуем метод отрисовки
void Polygone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    center = startPoint();

    if (is_drawing_first_time) {
    outerRadius = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2));
    }

    if (N < 3) N = 3;
    QPolygonF polygon;
    for (int i = 0; i < N; ++i) {

        double angleOuter = 2 * M_PI * i / N; // Угол для вершины на внешней окружности

        QPointF outerVertex((startPoint().x() + outerRadius * cos(angleOuter) - rotationX) * scale, (startPoint().y() + outerRadius * sin(angleOuter) - rotationY) * scale);

        polygon << outerVertex;
    }

    painter->setPen(QPen(Qt::red, 5));
    painter->drawPoint(rotationX, rotationY);

    painter->save();
    painter->translate(rotationX, rotationY);
    painter->rotate(rotation);
    painter->setPen(QPen(Qt::green, 5));
    painter->drawPoint((center - QPoint(rotationX, rotationY)) * scale);
    painter->setPen(QPen(Qt::gray, 2));
    painter->drawPolygon(polygon);
    painter->restore();

    area = 0.5 * outerRadius * outerRadius * N * sin(M_PI * 2 / N);
    perimeter = N * 2 * outerRadius * sin(M_PI / N);
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}