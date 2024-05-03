#include "figure.h"

Figure::Figure() {
    //tempFigure=0;
}

QRectF Figure::boundingRect() const
{
    return QRectF(-500,-500,1000,1000);
}

bool Figure::getItem()
{
    return Flag;
}

void Figure::setItem(bool flag)
{
    Flag=flag;
}

void Figure::changeK(){
    k+=1;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        startPoint = event->pos();
    }
    update();
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        endPoint = event->pos();
        update();
        points.push_back(event->pos());
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        endPoint = event->pos();
        update();
    }
}

float Figure::perimeter()
{
    return 0;
}

float Figure::area(){
    return 0;
}
