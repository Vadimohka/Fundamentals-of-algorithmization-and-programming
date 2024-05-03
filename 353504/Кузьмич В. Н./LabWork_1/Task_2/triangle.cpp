#include "triangle.h"

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPolygon pol;
    center_x = (x1 + x2 + x3) / 3;
    center_y = (y1 + y2 + y3) / 3;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
    x1 = center_x + scale * (300 + x_up + x_down + t1_tri - center_x);
    y1 = center_y + scale * (200 + y_up + y_down - center_y);
    x2 = center_x + scale * (-300 + x_up + x_down - t2_tri - center_x);
    y2 = center_y + scale * (200 + y_up + y_down - center_y);
    x3 = center_x + scale * (x_up + x_down - center_x);
    y3 = center_y + scale * (-250 + y_up + y_down - t3_tri - center_y);
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
    painter -> drawPolygon(pol);
    s1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    s2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    s3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    pol_pl = (s1 + s2 + s3) / 2;
    pl = sqrt(pol_pl * (pol_pl - s1) * (pol_pl - s2) * (pol_pl - s3));
    per = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) + sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
}
