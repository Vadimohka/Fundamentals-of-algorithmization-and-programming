
#pragma once

#include <QObject>
#include <QWidget>
#include "CardStack.h"
#include "MyCardVBL.h"

// The holding stack is a card stack which renders the cards below each other
class HoldingStack : public CardStack
{
    Q_OBJECT

public:
    // Constructor
    HoldingStack(QWidget* parent = nullptr);

public:
    static int CardOffsetInStack;

    static int CardOffsetInStackSmaller;

    static int StackCollapseNumCards;

public:
    virtual void addCard(MyCard *cardToAdd) override;
    virtual void removeCard(MyCard *cardToRemove) override;
    virtual bool canDropCard(MyCard *cardToDrop) override;

    // Flips the next top card
    void flipNextCard();

    // Returns all cards above a specific card
    QList<MyCard*> getCardsAbove(MyCard* card);

private:
    // Overwritten drag'n'drop events
    void dragEnterEvent(QDragEnterEvent* ev) override;
    void dropEvent(QDropEvent* ev) override;

    // Checks (and potentially performs) whether to collapse this stack or not
    void checkCollapseStack();

private:
    // The vertical box layout to use for the holding stack
    MyCardVBL *vbox;
};
