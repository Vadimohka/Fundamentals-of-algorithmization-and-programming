#include "rectangle.h"
#include <QWidget>

Rectangle::Rectangle(QGraphicsRectItem *parent):QGraphicsRectItem (parent)
{
}

Rectangle::~Rectangle()
{
}



void Rectangle::dviz(int dy)
{
 this->setPos(this->x(),dy);
}

