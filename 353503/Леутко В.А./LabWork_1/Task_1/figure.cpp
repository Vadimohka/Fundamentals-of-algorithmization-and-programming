#include "figure.h"

figure::figure()
{
    filled = false;
}

figure::~figure()
{

}

QRectF figure::boundingRect() const
{
    return QRectF (-w/2-20,-h/2-20,w+40,h+40);
}

void figure::Output()
{
    out_area->setText(QString::number(now_area));
    out_perimeter->setText(QString::number(now_perimeter));
    out_centerX->setText(QString::number(this->pos().rx()));
    out_centerY->setText(QString::number(this->pos().ry()));
    out_angle->setText(QString::number(now_ang));
}

void figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (Tgravity->text()=="Choose object to move" || btn_fill->text()=="No")
    {
        Tgravity->setText("Set center of gravity:");
        btn_fill->setText("fill");
        filled = true;
        this -> setPos(centergravity_x->text().toInt(),centergravity_y->text().toInt());
        this-> clearFocus();
        this-> ungrabMouse();
    }
    else
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void figure::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Right) ang += rotate_angle->text().toInt();
    else
        if (event->key()==Qt::Key_Left) ang -= rotate_angle->text().toInt();
        else
            if (event->key()==Qt::Key_Down)
            {
                size-=change_size->text().toInt()/100.;
                now_area=area*size*size;
            }
            else
                if (event->key()==Qt::Key_Up)
                {
                    size+=change_size->text().toInt()/100.;
                    now_area=area*size*size;
                }
                else
                    if (event->key()==Qt::Key_R)
                    {
                        ang = 0;
                        size = 1;
                        now_area = area;
                        now_perimeter = perimeter;
                    }
}
