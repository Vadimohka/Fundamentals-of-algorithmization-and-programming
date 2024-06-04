
#include "CardStack.h"
#include <QDebug>

CardStack::CardStack(QWidget *parent)
    : QWidget(parent)
{
    // Connect the event
    QObject::connect(this, &CardStack::onCardsChanged, this, &CardStack::handleCardsChanged);

    // Enable dropping elements
    setAcceptDrops(true);
}

void CardStack::addCard(MyCard *cardToAdd)
{
    // Make sure the card is valid
    if (cardToAdd)
    {
        // Add it to the list
        cards.push_back(cardToAdd);

        // Set the card's stack to this one
        cardToAdd->setCardStack(this);

        // Notify the handler
        emit onCardsChanged();
    }
}

void CardStack::insertCardAt(int insertAt, MyCard* cardToInsert)
{
    // Make sure the card is valid
    if (cardToInsert)
    {
        // Add it to the list
        cards.insert(insertAt, cardToInsert);

        // Set the card's stack to this one
        cardToInsert->setCardStack(this);

        // Notify the handler
        emit onCardsChanged();
    }
}

void CardStack::removeCard(MyCard *cardToRemove)
{
    // Make sure the card is valid
    if (cardToRemove)
    {
        // Remove it from the list
        cards.removeOne(cardToRemove);

        // Clear the card's stack
        cardToRemove->setCardStack(nullptr);

        // Notify the handler
        emit onCardsChanged();
    }
}

void CardStack::removeCardAt(int cardIndexToRemove)
{
    // Make sure the index is valid
    if (cardIndexToRemove >= 0 && cardIndexToRemove < cards.length())
    {
        // Remove it from the list
        removeCard(cards[cardIndexToRemove]);
    }
}

int CardStack::getNumCards() const
{
    // Return the length of the cards list
    return cards.length();
}

MyCard* CardStack::getTopCard()
{
    // Make sure we have cards
    if (cards.length() > 0)
    {
        // Return the last card in the list, as that will be the topmost card
        return cards.last();
    }
    else
    {
        // Return nothing
        return nullptr;
    }
}

bool CardStack::canDropCard(MyCard* cardToDrop)
{
    Q_UNUSED(cardToDrop);

    // By default, allow dropping
    return true;
}

int CardStack::getIndexOfCard(MyCard* card)
{
    // Find the card
    return cards.indexOf(card);
}

void CardStack::handleCardsChanged()
{

}
