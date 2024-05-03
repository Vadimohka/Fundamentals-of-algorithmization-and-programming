#include "figure.h"

Figure::Figure(QGraphicsObject *parent) : QGraphicsObject(parent)
{
    points = new QVector<QPointF>();
    brush = QBrush(Qt::gray);
}

QRectF Figure::boundingRect() const
{
    return QRectF();
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Figure::SetPenColor(QColor color)
{
    pen.setColor(color);
    update();
}

void Figure::SetBrushColor(QColor brush_color)
{
    brush.setColor(brush_color);
    update();
}

void Figure::SetCenter(QPointF prev_pos, QPointF curr_pos)
{
    qreal x_dist = abs(curr_pos.x() - prev_pos.x());
    qreal y_dist = abs(curr_pos.y() - prev_pos.y());
    if (curr_pos.x() < center.x())
    {
        center.setX(center.x() - x_dist);
    }
    else
    {
        center.setX(center.x() + x_dist);
    }

    if (curr_pos.y() < center.y())
    {
        center.setY(center.y() - y_dist);
    }
    else
    {
        center.setY(center.y() + y_dist);
    }
}

void Figure::CorrectCorners(QPointF first_point, QPointF second_point)
{
    x_side = abs(points->at(0).x() - points->at(1).x());
    y_side = abs(points->at(0).y() - points->at(1).y());

    if (points->at(1).x() < points->at(0).x() && points->at(1).y() < points->at(0).y())
    {
        top_left = points->at(1);
        bottom_right = points->at(0);
    }
    else if (points->at(1).x() > points->at(0).x() && points->at(1).y() < points->at(0).y())
    {
        top_left.setX(points->at(0).x());
        top_left.setY(points->at(0).y() - y_side);
        bottom_right.setX(points->at(1).x());
        bottom_right.setY(points->at(1).y() + y_side);
    }
    else if (points->at(1).x() < points->at(0).x() && points->at(1).y() > points->at(0).y())
    {
        top_left.setX(points->at(0).x() - x_side);
        top_left.setY(points->at(0).y());
        bottom_right.setX(points->at(1).x() + x_side);
        bottom_right.setY(points->at(1).y());
    }
    else
    {
        top_left = points->at(0);
        bottom_right = points->at(1);
    }
}

QPointF Figure::GetCenter()
{
    return mapToScene(center);
}

qreal Figure::GetPerim()
{
    return perim;
}

qreal Figure::GetSquare()
{
    return square;
}

void Figure::SetInfo(qreal mult)
{
    perim *= mult;
    square *= mult;
}

