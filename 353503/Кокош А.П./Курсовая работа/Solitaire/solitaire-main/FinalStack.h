
#pragma once

#include <QObject>
#include "CardStack.h"
#include "MyCardVBL.h"

// Represents one of the four final card stacks at the top of the game,
// where cards get dropped off until the stack is full
class FinalStack : public CardStack
{
    Q_OBJECT

public:
    // How many cards to render on a final stack to avoid glitches with the shadows
    static int NumCardsToRender;

public:
    // Constructor
    FinalStack(QWidget* parent = nullptr, CardSymbol symbol = CardSymbol::Heart);

public:
    //~ Begin CardStack interface
    virtual void addCard(MyCard *cardToAdd) override;
    virtual void removeCard(MyCard *cardToRemove) override;
    virtual bool canDropCard(MyCard* cardToDrop) override;
    virtual void handleCardsChanged() override;
    //~ End CardCard interface

private:
    // Overwritten drag'n'drop events
    void dragEnterEvent(QDragEnterEvent* ev) override;
    void dropEvent(QDropEvent* ev) override;

private:
    // The symbol this final stack allows
    CardSymbol stackSymbol;

    // Box layout to display the cards
    MyCardVBL* vbox;
};

