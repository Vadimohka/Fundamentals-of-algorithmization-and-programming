
#pragma once

#include <QObject>
#include <QWidget>
#include <QDragEnterEvent>
#include "MyCard.h"

// Implements a card stack which can hold multiple cards
class CardStack : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    CardStack(QWidget *parent = nullptr);

public:
    // Adds a new card to the stack
    virtual void addCard(MyCard *cardToAdd);

    // Inserts a card at a specific position
    void insertCardAt(int insertAt, MyCard *cardToInsert);

    // Removes a card from the stack
    virtual void removeCard(MyCard *cardToRemove);

    // Removes a card identified by the card index from the stack
    void removeCardAt(int cardIndexToRemove);

    // Returns the number of cards on this stack
    int getNumCards() const;

    // Gets the current topmost card
    virtual MyCard *getTopCard();

    // Checks whether a given card can be dropped on this stack
    virtual bool canDropCard(MyCard *cardToDrop);

    // Returns the cards of this card stack
    QList<MyCard *> getCards() { return cards; }

    // Returns the index of a specified card in the card stack
    int getIndexOfCard(MyCard *card);

public slots:
    // Internally handles when the cards on this stack changed
    virtual void handleCardsChanged();

signals:
    // When the cards on this stack changed
    void onCardsChanged();

private:
    // Holds the cards for this stack
    QList<MyCard *> cards;
};
