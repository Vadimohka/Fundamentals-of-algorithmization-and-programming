#ifndef STAR_5_H
#define STAR_5_H


#include "all_shapes.h"

class Star_5 : public QGraphicsPolygonItem, public All_shapes
{
public:
    Star_5(qreal, qreal, qreal , QGraphicsItem* parent = nullptr);

    QPointF Left_up_point;
    QPointF Right_Centre_point;
    QPointF Left_Centre_point;
    QPointF Right_down_point;
    QPointF Left_down_point;

    QPointF Current_Left_up_point;
    QPointF Current_Right_Centre_point;
    QPointF Current_Left_Centre_point;
    QPointF Current_Right_down_point;
    QPointF Current_Left_down_point;

    qreal radius;
    qreal width;
    QPoint Centre_of_mass;
    QPolygonF star_5;

    qreal Small_Width;

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


#endif // STAR_5_H
