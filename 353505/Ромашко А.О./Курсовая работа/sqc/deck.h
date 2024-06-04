#ifndef DECK_H
#define DECK_H

#include <QGraphicsScene>
#include <QVector>
#include <QImage>
#include <QGraphicsSceneMouseEvent>
#include <algorithm>
#include <random>

#include "card.h"

class Deck : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = nullptr);
    ~Deck();
    void addCard(Card *card);
    Card *subCard(int i);

    enum typesOfCard{
        AttackT,
        DefenceT,
        HealtPointT,
        EnergyT,
        EffectT,
        CombinationT
    };
    void addCardsToGame();
    bool isEnabled(){return activity;}
    void setEnabled(bool f){activity = f;}
    void getPlayerEnergy(Energy *e){this->PlayerEnergy=e;}
    QVector <Card*> *setNoUsedDeck(){return &this->noUsedCards;}

private:
    QVector <Card*> deck;
    QVector <Card*> activeCards;
    QVector <Card*> usedCards;
    QVector <Card*> noUsedCards;
    Card* getCardFromA(QVector <Card*> A, Card *card);
    Energy *PlayerEnergy;
    void findCard(Card *find);
    int numOfActiveCard=0;
    void usedToNoUsed();
    void noUsedToActive();
    void initTenCardsInDeck();
    Card* GenerateCard(int num);
    void addToActiveScene();

    bool activity=1;
    void shuffleDeck();
    void ashuffleDeck();
    bool activeCardsOnScene=0;
public slots:
    void clickToCard(Card *card);
    void PlayerDeckUpdateSlot();
signals:
    void forUpdateView();
    void dropSignal(Card *card);

};

#endif // DECK_H
