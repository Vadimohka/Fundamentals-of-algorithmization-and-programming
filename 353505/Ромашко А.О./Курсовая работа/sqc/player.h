#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

class Player : public Person
{
    Q_OBJECT
public:
    Player( int hpp,
           int dama,
           int defe
           );
    ~Player();
    Deck *setDeck(){return this->deck;}
    Deck *deck;
    // enum typesOfEffects{
    //     Poizon,
    //     Incineration, //испепеление
    //     Burning,      //выжигание
    //     Debility      //бессилие
    // };
    enum typeOfAttack{
        defaulTA,
        effectTA
    };
    enum typesOfCard{
        AttackT,
        DefenceT,
        HealtPointT,
        EnergyT,
        EffectT,
        CombinationT
    };
    void getCoordinate(int X,int Y, int W, int H);
    Card *setTempAttack(){return this->tempAttack;}
    Energy* setEnergy(){return this->energy;}
    void upHp(int a){this->hp->addHP(a);}
    int money;
    void getEnergy(int v){ this->energy->doNull();this->energy->upEnergy(v);}

private:
    void Died();

    int x,y,w,h;

    Health *hp;
    QPixmap *picture;
    QImage *image;
    Damage *damage;
    Defence *defence;
    Energy *energy;


    Card *tempAttack;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void attack(Card *);
    void GameOver();
    void updateView();
    void enemyMove();
    void signalDeckUpdate();
public slots:
    void takeAttack(Card *c);
    void takeAttackCard(Card *c);
    void updateViewSlot();

};

#endif // PLAYER_H
