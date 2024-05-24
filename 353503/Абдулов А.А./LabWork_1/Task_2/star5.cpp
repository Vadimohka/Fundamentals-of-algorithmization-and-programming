#include "star5.h"
#include<QApplication>
#include<QCoreApplication>

Star5::Star5(){

}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPoint points[11];

    for (int i = 0; i < 5; i++){
        QPoint p_out, p_in;
        p_out = {
            int(0 - radius2 * sin(2 * M_PI / 5 * i)),
            int(0 - radius1 * cos(2 * M_PI / 5 * i))
        };

        p_in = {
            int(0 - (double) radius2 / 2 * sin(2 * M_PI / 5 * i + M_PI / 5)),
            int(0 - (double) radius1 / 2 * cos(2 * M_PI / 5 * i + M_PI / 5))
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    points[10].rx() = points[0].rx();
    points[10].ry() = points[0].ry();

    for (int i = 0; i < 10;++i){
        painter->drawLine(points[i].rx(),points[i].ry(), points[i + 1].rx(),points[i + 1].ry());
    }
}

float Star5::area(){
    return this->getScale() * this->getScale() * (M_PI * radius1 * radius1 + (M_PI * radius2 * radius2 - M_PI * radius1 * radius1) / 3);
}

float Star5::perimeter(){
    return radius1 * count + radius2 * count * this->getScale();
}
