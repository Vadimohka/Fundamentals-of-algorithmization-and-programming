#ifndef DECK_H
#define DECK_H

#include<cards.h>
#include<QVector>
#include<QDebug>
#include<QtGlobal>
#include<QRandomGenerator>

class Deck
{
private:

    QVector<Card> cards;

    int top_index;

public:

    explicit Deck();

    void initializeCards();

    void shuffleCards();

    Card currentCard();

};

#endif // DECK_H
