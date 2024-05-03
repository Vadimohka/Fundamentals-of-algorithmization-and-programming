#include "star.h"

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon pol;
    center_x = x_up + x_down;
    center_y = y_up + y_down;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
    x1 = center_x + scale * ((x_up + x_down + rad_max * cos(0)) - center_x);
    y1 = center_y + scale * ((y_up + y_down + rad_max * sin(0)) - center_y);
    x2 = center_x + scale * ((x_up + x_down + rad_min * cos(pi / n)) - center_x);
    y2 = center_y + scale * ((y_up + y_down + rad_min * sin(pi / n)) - center_y);
    x3 = center_x + scale * ((x_up + x_down + rad_max * cos(2 * pi / n)) - center_x);
    y3 = center_y + scale * ((y_up + y_down + rad_max * sin(2 * pi / n)) - center_y);
    x4 = center_x + scale * ((x_up + x_down + rad_min * cos(2 * pi / n + pi / n)) - center_x);
    y4 = center_y + scale * ((y_up + y_down + rad_min * sin(2 * pi / n + pi / n)) - center_y);
    x5 = center_x + scale * ((x_up + x_down + rad_max * cos(4 * pi / n)) - center_x);
    y5 = center_y + scale * ((y_up + y_down + rad_max * sin(4 * pi / n)) - center_y);
    x6 = center_x + scale * ((x_up + x_down + rad_min * cos(4 * pi / n + pi / n)) - center_x);
    y6 = center_y + scale * ((y_up + y_down + rad_min * sin(4 * pi / n + pi / n)) - center_y);
    x7 = center_x + scale * ((x_up + x_down + rad_max * cos(6 * pi / n)) - center_x);
    y7 = center_y + scale * ((y_up + y_down + rad_max * sin(6 * pi / n)) - center_y);
    x8 = center_x + scale * ((x_up + x_down + rad_min * cos(6 * pi / n + pi / n)) - center_x);
    y8 = center_y + scale * ((y_up + y_down + rad_min * sin(6 * pi / n + pi / n)) - center_y);
    x9 = center_x + scale * ((x_up + x_down + rad_max * cos(8 * pi / n)) - center_x);
    y9 = center_y + scale * ((y_up + y_down + rad_max * sin(8 * pi / n)) - center_y);
    x10 = center_x + scale * ((x_up + x_down + rad_min * cos(8 * pi / n + pi / n)) - center_x);
    y10 = center_y + scale * ((y_up + y_down + rad_min * sin(8 * pi / n + pi / n)) - center_y);
    if (n == 6 || n == 8){
        x11 = center_x + scale * ((x_up + x_down + rad_max * cos(10 * pi / n)) - center_x);
        y11 = center_y + scale * ((y_up + y_down + rad_max * sin(10 * pi / n)) - center_y);
        x12 = center_x + scale * ((x_up + x_down + rad_min * cos(10 * pi / n + pi / n)) - center_x);
        y12 = center_y + scale * ((y_up + y_down + rad_min * sin(10 * pi / n + pi / n)) - center_y);
    }
    if (n == 8){
        x13 = center_x + scale * ((x_up + x_down + rad_max * cos(12 * pi / n)) - center_x);
        y13 = center_y + scale * ((y_up + y_down + rad_max * sin(12 * pi / n)) - center_y);
        x14 = center_x + scale * ((x_up + x_down + rad_min * cos(12 * pi / n + pi / n)) - center_x);
        y14 = center_y + scale * ((y_up + y_down + rad_min * sin(12 * pi / n + pi / n)) - center_y);
        x15 = center_x + scale * ((x_up + x_down + rad_max * cos(14 * pi / n)) - center_x);
        y15 = center_y + scale * ((y_up + y_down + rad_max * sin(14 * pi / n)) - center_y);
        x16 = center_x + scale * ((x_up + x_down + rad_min * cos(14 * pi / n + pi / n)) - center_x);
        y16 = center_y + scale * ((y_up + y_down + rad_min * sin(14 * pi / n + pi / n)) - center_y);
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
    pol << QPoint(x1, y1);
    pol << QPoint(x2, y2);
    pol << QPoint(x3, y3);
    pol << QPoint(x4, y4);
    pol << QPoint(x5, y5);
    pol << QPoint(x6, y6);
    pol << QPoint(x7, y7);
    pol << QPoint(x8, y8);
    pol << QPoint(x9, y9);
    pol << QPoint(x10, y10);
    if (n == 6 || n == 8){
        pol << QPoint(x11, y11);
        pol << QPoint(x12, y12);
    }
    if (n == 8){
        pol << QPoint(x13, y13);
        pol << QPoint(x14, y14);
        pol << QPoint(x15, y15);
        pol << QPoint(x16, y16);
    }
    painter -> drawPolygon(pol);
    if (n == 5){
        per = 10 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        pl = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y6 + x6 * y7 + x7 * y8 + x8 * y9 + x9 * y10 + x10 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x6 * y5 - x7 * y6 - x8 * y7 - x9 * y8 - x10 * y9 - x1 * y10);
    }
    if (n == 6){
        per = 12 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        pl = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y6 + x6 * y7 + x7 * y8 + x8 * y9 + x9 * y10 + x10 * y11 + x11 * y12 + x12 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x6 * y5 - x7 * y6 - x8 * y7 - x9 * y8 - x10 * y9 - x11 * y10 - x12 * y11 - x1 * y12);
    }
    if (n == 8){
        per = 16 * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        pl = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y6 + x6 * y7 + x7 * y8 + x8 * y9 + x9 * y10 + x10 * y11 + x11 * y12 + x12 * y13 + x13 * y14 + x14 * y15 + x15 * y16 + x16 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x6 * y5 - x7 * y6 - x8 * y7 - x9 * y8 - x10 * y9 - x11 * y10 - x12 * y11 - x13 * y12 - x14 * y13 - x15 * y14 - x16 * y15 - x1 * y16);
    }
}
