#include "rectangle.h"

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon pol;
    center_x = x_up + x_down;
    center_y = y_up + y_down;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
    x1 = center_x + scale * (300 + x_up + x_down + isk_x - center_x);
    y1 = center_y + scale * (150 + y_up + y_down + isk_y - center_y);
    x2 = center_x + scale * (-300 + x_up + x_down - isk_x - center_x);
    y2 = center_y + scale * (150 + y_up + y_down + isk_y - center_y);
    x3 = center_x + scale * (-300 + x_up + x_down - isk_x - center_x);
    y3 = center_y + scale * (-150 + y_up + y_down - isk_y - center_y);
    x4 = center_x + scale * (300 + x_up + x_down + isk_x - center_x);
    y4 = center_y + scale * (-150 + y_up + y_down - isk_y - center_y);
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
    pol << QPoint(x1, y1) <<  QPoint(x2, y2) <<  QPoint(x3, y3) << QPoint(x4, y4);
    painter -> drawPolygon(pol);
    pl = (x1 - (x2)) * (y2 - (y3));
    per = 2 * (x1 - (x2)) + 2 * (y2 - (y3));
}
