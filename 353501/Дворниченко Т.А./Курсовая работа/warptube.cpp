#include "warptube.h"

WarpTube::WarpTube(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)

{

   setPixmap(QPixmap(":images/Warp.png"));
}

int WarpTube::type() const
{
    return Type;
}
