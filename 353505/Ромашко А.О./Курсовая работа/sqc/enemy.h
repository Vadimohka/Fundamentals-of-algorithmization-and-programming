#ifndef ENEMY_H
#define ENEMY_H

#include "person.h"

class Enemy : public Person
{
    Q_OBJECT
public:
    Enemy(int hpp,
          int dama,
          int defe,
          int t);
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
    ~Enemy();
    void getPixmap(QPixmap *p){this->picture=p;}

private:
    int type;
    int x,y,w,h;

    Health *hp;
    QPixmap *picture;
    QImage *image;
    Damage *damage;
    Defence *defence;
    Energy *energy;
    void Died();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void attack(Card *);
    void updateView();
    void Win();

public slots:
    void takeAttack(Card *c);
    void Attack();

};

#endif // ENEMY_H
