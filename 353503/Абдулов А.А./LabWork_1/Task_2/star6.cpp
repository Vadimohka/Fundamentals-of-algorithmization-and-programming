#include "star6.h"

Star6::Star6(){

}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPoint points[12];

    for (int i = 0; i < 6; i++)
    {
        QPoint p_out, p_in;
        p_out = {
            int(0 - radius2 * sin(2 * M_PI / 6 * i)),
            int(0 - radius1 * cos(2 * M_PI / 6 * i))
        };

        p_in = {
            int(0 - (double) radius2 / 2 * sin(2 * M_PI / 6 * i + M_PI / 6)),
            int(0 - (double) radius1 / 2 * cos(2 * M_PI / 6 * i + M_PI / 6))
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    points[12].rx() = points[0].rx();
    points[12].ry() = points[0].ry();

    for (int i = 0; i < 12; ++i){
        painter->drawLine(points[i].rx(),points[i].ry(), points[i + 1].rx(),points[i + 1].ry());
    }
}

float Star6::area(){
    return this->getScale() * this->getScale() * (M_PI * radius1 * radius1 + (M_PI * radius2 * radius2 - M_PI * radius1 * radius1) / 5);
}

float Star6::perimeter(){
    return radius1 * count + radius2 * count * this->getScale();
}
