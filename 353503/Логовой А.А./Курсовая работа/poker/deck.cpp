#include "deck.h"
#include <const_numbers.h>

Deck::Deck() = default;

void Deck::initializeCards() {
    for (int suit = Card::Spades, i = 1; suit <= Card::Clubs; ++suit) {
        for (int value = static_cast<int>(Value::Two); value <= static_cast<int>(Value::Ace); ++value) {
            Card card(static_cast<Card::suit>(suit), static_cast<Value>(value));
            QString images = "/home/blaugranas/poker_qt/card_images/PNG-cards-1.3/";
            QPixmap image;
            if (!image.load(images + QString::number(i) + ".png")) {
                qDebug() << "Error to create a picture of the cards";
            }
            QPixmap scaledImage = image.scaled(QSize(PICTURE_SIZE,PICTURE_SIZE), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            card.setImage(scaledImage);
            cards.push_back(card);
            ++i;
        }
    }
    top_index = cards.size();
}

void Deck::shuffleCards()
{
    for(auto & card : cards)
    {
        qSwap(card, cards[QRandomGenerator::global()->bounded(0, cards.size())]);
    }
    top_index = cards.size();
}

Card Deck::currentCard()
{
    top_index--;
    return cards[top_index];
}
