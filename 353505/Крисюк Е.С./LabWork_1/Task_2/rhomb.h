#ifndef RHOMB_H
#define RHOMB_H

#include "all_shapes.h"
#include <QGraphicsPolygonItem>

class Rhomb : public QGraphicsPolygonItem, public All_shapes
{
public:
    Rhomb(qreal, qreal, qreal , qreal, QGraphicsItem* parent = nullptr);
    QPointF Left_up_point;
    QPointF Right_down_point;
    QPointF Left_down_point;
    QPointF Right_up_point;


    QPointF Current_Left_up_point;
    QPointF Current_Right_down_point;
    QPointF Current_Left_down_point;
    QPointF Current_Right_up_point;

    qreal width;
    qreal angle;
    QPoint Centre_of_mass;
    QPolygonF rhomb;

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

#endif // RHOMB_H
