#include "rhombus.h"

void rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon pol;
    center_x = x_up + x_down;
    center_y = y_up + y_down;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
    x1 =  x_up + x_down;
    y1 = center_y + scale * (200 + y_up + y_down + isk_y - center_y);
    x2 = center_x + scale * (100 + x_up + x_down + isk_x - center_x);
    y2 = y_up + y_down;
    x3 = x_up + x_down;
    y3 = center_y + scale * (-200 + y_up + y_down - isk_y - center_y);
    x4 = center_x + scale * (-100 + x_up + x_down - isk_x - center_x);
    y4 = y_up + y_down;
    if (is_t_vr){
    painter -> translate(center_vr_x, center_vr_y);
    painter -> rotate(grad);
    painter -> translate(-center_vr_x, -center_vr_y);
    }
    else{
    painter -> translate(center_x, center_y);
    painter -> rotate(grad);
    painter -> translate(-center_x, -center_y);
    }
    pol << QPoint(x1, y1);
    pol <<  QPoint(x2,y2);
    pol <<  QPoint(x3, y3);
    pol << QPoint(x4,y4);
    painter -> drawPolygon(pol);
    pl = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x1 * y4);
    per = 4 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

