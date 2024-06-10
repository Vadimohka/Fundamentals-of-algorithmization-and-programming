#ifndef SCENE_H
#define SCENE_H

#include <QPainter>
#include "sprite.h"

class Scene
{
public:
    Scene();

    QPixmap *background, *dSprites;

    void draw(QPainter *painter);

    QVector <Sprite> sprites;
};

#endif // SCENE_H
