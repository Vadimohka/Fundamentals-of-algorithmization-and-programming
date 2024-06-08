#include "castle.h"

Castle::Castle(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)

{

   setPixmap(QPixmap(":images/hcastle.png"));
}

int Castle::type() const
{
    return Type;
}
