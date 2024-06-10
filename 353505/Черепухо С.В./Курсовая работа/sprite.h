#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QPainter>

class Sprite
{
public:
    Sprite();

    QString name, script;
    QPixmap *image;
    int x = 0, y = 0, w, h, id = 0;

    bool doDraw = false;

    void draw(QPainter *painter);
    void setCords(int x, int y);
};

#endif // SPRITE_H
