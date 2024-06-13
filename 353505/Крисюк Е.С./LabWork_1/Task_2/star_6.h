#ifndef STAR_6_H
#define STAR_6_H


#include "all_shapes.h"

class Star_6 : public QGraphicsPolygonItem, public All_shapes
{
public:
    Star_6(qreal, qreal, qreal , QGraphicsItem* parent = nullptr);

    QPointF Up_point;
    QPointF Right_up_point;
    QPointF Left_up_point;
    QPointF Right_down_point;
    QPointF Left_down_point;
    QPointF Down_point;
    QPointF Centre;

    QPointF Current_Up_point;
    QPointF Current_Right_up_point;
    QPointF Current_Left_up_point;
    QPointF Current_Right_down_point;
    QPointF Current_Left_down_point;
    QPointF Current_Down_point;
    QPointF Current_Centre;

    qreal radius;
    qreal width;
    QPoint Centre_of_mass;
    QPolygonF star_6;


    QLineEdit* line_of_X;
    QLineEdit* line_of_Y;
    QLineEdit* line_of_Square;
    QLineEdit* line_of_Perimetr;

    QPointF current_Mouse_Pos;
    QPointF delta;
    QEvent::Type mousePressType;


protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);

private:
    QPointF Mouse_last_pos;

};


#endif // STAR_6_H
