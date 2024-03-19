#include "truck.h"

void truck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter -> drawRect(per_x, -553, 295, 150);
    painter -> setBrush(Qt::yellow);
    painter -> drawRect(per_x - 580, 225, 70, 30);
    painter -> drawRect(per_x - 490, 225, 70, 30);
    painter -> drawRect(per_x - 400, 225, 70, 30);
    painter -> setBrush(Qt::blue);
    painter -> drawEllipse(per_x - 555, 269, 60, 60);
    painter -> drawEllipse(per_x - 395, 269, 60, 60);

    painter -> translate(-525 + per_x, 298);
    painter -> rotate(grad);
    painter -> translate(525 - per_x, -298);

    painter -> drawLine(-555 + per_x, 298, -495 + per_x, 298);
    painter -> drawLine(-525 + per_x, 328, -525 + per_x, 268);

    painter -> translate(-525 + per_x, 298);
    painter -> rotate(-grad);
    painter -> translate(525 - per_x, -298);

    painter -> translate(-365 + per_x, 298);
    painter -> rotate(grad);
    painter -> translate(365 - per_x, -298);

    painter -> drawLine(-395 + per_x, 298, -335 + per_x, 298);
    painter -> drawLine(-365 + per_x, 328, -365 + per_x, 268);
}

