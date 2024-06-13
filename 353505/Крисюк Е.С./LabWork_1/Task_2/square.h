#ifndef SQUARE_H
#define SQUARE_H

#include "all_shapes.h"

class Square : public QGraphicsRectItem, public All_shapes
{
public:
    Square(qreal, qreal, qreal,QGraphicsItem* parent = nullptr);
    QPointF Left_up_point;
    QPointF Current_Left_up_point;

    qreal height;
    QPoint Centre_of_mass;

    QLineEdit* line_of_X;
    QLineEdit* line_of_Y;
    QLineEdit* line_of_Square;
    QLineEdit* line_of_Perimetr;

    QPointF current_Mouse_Pos;
    QPointF delta;

    QEvent::Type mousePressType;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

private:
    QPointF Mouse_last_pos;

};

#endif // SQUARE_H
