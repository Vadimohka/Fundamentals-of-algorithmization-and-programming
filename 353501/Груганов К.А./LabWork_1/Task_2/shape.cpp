#include "shape.h"

Shape::Shape()
{

}

Shape::~Shape()
{

}

void Shape::updateInfo() {
    Area();
    Perimeter();
}

void Shape::Center()
{
    QPointF displacement = QPointF(600, 450) - center;
    for (QPointF& a : pts) {
        a += displacement;
    }
    center={600,450};
    rotationMatrix(0,{0,0});
    if(currScale !=1){
    currScale = 1;
    resize();
    }
    updateInfo();
}

void Shape::mouseMoving(QMouseEvent *p)
{
    QPointF displacement = p->pos() - posMove;
    for (QPointF& a : pts) {
        a += displacement;
    }

    posMove = p->pos();

}

void Shape::paint(QPainter *p)
{

    QPolygonF pol;
    for(int i=0;i<ptsCount;i++){
        pol<<pts[i];
    }
    QPainterPath path;
    path.addPolygon(pol);
    QColor fill = Qt::darkRed;
    p->fillPath(path,fill);
    p->drawPolygon(pol);
    updateInfo();
}

void Shape::resize()
    {
    for (int i = 0; i < ptsCount; i++) {
            pts[i] = center + (pts[i] - center) * currScale / prevScale;
    }
}

 void Shape::upScale()
    {
    prevScale = currScale;
    currScale*=1.01;
    resize();
    updateInfo();
    }

void Shape::downScale()
{
    prevScale=currScale;
    if(currScale>0.1){
        currScale/=1.01;}
    resize();
    updateInfo();
}
QPointF Shape::MassCenter()
{
    double sumX = 0;
    double sumY = 0;
    int n = ptsCount;
    for (int i = 0; i < n; i++) {
        sumX += pts[i].x();
        sumY += pts[i].y();
    }

    center.setX(sumX / n);
    center.setY(sumY / n);
    posMove = center;
    return center;
}

void Shape::rotateL(QPointF anchor)
{
    rotationMatrix(currAngle-1,anchor);
}

void Shape::rotateR(QPointF anchor)
{
    rotationMatrix(currAngle+1,anchor);

}

double Shape::Area()
    {
    area=0;
    area+= pts[pts.size()-1].x()*pts[0].y()-pts[0].x()*pts[pts.size()-1].y();
    for(int i=0;i<pts.size()-1;i++){
        area+=pts[i].x()*pts[i+1].y()-pts[i+1].x()*pts[i].y();
    }
    area=abs(area)/2;
    return area;
}

double Shape::Perimeter()
{
    perimetr=0;
    for(int i=0;i<pts.size()-1;i++){
        perimetr+=sqrt((pts[i+1].x()-pts[i].x())*(pts[i+1].x()-pts[i].x())+
                         (pts[i+1].y()-pts[i].y())*(pts[i+1].y()-pts[i].y()));
    }
    perimetr+=sqrt((pts[pts.size()-1].x()-pts[0].x())*(pts[pts.size()-1].x()-pts[0].x())+
                     (pts[pts.size()-1].y()-pts[0].y())*(pts[pts.size()-1].y()-pts[0].y()));
    return perimetr;
};


void Shape::rotationMatrix(int newAngle, QPointF anchor)
{
    double angle = (newAngle - currAngle) * 3.1415 / 180;
    posMove=MassCenter();
    currAngle = newAngle;
    if (!anchor.isNull()) {
        for (int i = 0; i < ptsCount; i++) {
            double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
            double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
            pts[i].setX(dx);
            pts[i].setY(dy);
        }
    } else {
        for (int i = 0; i < ptsCount; i++) {
            double dx = center.x() + (pts[i].x() - center.x()) * cos(angle) - (pts[i].y() - center.y()) * sin(angle);
            double dy = center.y() + (pts[i].x() - center.x()) * sin(angle) + (pts[i].y() - center.y()) * cos(angle);
            pts[i].setX(dx);
            pts[i].setY(dy);
        }
    }
}
