#include "star.h"
#include <QPainter>
 
Star::Star(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
    N = 0;
}
 
Star::~Star()
{
 
}
 
// Реализуем метод отрисовки
void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
painter->setPen(QPen(Qt::white, 2));

// Определите координаты вершин внешней и внутренней окружностей
QPointF outerCenter(startPoint().x(), startPoint().y()); // Координаты центра внешней окружности
QPointF innerCenter(startPoint().x(), startPoint().y()); // Координаты центра внутренней окружности
double outerRadius = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2)); // Радиус внешней окружности
double innerRadius = outerRadius / 2; // Радиус внутренней окружности


if (N < 4) N = 4;
qDebug() << "Star" << N;
// Вычислите координаты вершин пятиконечной звезды
QPolygonF star;
for (int i = 0; i < N; ++i) {   
    double angleOuter = 2 * M_PI * i / N; // Угол для вершины на внешней окружности
    double angleInner = angleOuter + M_PI / N; // Угол для вершины на внутренней окружности

    QPointF outerVertex(startPoint().x() + outerRadius * cos(angleOuter), startPoint().y() + outerRadius * sin(angleOuter));
    QPointF innerVertex(startPoint().x() + innerRadius * cos(angleInner), startPoint().y() + innerRadius * sin(angleInner));

    star << outerVertex << innerVertex;
}

// Рисование звезды
painter->drawPolygon(star);
 
    Q_UNUSED(option)
    Q_UNUSED(widget)
}