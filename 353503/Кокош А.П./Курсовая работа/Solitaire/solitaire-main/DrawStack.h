
#pragma once

#include <QObject>
#include "CardStack.h"
#include "MyCardHBL.h"
#include "MyClickLbl.h"

// The draw stack is the stack where new cards can be acquired from
// Acts like a circular buffer of cards
class DrawStack : public CardStack
{
    Q_OBJECT

public:
    // Default constructor
    DrawStack(QWidget* parent = nullptr);

public:
    //~ Begin CCardStack interface
    virtual void removeCard(MyCard *cardToRemove) override;
    virtual bool canDropCard(MyCard* cardToDrop) override;
    virtual MyCard* getTopCard() override;
    //~ End CCardCard interface

    // Returns the hbox layout
    QHBoxLayout* getHBoxLayout();

    // When the undo Button is clicked and the last move was recycling the drawstack
    void undo(MyCard* card = nullptr);

public slots:
    void showNextCard();

private:
    // Box layout to display the cards
    MyCardHBL* hbox;
    QHBoxLayout* boxLayout;

    // Holds the index of the current visible card
    int currentCard = -1;

    // Label that represents the unflipped drawStack but needs no logic
    MyClickLbl *drawStackPlaceholder;

    // The pixmap of the card back and empty drawStack placeholder
    QPixmap cardBackPixmap;
    QPixmap emptyDrawStackPixmap;

    // Adds a new card to the UI
    void addCardToUi();

    // Removes the last card from the UI
    void removeCardFromUi();
};


