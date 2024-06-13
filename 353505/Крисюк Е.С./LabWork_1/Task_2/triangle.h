#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "all_shapes.h"
#include <QGraphicsPolygonItem>

class Triangle : public QGraphicsPolygonItem, All_shapes
{
public:
    Triangle(qreal, qreal, qreal , QGraphicsItem* parent = nullptr);
    QPointF Left_up_point;
    QPointF Right_down_point;
    QPointF Left_down_point;


    QPointF Current_Left_up_point;
    QPointF Current_Right_down_point;
    QPointF Current_Left_down_point;

    qreal width;
    QPoint Centre_of_mass;
    QPolygonF triangle;

    QLineEdit* line_of_X;
    QLineEdit* line_of_Y;
    QLineEdit* line_of_Square;
    QLineEdit* line_of_Perimetr;

    QEvent::Type mousePressType;


    QPointF current_Mouse_Pos;
    QPointF delta;


protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);

private:
    QPointF Mouse_last_pos;

};

#endif // TRIANGLE_H
