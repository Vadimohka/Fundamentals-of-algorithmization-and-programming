
#include "DrawStack.h"
#include "Main.h"
#include "MyCardVBL.h"
#include <QDebug>

DrawStack::DrawStack(QWidget *parent)
    : CardStack(parent)
{
    // Create the dummy vbox layout with zero spacing, so they get overlayed
    hbox = new MyCardHBL(20, this);

    // Create the boxLayout that contains the playholder and the cards
    boxLayout = new QHBoxLayout();

    // Set the space between the cards
    boxLayout->setSpacing(10);

    // Assign and scale the needed tiles to the pixmap variables
    QPixmap* cardBackTile = new QPixmap(":/assets/card_back.png");
    cardBackPixmap = cardBackTile->scaled(MyCard::getCardScreenSize().width(),
                                          MyCard::getCardScreenSize().height(),
                                          Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation);
    QPixmap placeholderTilset = QPixmap(":/assets/card_placeholders.png");
    QPixmap placeholderTile = placeholderTilset.copy(4 * MyCard::cardTileSize.width(),
                                                     0,
                                                     MyCard::cardTileSize.width(),
                                                     MyCard::cardTileSize.height());
    emptyDrawStackPixmap = placeholderTile.scaled(MyCard::getCardScreenSize().width(),
                                                  MyCard::getCardScreenSize().height(),
                                                  Qt::KeepAspectRatio,
                                                  Qt::SmoothTransformation);

    // Create a QLabel that represents the drawStack but needs no logic
    drawStackPlaceholder = new MyClickLbl(this);
    drawStackPlaceholder->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    drawStackPlaceholder->setPixmap(cardBackPixmap);

    // Add the playeholder and the cards to the boxLayout
    boxLayout->addWidget(drawStackPlaceholder);
    boxLayout->addWidget(this);

    // Connect the clicked event with the showNextCard function
    QObject::connect(drawStackPlaceholder, &MyClickLbl::clicked, this, &DrawStack::showNextCard);
}

void DrawStack::removeCard(MyCard *cardToRemove)
{
    // Call the superclasses' removeCard
    CardStack::removeCard(cardToRemove);

    // Remove the card from the UI
    removeCardFromUi();
}

bool DrawStack::canDropCard(MyCard *cardToDrop)
{
    Q_UNUSED(cardToDrop);

    // Adding a card to the drawStack is not possible, due to that, this method is not necessary
    qDebug() << "nothing happens";

    return false;
}

MyCard *DrawStack::getTopCard()
{
    // Return the current top card
    return getCards()[currentCard];
}

void DrawStack::addCardToUi()
{
    // When the Boxlayout shows already 3 cards, the last one is removed, so that a new one can be displayed
    if(hbox->count() == 3 && getNumCards() > 3)
    {
        hbox->removeItem(hbox->itemAt(0));
        getCards()[currentCard+3]->setVisible(false);
    }

    // The following card is added to the boxlayout and set to visible
    hbox->addWidget(getCards()[currentCard]);
    getCards()[currentCard]->setVisible(true);

    // Interaction with the added card should be possible, with the former front card impossible (only if there is a former card)
    getCards()[currentCard]->setCanInteract(true);
    if(currentCard < getNumCards()-1)
       getCards()[currentCard+1]->setCanInteract(false);

    // Additionally, if it is the last card of the stack or if there is no card left, the placeholder displays the empty tile
    if(currentCard == 0 || getNumCards()-1 == 0)
        drawStackPlaceholder->setPixmap(emptyDrawStackPixmap);
}

void DrawStack::removeCardFromUi()
{
    // Remove the card from the layout which is the first one
    if(hbox->itemAt(2))
        hbox->removeItem(hbox->itemAt(2));
    else if(hbox->itemAt(1))
        hbox->removeItem(hbox->itemAt(1));
    else
        hbox->removeItem(hbox->itemAt(0));

    // The next card should be interactable, if there is one
    if(currentCard <= getNumCards()-1)
    {
        getCards()[currentCard]->setCanInteract(true);

        // When a card is removed, the last third card in the stack will be displayed, if existent
        if(currentCard + 2 <= getNumCards()-1)
        {
            hbox->push_back(getCards()[currentCard+2]);
            getCards()[currentCard+2]->setVisible(true);
        }
    }
}

void DrawStack::showNextCard()
{
    // The cards that shouldn't be displayed have to be invisible, even if the card is removed from
    // the layout (the card is still in the background of the layout)
    // If there are cards left on the stack, the variable "currentCard" is decremented
    if(currentCard > 0)
    {
        --currentCard;
        addCardToUi();
    }
    else if(currentCard == 0)
    {
        // CurrentCard = 0 means, that the stack is empty, so the drawStack gets recycled
        drawStackPlaceholder->setPixmap(cardBackPixmap);

        // Recycling the draw stack changes the score
        Main::get()->getGameInstance()->addScore(ScoreAttributes::RECYCLING_DRAW_PILE);

        // Iterating over the remaining cards and setting them to invisible and not interactable
        for(int i = 0; i < hbox->getItemCount(); ++i)
        {
            getCards()[currentCard + i]->setCanInteract(false);
            getCards()[currentCard + i]->setVisible(false);
        }

        hbox->clear();

        // Decrementing currentCard again, so that we don't jump in the same condition next time
        --currentCard;
    }
    // Otherwise, the currentCard is set to the topCard again, the first card is set to visible and caninteract
    else if(getNumCards() > 0)
    {
        currentCard = getNumCards()-1;
        addCardToUi();
    }

    // Register a new transaction that we drew a card
    Transaction t;
    t.type = Transaction::ETransactionType::DrawFromDrawStack;
    t.stack1 = this;

    Main::get()->getGameInstance()->addTransaction(t);

    // Drawing a card counts as a move
    Main::get()->getGameWindow()->incrementMove();
}

void DrawStack::undo(MyCard *card)
{
    // If a card has to be readded to the drawstack
    if(card)
    {
       insertCardAt(currentCard, card);
       addCardToUi();
    }
    else
    {
        // If the recycling has to be undone:
        if (currentCard == -1)
        {
            // TODO: Beautify
            currentCard = 2;
            addCardToUi();
            currentCard = 1;
            addCardToUi();
            currentCard = 0;
            addCardToUi();
            drawStackPlaceholder->setPixmap(cardBackPixmap);
        }
        else
        {
            getCards()[currentCard]->setVisible(false);
            ++currentCard;
            removeCardFromUi();
        }
    }
}

QHBoxLayout *DrawStack::getHBoxLayout()
{
    return boxLayout;
}
