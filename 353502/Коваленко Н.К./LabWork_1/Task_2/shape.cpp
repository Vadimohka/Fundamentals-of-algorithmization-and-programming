#include "shape.h"

Shape::Shape()
{

}

QRectF Shape::boundingRect() const //положение фигуры на поле
{
    return QRectF(-500,-500,1000,1000);
}

float Shape::getScale()
{
    return scale;
}

QPoint Shape::getCenter()
{
    return QPoint(this->x(), this->y());
}

bool Shape::getItem()
{
    return Flag;
}

void Shape::setItem(bool flag)
{
    Flag=flag;
}

void Shape::getSize() //размер фигур + / -
{
    if(this->getItem())
    {
        scale += 0.02;
    }
    else
    {
        scale -= 0.02;
        if(scale < 0)
        {
            scale=0.02;
        }
    }

    this->setScale(scale);
}

void Shape::move_up()
{
    this->setPos(this->x(), this->y() - 4);
    if(this->y()<-360)
    {
        this->setPos(this->x(), -360);
    }
}

void Shape::move_down()
{
    this->setPos(this->x(), this->y() + 4);
    if(this->y()>440)
    {
        this->setPos(this->x(), 440);
    }
}

void Shape::move_left()
{
    this->setPos(this->x() - 4 , this->y());
    if(this->x()<-1040)
    {
        this->setPos(-1040, this->y());
    }
}

void Shape::move_right()
{
    this->setPos(this->x() + 4, this->y());
    if(this->x()>1050)
    {
        this->setPos(1050, this->y());
    }
}

void Shape::rotate_right() //поворот фигур
{
    angle+=3;
    this->setRotation(angle);
}
void Shape::rotate_left()
{
    angle-=3;
    this->setRotation(angle);
}

void Shape::move() //передвижение линий мышью
{
    QPoint dif = mouseMoveNow - mouseMovePress;
    for (auto &point: points)
    {
        point += dif;
    }
    mouseMovePress = mouseMoveNow;
}

void Shape::mousePressing(QMouseEvent *me) //отслеживание действий мыши для рисования линий
{
    mousePress = me->pos();
    mouseNow = me->pos();
}

void Shape::mouseMovePressing(QMouseEvent *me)
{
    mouseMovePress = me->pos();
}

void Shape::mouseMoving(QMouseEvent *me)
{
    mouseNow = me->pos();
    setPoints(me);
}

float Shape::area()
{
    return 0;
}

float Shape::perimeter()
{
    return 0;
}

void Shape::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

void Shape::setPoints(QMouseEvent *)
{

}

void Shape::mouseMoveMoving(QMouseEvent *me)
{
    mouseMoveNow = me->pos();
    move();
}

void Shape::rotate(int degree)
{
    double angle = (double) (degree - lastDegree) / 180 * M_PI;
    lastDegree = degree;
    for (auto &a: points)
    {
        int qx = int(center.x() + qCos(angle) * (a.x() - center.x()) - qSin(angle) * (a.y() - center.y()));
        int qy = int(center.y()  + qSin(angle) * (a.x() - center.x()) + qCos(angle) * (a.y() - center.y()));
        a = {qx, qy};
    }
}
