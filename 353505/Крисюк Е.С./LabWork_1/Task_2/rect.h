#ifndef RECT_H
#define RECT_H

#include "all_shapes.h"
#include <QGraphicsRectItem>

class Rect : public QGraphicsRectItem, public All_shapes
{

public:
    Rect(qreal, qreal, qreal , qreal, QGraphicsItem* parent = nullptr);

    QPointF Left_up_point;
    QPointF Current_Left_up_point;

    QPointF temp;

    qreal width;
    qreal height;
    QPointF Centre_of_mass;

    QLineEdit* line_of_X;
    QLineEdit* line_of_Y;
    QLineEdit* line_of_Square;
    QLineEdit* line_of_Perimetr;

    QPointF current_Mouse_Pos;
    QPointF delta;

    QEvent::Type mousePressType;


private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

private:
    QPointF Mouse_last_pos;
};

#endif // RECT_H
