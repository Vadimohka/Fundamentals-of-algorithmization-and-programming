#include "circle.h"

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    center_x = x_up + x_down;
    center_y = y_up + y_down;
    if (is_t_vr){
        painter -> setBrush(Qt::blue);
        painter -> drawEllipse(center_vr_x, center_vr_y, 5, 5);
        painter -> setBrush(Qt::NoBrush);
    }
    painter -> translate(center_vr_x, center_vr_y);
    painter -> rotate(grad);
    painter -> translate(-center_vr_x, -center_vr_y);
    QPointF s(center_x, center_y);
    painter -> drawEllipse(s, 100 * scale, 100 * scale);
    per = 2 * pi * 100 * scale;
    pl = pi * 10000 * scale * scale;
}
