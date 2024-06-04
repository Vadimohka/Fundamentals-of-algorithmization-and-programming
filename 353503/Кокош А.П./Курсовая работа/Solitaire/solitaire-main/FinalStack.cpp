// Author: Annie Berend (5033782) - Jonathan Verbeek (5058288)
#include "FinalStack.h"
#include <QDebug>
#include "Main.h"
#include "MyCardVBL.h"

// Set the static variables
int FinalStack::NumCardsToRender = 5;

FinalStack::FinalStack(QWidget *parent, CardSymbol symbol)
    : CardStack(parent)
    , stackSymbol(symbol)
{
    // Cut out the placeholder image from the tileset
    int tilesetX = (int)symbol;
    tilesetX == 1 ? tilesetX = 2 : tilesetX == 2 ? tilesetX = 1 : 0;

    QPixmap placeholderTilset = QPixmap(":/assets/card_placeholders.png");
    QPixmap placeholderPixmap = placeholderTilset.copy(tilesetX * MyCard::cardTileSize.width(),
                                                       0,
                                                       MyCard::cardTileSize.width(),
                                                       MyCard::cardTileSize.height());

    // Create a new placeholder label with that image
    QLabel* placeholder = new QLabel(this);
    placeholder->setGeometry(0,
                             0,
                             MyCard::getCardScreenSize().width(),
                             MyCard::getCardScreenSize().height());
    placeholder->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    placeholder->setPixmap(placeholderPixmap.scaled(MyCard::getCardScreenSize().width(),
                                                    MyCard::getCardScreenSize().height(),
                                                    Qt::KeepAspectRatio,
                                                    Qt::SmoothTransformation));

    // This widget has always the size of a card
    this->setGeometry(0, 0, MyCard::cardTileSize.width(), MyCard::cardTileSize.height());

    // Create the dummy vbox layout with zero spacing, so they get overlayed
    vbox = new MyCardVBL(0, this);
}

void FinalStack::addCard(MyCard *cardToAdd)
{
    // Call the superclasses' addCard
    CardStack::addCard(cardToAdd);

    // Add it to the vbox
    vbox->addWidget(cardToAdd);
}

void FinalStack::removeCard(MyCard *cardToRemove)
{
    // We can only remove the top card
    if (cardToRemove != this->getTopCard()) return;

    // Call the superclasses' removeCard
    CardStack::removeCard(cardToRemove);

    // Remove it from the vbox
    vbox->removeWidget(cardToRemove);
}

bool FinalStack::canDropCard(MyCard *cardToDrop)
{
    // Check if the symbol is what we allow on this stack
    if (cardToDrop->getSymbol() != stackSymbol) return false;

    // Get the top card on the stack
    MyCard *topCard = this->getTopCard();

    // If we have any card
    if (topCard)
    {
        // If the top card is an Ace, the next allowed card is only a '2'
        if (topCard->getType() == CardType::Ace && cardToDrop->getNumberValue() == 2) return true;

        // Check whether the value of the card to drop is one higher than the current top card
        if (cardToDrop->getOverallValue() != topCard->getOverallValue() + 1) return false;
    }
    else
    {
        // When no card is on this stack, the first card to accept is only an Ace
        if (cardToDrop->getType() != CardType::Ace) return false;
    }

    // Allowed
    return true;
}

void FinalStack::handleCardsChanged()
{
    // Only show the last NumCardsToRender cards to avoid weird overlapping shadows
    for (int i = 0; i < getCards().length(); i++)
    {
        if (i >= getCards().length() - FinalStack::NumCardsToRender) {
            getCards()[i]->show();
        } else {
            getCards()[i]->hide();
        }
    }
}

void FinalStack::dragEnterEvent(QDragEnterEvent *ev)
{
    // We can extract the card to drop from the source of the drag event (as we started
    // the d'n'd operation in the card)
    MyCard *cardToDrop = reinterpret_cast<MyCard *>(ev->source());

    // Make sure the card is valid
    if (!cardToDrop) return;

    // Check if we could drop the card here
    if (this->canDropCard(cardToDrop))
    {
        // Accept the drag operation
        ev->acceptProposedAction();
    }
}

void FinalStack::dropEvent(QDropEvent *ev)
{
    // We can extract the card to drop from the source of the drag event (as we started
    // the d'n'd operation in the card)
    MyCard *cardToDrop = reinterpret_cast<MyCard *>(ev->source());

    // Make sure the card is valid
    if (!cardToDrop) return;

    // Now, this drop event will only be called if we can actually drop here, the actual
    // decision happens in dragEnterEvent

    Transaction t;
    t.type = Transaction::ETransactionType::StackToStack;
    t.stack1 = cardToDrop->getCardStack();
    t.stack2 = this;
    QList<MyCard *> temp;
    temp.append(cardToDrop);
    t.cards = temp;
    t.scoreBefore = Main::get()->getGameInstance()->getScore();
    t.flipCardBefore = cardToDrop->getCardStack()->getTopCard()->getFlipped();

    // Call the Scoring in the GameInstance with the suitable enum
    if (dynamic_cast<DrawStack*>(cardToDrop->getCardStack()) != NULL)
    {
        // If the card comes from a DrawStack
        Main::get()->getGameInstance()->addScore(ScoreAttributes::WASTE_PILE_TO_FOUNDATION);
    }
    else if(dynamic_cast<HoldingStack*>(cardToDrop->getCardStack()) != NULL)
    {
        // If the card comes from a HoldingStack
        Main::get()->getGameInstance()->addScore(ScoreAttributes::TABLEAU_TO_FOUNDATION);
    }

    // Store the score after evaluation in the transaction
    t.scoreAfter = Main::get()->getGameInstance()->getScore();

    // Add the transaction
    Main::get()->getGameInstance()->addTransaction(t);

    // Increment the amount of steps
    Main::get()->getGameWindow()->incrementMove();

    // Remove the card from the stack it's in right now, if it's in any stack
    if (cardToDrop->getCardStack())
    {
        cardToDrop->getCardStack()->removeCard(cardToDrop);
    }

    // Add it to this stack
    this->addCard(cardToDrop);
}
