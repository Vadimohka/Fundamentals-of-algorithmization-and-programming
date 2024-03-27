#include "custom.h"

Custom::Custom()
{
    this->ptsCount=0;
    this->drawMode=1;
}

void Custom::mouseMoving(QMouseEvent *p)
{
    if (p->buttons() & Qt::LeftButton) {
        posMove = p->pos();
        pts.push_back(posMove);
        ptsCount = pts.size();
    } else if (p->buttons() & Qt::RightButton) {
        Shape::mouseMoving(p);
    }
}

void Custom::paint(QPainter *p)
{

    QPen pen = p->pen();
    pen.setWidth(penWidth);
    pen.setColor(color);
    p->setPen(pen);

    if(drawMode==1){

        for (int i = 0; i < ptsCount; i++) {
            p->drawEllipse(pts[i].x(), pts[i].y(), penWidth, penWidth);
        }
    }
    else if(drawMode==2){
        if (ptsCount > 1) {
            for (int i = 0; i < ptsCount - 1; i++) {
                p->drawLine(pts[i], pts[i + 1]);
            }
        }
    }
}

void Custom::clearPoints()
{
    pts.clear();
    ptsCount=0;
}


Custom::~Custom()
{

}
