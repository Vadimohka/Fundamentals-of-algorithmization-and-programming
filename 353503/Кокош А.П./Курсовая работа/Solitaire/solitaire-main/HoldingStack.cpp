
#include "HoldingStack.h"
#include "Main.h"
#include <QDebug>
#include <QImage>
#include <QMimeData>

// Set the static variables
int HoldingStack::CardOffsetInStack = 45;
int HoldingStack::CardOffsetInStackSmaller = 24;
int HoldingStack::StackCollapseNumCards = 9;

HoldingStack::HoldingStack(QWidget *parent)
    : CardStack(parent)
{
    // Create the vbox layout
    vbox = new MyCardVBL(CardOffsetInStack, this);
}

void HoldingStack::addCard(MyCard *cardToAdd)
{
    // Add the card to our vbox
    vbox->addWidget(cardToAdd);

    // Call the superclasses' addCard
    CardStack::addCard(cardToAdd);

    // Check whether we should collapse the stack
    this->checkCollapseStack();
}

void HoldingStack::removeCard(MyCard *cardToRemove)
{
    // Call the superclasses' removeCard
    CardStack::removeCard(cardToRemove);

    // Remove the card from our vbox
    vbox->removeWidget(cardToRemove);

    // A card was removed from this stack, so flip the next card if the next card is not flipped yet
    // The condition is necessary, otherwise already flipped cards would play the anim when clicking
    // on multiple cards. Also make sure there IS a top card
    if(getTopCard() && !getTopCard()->getFlipped())
    {
        flipNextCard();
    }

    // Check whether we should collapse the stack
    this->checkCollapseStack();
}

bool HoldingStack::canDropCard(MyCard *cardToDrop)
{
    // If we have any card
    if (this->getNumCards() > 0)
    {
        // Get the top card on the stack
        MyCard *topCard = this->getTopCard();

        // First, check if it's the opposite color
        bool isTopCardRed = topCard->isRed();
        bool isCardToDropRed = cardToDrop->isRed();

        if ((isTopCardRed && isCardToDropRed) || (!isTopCardRed && !isCardToDropRed))
        {
            // No same colors
            return false;
        }

        // Now, check if the value of this card is one lower than the current top card
        if (cardToDrop->getOverallValue() != topCard->getOverallValue() - 1)
        {
            // No lower value
            return false;
        }

        // Also, don't allow dropping kings on aces in holding stacks
        if (topCard->getType() == CardType::Ace && cardToDrop->getType() == CardType::King) {
            // No aces on kings
            return false;
        }

        // If all of these conditions passed, we allow it
        return true;
    }
    else
    {
        // No card, then only a king can start a new stack
        if (cardToDrop->getType() != CardType::King)
            return false;
    }

    // If we don't have any card on this stack, we can always drop
    return true;
}

void HoldingStack::flipNextCard()
{
    // Make sure we have any card
    if (getNumCards() == 0) return;

    // Flip the top card
    getTopCard()->requestCardFlip(true);

    // Emit that the stack changed
    emit onCardsChanged();
}

QList<MyCard *> HoldingStack::getCardsAbove(MyCard *card)
{
    // Will contain the cards
    QList<MyCard *> cardsList;

    // Get the index of this card
    int index = getCards().indexOf(card);

    // Make sure the index is valid (= card is in the stack)
    if (index < 0) {
        qDebug() << "Cannot find " << card->toString();
        return cardsList;
    }

    // Iterate over all cards in the region index..numCards
    for (int i = index; i < getNumCards(); i++)
    {
        // Add it to the list
        cardsList.push_back(getCards()[i]);
    }

    return cardsList;
}

void HoldingStack::dragEnterEvent(QDragEnterEvent *ev)
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

void HoldingStack::dropEvent(QDropEvent *ev)
{
    // Deserialize the payload from the MIME data
    QByteArray mimeData = ev->mimeData()->data("application/x-solitaire-dnd");
    QDataStream mimeDataStream(&mimeData, QIODevice::ReadOnly);
    CardDndPayload* payload;
    mimeDataStream >> payload;

    // Make sure the payload is valid
    if (!payload) return;

    // Make sure there is a card
    if (payload->cards.length() <= 0) return;

    // Now, this drop event will only be called if we can actually drop here, the actual
    // decision happens in dragEnterEvent

    // Call the method to change the score in the GameInstance with the suitable enum
    if (dynamic_cast<FinalStack *>(payload->cards[0]->getCardStack()) != NULL) {
        // If the card comes from a FinalStack
        Main::get()->getGameInstance()->addScore(ScoreAttributes::FOUNDATION_TO_TABLEAU);
    } else if (dynamic_cast<DrawStack *>(payload->cards[0]->getCardStack()) != NULL) {
        // If the card comes from the DrawStack
        Main::get()->getGameInstance()->addScore(ScoreAttributes::WASTE_PILE_TO_TABLEAU);
    } else if (dynamic_cast<FinalStack *>(payload->cards[0]->getCardStack()) != NULL) {
        // If the card comes from the DrawStack
        Main::get()->getGameInstance()->addScore(ScoreAttributes::FOUNDATION_TO_TABLEAU);
    }

    // Register a new transaction
    Transaction t;
    t.type = Transaction::ETransactionType::StackToStack;
    t.stack1 = payload->cards.front()->getCardStack();
    t.stack2 = this;
    t.cards = payload->cards;
    t.scoreBefore = Main::get()->getGameInstance()->getScore();
    t.flipCardBefore = payload->cards[0]->getCardStack()->getTopCard()->getFlipped();

    // Go through all cards we're about to drop
    for (MyCard *card : payload->cards) {
        // Remove the card from the stack it's in right now, if any
        if (card->getCardStack())
        {
            card->getCardStack()->removeCard(card);
        }
        // Add it to this stack
        this->addCard(card);
    }

    // Store the score after evaluation in the transaction
    t.scoreAfter = Main::get()->getGameInstance()->getScore();

    // Add the transaction
    Main::get()->getGameInstance()->addTransaction(t);

    // Increment the amount of steps
    Main::get()->getGameWindow()->incrementMove();
}

void HoldingStack::checkCollapseStack()
{
    // Check whether we should collapse
    if (this->getNumCards() >= HoldingStack::StackCollapseNumCards) {
        // Set the spacing to smaller
        vbox->setSpacingWithAnimation(HoldingStack::CardOffsetInStackSmaller);
    } else {
        // Set the spacing back to normal
        vbox->setSpacingWithAnimation(HoldingStack::CardOffsetInStack);
    }
}
