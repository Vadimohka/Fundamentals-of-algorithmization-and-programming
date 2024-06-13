#ifndef CIRCLE_H
#define CIRCLE_H

#include "all_shapes.h"

class Circle : public QGraphicsEllipseItem, public All_shapes
{
public:
    Circle(qreal, qreal, qreal,QGraphicsItem* parent = nullptr);
    QPointF Left_up_point;
    qreal diametr;
    QPoint Centre_of_mass;

    QLineEdit* line_of_X;
    QLineEdit* line_of_Y;
    QLineEdit* line_of_Square;
    QLineEdit* line_of_Perimetr;

    QPointF current_Mouse_Pos;
    QPointF delta;

    QEvent::Type mousePressType;

    QGraphicsEllipseItem* ellipse;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

private:
    QPointF Mouse_last_pos;

};

#endif // CIRCLE_H
