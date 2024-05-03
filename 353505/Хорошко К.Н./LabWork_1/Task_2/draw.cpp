#include "draw.h"

Draw::Draw(QPointF point, QObject *parent) :
    Figure(point, parent)
{
    Q_UNUSED(point)
}


void Draw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if (points.size() == 0){
    points << QPointF(startPoint().x(), startPoint().y());
    m_shape = QPainterPath();
    m_shape.lineTo(startPoint().x(), startPoint().y());
    }
    else
    {
    m_shape.lineTo(points[points.size()-1]);
    painter->setPen(QPen(Qt::black, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    for (int i = 1; i < points.size(); ++i) {
        painter->drawLine(points[i - 1], points[i]);
    }
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);

}
