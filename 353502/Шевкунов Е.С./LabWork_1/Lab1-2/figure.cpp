#include "figure.h"

Figure::Figure(QWidget *parent)
    : QWidget{parent}
{
    center = {0, 0};
    ID = {0,0};
    is_selected = false;

    former_pos = {0, 0};
    former_rotation = 0;
    former_scale = 0;
}


//**********************************************


void Figure::move(QPointF d)
{
    this->setPos(former_pos + d);
    repaint();
}

void Figure::rotate(QPointF d)
{
    this->setRotation(former_rotation + d.x());
    repaint();
}

void Figure::scale(QPointF d)
{
    this->setScale(former_scale + d.x() / 100);
    if (this->QGraphicsItem::scale() <= 0)
    {
        this->setScale(0.1);
    }
    repaint();
}

void Figure::setPreviousParameters()
{
    this->setPos(former_pos);
    this->setRotation(former_rotation);
    this->setScale(former_scale);
}

void Figure::updateParameters()
{
    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();
}


//**********************************************

QPair<short,short> Figure::getID()
{
    return ID;
}

void Figure::slotIsSelected()
{
    connect(this, SIGNAL(myID(QPair<short,short>)), parent(), SLOT(setSelectedFigure(QPair<short,short>)));
    emit myID(ID);
    is_selected = true;
    this->repaint();
}

void Figure::slotNotSelected()
{
    is_selected = false;
    this->repaint();
}
