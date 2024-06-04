#ifndef CARD_H
#define CARD_H

#include <QGraphicsObject>
#include <QPixmap>
#include <QImage>
#include <QPainter>

#include "CardCharHDDE.h"
#include "effects.h"

class Card : public QGraphicsObject
{
    Q_OBJECT
public:
    Card(QImage *i,
         Damage *dam,
         Defence *def,
         Health *h,
         Energy *e);
    ~Card();
    Damage *setDamage();
    int setIDamage(){return this->damage->damage();}
    Defence *setDefence();
    int setIDefence(){return this->defence->setDef();}
    Health *setHp();
    int setIHP(){return this->hp->setHP();}
    Energy *setEnergy();
    int setIEnergy(){return this->energyCost->setEnergy();}
    Energy *setEnergyCost();
    int setIEnergyCost(){return this->energyCost->setEnergy();}
    void getDamage(Damage *damag);
    void getDefence(Defence *def);
    void getHp(Health *health);
    void getEnergy(Energy *en);
    void getEnergyCost(Energy *en);
    void getEnergyCost(int en);
    void getImage(QImage* im);
    void getCoordinate(int x,int y, int w, int h);
    void getType(int t);
    int setType();
    void getPlayerEnergy(Energy* p){this->PlayerEnergy=p;}

    enum typesOfCard{
        AttackT,
        DefenceT,
        HealtPointT,
        EnergyT,
        EffectT,
        CombinationT
    };
private:
    int activityPressEvent;
    int type;
    QPixmap *picture;
    QImage *image;
    Damage *damage;
    Defence *defence;
    Health *hp;
    Energy *energy;
    Energy *energyCost;
    Energy *PlayerEnergy;
    int x,y,w,h;
    QPixmap *p;
    QPixmap *p1;
    QPixmap *p2;
    QPixmap *p3;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    void signalClickType(Card *card);
    // void updateDeck();
};

#endif // CARD_H
