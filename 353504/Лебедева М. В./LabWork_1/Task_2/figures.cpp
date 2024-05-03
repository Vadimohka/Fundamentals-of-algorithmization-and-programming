#include "figures.h"

Figures::Figures()
{

}

QRectF Figures::boundingRect() const
{
    return QRectF(-500,-500,1000,1000);
}

float Figures::getScale()
{
    return scale;
}

QPoint Figures::getCenter()
{
    return QPoint(this->x(), this->y());
}

bool Figures::getItem()
{
    return Flag;
}

void Figures::getSize()
{
    if(this->getItem())
    {
        scale += 0.01;
    }
    else
    {
        scale -= 0.01;
        if(scale < 0)
        {
            scale=0.01;
        }
    }

    this->setScale(scale);
}


void Figures::setItem(bool flag)
{
    Flag=flag;
}

void Figures::move_up()
{
    this->setPos(this->x(), this->y() - 2);
    if(this->y()<-360)
    {
        this->setPos(this->x(), -360);
    }
}

void Figures::move_down()
{
    this->setPos(this->x(), this->y() + 2);
    if(this->y()>440)
    {
        this->setPos(this->x(), 440);
    }
}

void Figures::move_left()
{
    this->setPos(this->x() - 2 , this->y());
    if(this->x()<-1040)
    {
        this->setPos(-1040, this->y());
    }
}

void Figures::move_right()
{
    this->setPos(this->x() + 2, this->y());
    if(this->x()>1050)
    {
        this->setPos(1050, this->y());
    }
}

void Figures::rotate_right()
{
    ++angle;
    this->setRotation(angle);
}
void Figures::rotate_left()
{
    --angle;
    this->setRotation(angle);
}

void Figures::move()
{
    QPoint dif = mouseMoveNow - mouseMovePress;//разница между текущей позицией мыши и позицией мыши в момент нажатия
    for (auto &point: points)
    {
        point += dif;
    }
    mouseMovePress = mouseMoveNow;
}

void Figures::mousePressing(QMouseEvent *me)
{
    mousePress = me->pos();
    mouseNow = me->pos();
}

void Figures::mouseMovePressing(QMouseEvent *me)
{
    mouseMovePress = me->pos();
}

void Figures::mouseMoving(QMouseEvent *me)
{
    mouseNow = me->pos();
}

void Figures::mouseMoveMoving(QMouseEvent *me)
{
    mouseMoveNow = me->pos();
    move();
}

float Figures::area()
{
    return 0;
}

float Figures::perimeter()
{
    return 0;
}

void Figures::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

void Figures::rotate(int degree)
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
