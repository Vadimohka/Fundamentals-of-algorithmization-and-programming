#include "star.h"
#include <QPainter>
 
Star::Star(QPointF point, QObject *parent) :
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
 
Star::~Star()
{
 
}
 
// Реализуем метод отрисовки
void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    center = startPoint();
    if (N < 4) N = 4;
    QPolygonF polygon;

    if (is_drawing_first_time) {
    outerRadius = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2)); // Радиус внешней окружности
    innerRadius = outerRadius / 2; // Радиус внутренней окружности
    }


    for (int i = 0; i < N; ++i) {   
        double angleOuter = 2 * M_PI * i / N; // Угол для вершины на внешней окружности
        double angleInner = angleOuter + M_PI / N; // Угол для вершины на внутренней окружности

        QPointF outerVertex((startPoint().x() + outerRadius * cos(angleOuter) - rotationX) * scale, (startPoint().y() + outerRadius * sin(angleOuter) - rotationY) * scale);
        QPointF innerVertex((startPoint().x() + innerRadius * cos(angleInner) - rotationX) * scale, (startPoint().y() + innerRadius * sin(angleInner) - rotationY) * scale);

        polygon << outerVertex << innerVertex;
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

    area = abs(1/2 * outerRadius * outerRadius * N * sin(2 * M_PI / N) - N * abs(outerRadius - innerRadius) * 1/2 * 2 * outerRadius * sin(M_PI / N));
    perimeter = sqrt(pow(1/2 * 2 * outerRadius * sin(M_PI / N), 2) + pow(abs(outerRadius - innerRadius), 2)) * 2 * N; 
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}