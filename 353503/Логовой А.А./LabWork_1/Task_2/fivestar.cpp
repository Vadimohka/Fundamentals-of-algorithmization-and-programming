#include "fivestar.h"

FiveStar::FiveStar(int x1,int y1, int x2, int y2){

    rect = QRectF(x1,y1,x2,y2);
    show_borders = false;
}

FiveStar::~FiveStar()
{

}
void FiveStar::drawFigure(QPainter *painter){
    QPolygon polygon;
    double centerX = rect.x() + rect.width() / 2;
    double centerY = rect.y() + rect.height() / 2;
    double radius = qMin(rect.width(), rect.height()) / 2;
    double angle = 360.0 / 5;
    for (int i = 0; i < 5; ++i) {
        double theta = (angle * i - 90) * M_PI / 180.0;
        double dx = centerX + radius * cos(theta);
        double dy = centerY + radius * sin(theta);
        polygon << QPoint(dx, dy);
    }
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->drawPolygon(polygon);
}

