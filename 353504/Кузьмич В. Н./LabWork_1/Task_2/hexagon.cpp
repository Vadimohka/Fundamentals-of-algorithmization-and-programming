#include "hexagon.h"

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon pol;
    center_x = x_up + x_down;
    center_y = y_up + y_down;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
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
    x1 = center_x + scale * ((x_up + x_down + isk_x + 200 * cos(0)) - center_x);
    y1 = center_y + scale * ((y_up + y_down + 200 * sin(0)) - center_y);
    x2 = center_x + scale * ((x_up + x_down + 200 * cos(2 * pi / 6)) - center_x);
    y2 = center_y + scale * ((y_up + y_down + isk_y + 200 * sin(2 * pi / 6)) - center_y);
    x3 = center_x + scale * ((x_up + x_down + 200 * cos(4 * pi / 6)) - center_x);
    y3 = center_y + scale * ((y_up + y_down + isk_y + 200 * sin(4 * pi / 6)) - center_y);
    x4 = center_x + scale * ((x_up + x_down - isk_x + 200 * cos(6 * pi / 6)) - center_x);
    y4 = center_y + scale * ((y_up + y_down + 200 * sin(6 * pi / 6)) - center_y);
    x5 = center_x + scale * ((x_up + x_down + 200 * cos(8 * pi / 6)) - center_x);
    y5 = center_y + scale * ((y_up + y_down - isk_y + 200 * sin(8 * pi / 6)) - center_y);
    x6= center_x + scale * ((x_up + x_down + 200 * cos(10 * pi / 6)) - center_x);
    y6 = center_y + scale * ((y_up + y_down - isk_y + 200 * sin(10 * pi / 6)) - center_y);
    pol << QPoint(x1, y1);
    pol << QPoint(x2, y2);
    pol << QPoint(x3, y3);
    pol << QPoint(x4, y4);
    pol << QPoint(x5, y5);
    pol << QPoint(x6, y6);
    painter -> drawPolygon(pol);
    pl = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y6 + x6 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x6 * y5 - x1 * y6);
    per = 4 * sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)) + 2 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
