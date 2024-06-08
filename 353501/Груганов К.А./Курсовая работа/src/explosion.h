#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QtWidgets>
#include "gameobj.h"
class Explosion : public GameObj
{
public:
    Explosion();

private:
    QPixmap m_explosion;
};

#endif // EXPLOSION_H
