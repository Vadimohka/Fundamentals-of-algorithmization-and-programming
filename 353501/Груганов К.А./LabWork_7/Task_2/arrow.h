#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QPainter>
#include <cmath>

class Arrow : public QGraphicsLineItem
{
public:
    Arrow(QGraphicsItem *startItem, QGraphicsItem *endItem)
    {
        // Устанавливаем начальную и конечную точки линии в соответствии с позициями элементов
        QLineF line(mapFromItem(startItem, 0, 0), mapFromItem(endItem, 0, 0));
        setLine(line);
    }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        if (line().length() == 0)
            return;
        QPen pen(Qt::black, 2);
        painter->setPen(pen);
        painter->setBrush(Qt::black);

        // Рисуем линию
        painter->drawLine(line());

        // Рисуем стрелочную головку
        double angle = std::atan2(-line().dy(), line().dx());

        QPointF arrowHeadP1 = line().p1()
                              + QPointF(sin(angle - M_PI / 3) * 10, cos(angle - M_PI / 3) * 10);
        QPointF arrowHeadP2 = line().p1()
                              + QPointF(sin(angle - M_PI + M_PI / 3) * 10,
                                        cos(angle - M_PI + M_PI / 3) * 10);

        painter->drawPolygon(QPolygonF() << line().p1() << arrowHeadP1 << arrowHeadP2);
    }
};

#endif // ARROW_H
