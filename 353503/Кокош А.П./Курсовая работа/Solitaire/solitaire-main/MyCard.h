
#pragma once

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QVariantAnimation>

// Forward declaration
class CardStack;

// Card symbol enumeration
enum CardSymbol { Heart, Spade, Diamond, Club };

// Card type enumeration
enum CardType { Number = 0, Jack = 9, Queen = 10, King = 11, Ace = 12 };

// Payload data used for drag-and-drop operations
struct CardDndPayload
{
public:
    // A list of cards which were dragged
    QList<class MyCard *> cards;

    // Whether this was a single card or a card stack
    bool isSingleCard;

    friend QDataStream& operator<<(QDataStream& s, const CardDndPayload* payloadPtr);
    friend QDataStream& operator>>(QDataStream& s, CardDndPayload*& payloadPtr);
};

// Implements a playing card
class MyCard : public QLabel
{
    Q_OBJECT

public:
    // The size of a card on the tileset
    static QSize cardTileSize;

    // The factor by which the cardTileSize get's multiplied for screen size
    static float cardSizeFactor;

public:
    // Constructor
    MyCard(QWidget *parent = nullptr,
           const CardSymbol symbol = CardSymbol::Heart,
           const CardType type = CardType::Number,
           const int numberValue = 0);

public:
    // Get the actual screen size of a card in pixels
    static QSize getCardScreenSize();

    // Returns the symbol of this card
    CardSymbol getSymbol() const { return cardSymbol; }

    // Returns the type of this card
    CardType getType() const { return cardType; }

    // Returns the number value of this card (if card type == ECardType::Number)
    int getNumberValue() const
    {
        return cardNumberValue;
    }

    // Returns whether this card is red (true) or black (false)
    bool isRed() const
    {
        // Hearts and Diamonds are red
        return (cardSymbol == CardSymbol::Heart || cardSymbol == CardSymbol::Diamond);
    }

    // Returns the overall "value" of the card - being 2..10 for numbers, 11 for jack, 12 for queen, 13 for king, 14 for ace
    int getOverallValue() const
    {
        // If the card type is a number, just return the number value
        if (cardType == CardType::Number) {
            return cardNumberValue;
        } else {
            // We can convert the type enum to int, because we assigned custom integers to the enum. We have to add 2 though,
            // as the enum doesn't start counting at 2 (like the cards actually do)
            return ((int)cardType) + 2;
        }
    }

    // Sets whether this card is flipped or not (true = you see the image, false = you see the back)
    void setCardFlipped(bool shouldFlip);

    // Returns whether this card is flipped
    bool getFlipped()
    {
        return isFlipped;
    }

    // Requests a card flip WITH ANIMATION. Not the same as setCardFlipped
    void requestCardFlip(bool shouldFlip);

    // Sets the stack this card is in
    void setCardStack(CardStack *newStack);

    // Returns the stack this card is on
    CardStack *getCardStack() { return currentStack; }

    // Converts this card to a human readable string
    QString toString();

    // Sets whether the player can interact with this card (click it, drag it, etc.)
    void setCanInteract(bool canInteract);

private:
    // Overwritten mouse events
    void mousePressEvent(QMouseEvent* ev) override;
    void mouseReleaseEvent(QMouseEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);

private:
    // This card's symbol and type
    CardSymbol cardSymbol;
    CardType cardType;
    int cardNumberValue;

    // Whether this card is flipped
    bool isFlipped;

    // Whether this card can be dragged or interacted with
    bool canInteract;

    // The pixmap of the card front and back
    QPixmap* cardFrontPixmap;
    QPixmap* cardBackPixmap;
    QPixmap currentPixmap;

    // The stack the card is in right now
    CardStack *currentStack;

    // The position where we started clicking so we know whether it
    // was a drag request or not
    QPoint dragStartPos;

    // Animations
    QPropertyAnimation* hoverAnim;
    QVariantAnimation* flipAnim;
    QPropertyAnimation* cannotMoveAnim;

    // Whether this card was clicked and should automatically move to another position
    CardStack *stackBeforeHoverAnim;
};
