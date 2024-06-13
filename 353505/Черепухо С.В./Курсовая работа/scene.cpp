#include "scene.h"

Scene::Scene()
{
    background = new QPixmap(580, 380);
    background->fill(QColor("white"));
    dSprites = new QPixmap(580, 380);
    dSprites->fill(QColor(0, 0, 0, 0));
}

void Scene::draw(QPainter *painter)
{
    painter->drawRect(9, 99, 582, 381);
    painter->drawPixmap(10, 100, *background);

    dSprites->fill(QColor(0, 0, 0, 0));
    QPainter dSpritesPainter(dSprites);

    if(!sprites.isEmpty())
    {
        for(int i = 0; i < sprites.size(); i++)
        {
            if(sprites[i].doDraw)
                dSpritesPainter.drawPixmap(sprites[i].x, sprites[i].y, *sprites[i].image);
        }
    }

    painter->drawPixmap(10, 100, *dSprites);
}
