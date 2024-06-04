#ifndef PERSON_H
#define PERSON_H

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QString>

#include "deck.h"
#include "artefacts.h"

class Person: public QGraphicsObject
{
    Q_OBJECT
public:
    Person();
    enum typesOfEffects{
        Poizon,
        Incineration, //испепеление
        Burning,      //выжигание
        Debility      //бессилие
    };
    enum typeOfAttack{
        defaulTA,
        effectTA
    };
    void getCoordinate(int x,int y, int w, int h);
private:
    int x,y,w,h;

    Health *hp;
    QPixmap *picture;
    QImage *image;
    Damage *damage;
    Defence *defence;
    Energy *energy;
protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
    void updateView();
};

#endif // PERSON_H
