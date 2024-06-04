#include <QDebug>
#include "CardStack.h"
#include "FinalStack.h"
#include "GameWindow.h"
#include "HoldingStack.h"
#include "Main.h"
#include "MyGameLogic.h"

// Set the static variables
int MyGameLogic::MaxUndoSteps = 3;

MyGameLogic::MyGameLogic(QObject *parent)
    : QObject(parent)
{
    // Initially set up the game
    setUp();

    // Connection, when New Game menu item is pressed
    QObject::connect(Main::get()->getGameWindow(),
                     &GameWindow::resetGame,
                     this,
                     &MyGameLogic::restartGame);

    // Connection from score changing in Game with GameWindow
    QObject::connect(this,
                     &MyGameLogic::onScoreChanged,
                     Main::get()->getGameWindow(),
                     &GameWindow::updateScore);
}

void MyGameLogic::setUp()
{
    const CardSymbol symbolVector[] = {Club, Heart, Diamond, Spade};
    const CardType typeVector[] = {Jack, Queen, King, Ace};

    // Filling the deck initially
    for (CardSymbol symbol : symbolVector) {
        // Create all number cards
        for (int i = 2; i < 11; ++i)
        {
            MyCard *newCard = new MyCard(Main::get()->getGameWindow(), symbol, CardType::Number, i);
            deck.push_back(newCard);
        }

        // Create all special cards
        for (CardType type : typeVector) {
            MyCard* newCard = new MyCard(Main::get()->getGameWindow(), symbol, type, 0);
            deck.push_back(newCard);
        }
    }

    // Seed the random number generator and shuffle the carddeck
    std::srand(time(0));
    std::random_shuffle(deck.begin(), deck.end());

    // Clear the holding- and finalStacks before creating them is necessary for the "new game"-action
    holdingStacks.clear();
    finalStacks.clear();

    // Creation of the 4 final stacks, these are initially empty
    finalStacks.append(new FinalStack(Main::get()->getGameWindow(), CardSymbol::Heart));
    finalStacks.append(new FinalStack(Main::get()->getGameWindow(), CardSymbol::Diamond));
    finalStacks.append(new FinalStack(Main::get()->getGameWindow(), CardSymbol::Spade));
    finalStacks.append(new FinalStack(Main::get()->getGameWindow(), CardSymbol::Club));

    // Call the GameWindow to display the initial state of the finalStacks
    for(int i = 0; i < 4; ++i)
    {
        Main::get()->getGameWindow()->displayFinalStack(finalStacks[i], i);

        // Hook their onCardsChange signal so we can detect wins
        QObject::connect(finalStacks[i],
                         &FinalStack::onCardsChanged,
                         this,
                         &MyGameLogic::checkHasEnded);
    }

    // Create seven holding stacks and fill with cards
    for(int i = 0; i < 7; ++i)
    {
        // Add a new holding stack
        HoldingStack* newHoldingStack = new HoldingStack();
        holdingStacks.push_back(newHoldingStack);

        // Display the new holding stack
        Main::get()->getGameWindow()->displayHoldingStack(newHoldingStack, i);

        // Every n'th holding stack has n+1 cards
        for(int j = 0; j < i+1; ++j)
        {
            // Add the next card from the deck
            holdingStacks[i]->addCard(deck.front());
            // Flip the card if it's not the top card in the stack
            deck.front()->setCardFlipped(j >= i);

            // Remove it from the deck list
            deck.pop_front();
        }
    }

    // Create the drawStack and adding the left cards of the deck to it
    drawStack = new DrawStack(Main::get()->getGameWindow());

    for(int i = 0; i < deck.size(); ++i)
    {
        drawStack->addCard(deck[i]);
    }

    // Call the CGameWindow to display the initial state of the drawStack and clear the deck
    Main::get()->getGameWindow()->displayDrawStack(drawStack);
    deck.clear();

    // Clear the transaction buffer
    transactions.clear();
}

bool MyGameLogic::moveCard(MyCard *cardToDrop, CardStack *srcStack)
{
    // The found stack where we can add the card to
    CardStack* foundStack = nullptr;

    // We need a list, if the cardToDrop is not the topCard
    QList<MyCard*> cardsToMove;

    // Iterate over the final stacks and check if card can be dropped
    for (FinalStack* final : finalStacks)
    {
        // If the card fits on a final stack, it has to be the top card as only a single card can be dropped there
        if (final->canDropCard(cardToDrop) && cardToDrop == srcStack->getTopCard() && final != srcStack)
        {
            // Add the card to the cardsToMove list and assign the found stack
            cardsToMove.push_back(cardToDrop);
            foundStack = final;

            // Increment the amount of steps
            Main::get()->getGameWindow()->incrementMove();
            break;
        }
    }

    // If we didn't find a suitable stack yet
    if (!foundStack)
    {
        // Try to find a suitable holding stack
        for (HoldingStack* holding : holdingStacks)
        {
            // Can it be dropped?
            if (holding->canDropCard(cardToDrop) && holding != srcStack)
            {
                // Add it to the list and mark that we found it
                cardsToMove.push_back(cardToDrop);
                foundStack = holding;

                // If the source stack is a holding stack too...
                if (dynamic_cast<HoldingStack*>(srcStack) != NULL)
                {
                    // ...get all cards above this one and add them too
                    for (MyCard* card : dynamic_cast<HoldingStack*>(srcStack)->getCardsAbove(cardToDrop))
                    {
                        // Ignore the card to drop
                        if (card == cardToDrop) continue;
                        cardsToMove.push_back(card);
                    }
                }

                // Increment the amount of steps
                Main::get()->getGameWindow()->incrementMove();
                break;
            }
        }
    }

    // Now check if a stack was found
    if (foundStack)
    {
        // Register a new transaction
        Transaction t;

        // If the source stack was a DrawStack, we need to flag that in the type
        if(dynamic_cast<DrawStack*>(srcStack) != NULL)
            t.type = Transaction::ETransactionType::DrawToStack;
        else
            t.type = Transaction::ETransactionType::StackToStack;

        t.stack1 = srcStack;
        t.stack2 = foundStack;
        t.cards = cardsToMove;
        t.scoreBefore = this->score;
        t.flipCardBefore = (srcStack->getTopCard() != nullptr ? srcStack->getTopCard()->getFlipped() : false);

        // Go over all cards to move from front to back
        while (cardsToMove.size() > 0)
        {
            srcStack->removeCard(cardsToMove.front());
            foundStack->addCard(cardsToMove.front());
            cardsToMove.pop_front();
        }

        // Change the score
        evaluateScore(srcStack, foundStack);

        // Store the score after evaluation in the transaction
        t.scoreAfter = this->score;

        // Add the transaction
        this->addTransaction(t);

        return true;
    }

    return false;
}

void MyGameLogic::evaluateScore(CardStack *srcStack, CardStack *dstStack)
{
    // Increment the score with the suitable attribute
    if(dynamic_cast<HoldingStack*>(srcStack) != NULL && dynamic_cast<FinalStack*>(dstStack) != NULL)
    {
        // Points for moving a card from a HoldingStack to a FinalStack
        addScore(ScoreAttributes::TABLEAU_TO_FOUNDATION);
    }
    else if (dynamic_cast<FinalStack*>(srcStack) != NULL && dynamic_cast<HoldingStack*>(dstStack) != NULL)
    {
        // Minus points if card is moved from FinalStack back to a HoldingStack
        addScore(ScoreAttributes::FOUNDATION_TO_TABLEAU);
    }
    else if (dynamic_cast<DrawStack*>(srcStack) != NULL && dynamic_cast<HoldingStack*>(dstStack) != NULL)
    {
        // Points for moving a card from the DrawStack to a HoldingStack
        addScore(ScoreAttributes::WASTE_PILE_TO_TABLEAU);
    }
    else if (dynamic_cast<DrawStack*>(srcStack) != NULL && dynamic_cast<FinalStack*>(dstStack) != NULL)
    {
        // Points for moving a card directly from the DrawStack to a FinalStack
        addScore(ScoreAttributes::WASTE_PILE_TO_FOUNDATION);
    }
}

void MyGameLogic::addScore(int points)
{
    // Update the score and make sure it does not go below zero
    score = qMax<int>(0, score + points);

    // Emit the signal
    emit onScoreChanged();
}

int MyGameLogic::getScore()
{
    return score;
}

void MyGameLogic::checkHasEnded()
{
    // Check if all final stacks got 13 cards
    bool hasEnded = true;
    for (FinalStack* finalStack : finalStacks)
    {
        hasEnded &= (finalStack->getNumCards() == 13);
    }

    // Update isWon
    this->isWon = hasEnded;

    if (hasEnded)
    {
        // We won! Show the win screen
        Main::get()->getGameWindow()->showWinScreen();

        qDebug() << "Won!";
    }
}

bool MyGameLogic::hasEnded()
{
    return this->isWon;
}

void MyGameLogic::addTransaction(Transaction newTransaction)
{
    // Remove transactions from the front to stay at MaxUndoSteps
    int transactionsToRemove = transactions.length() - MyGameLogic::MaxUndoSteps + 1;
    if (transactionsToRemove > 0) {
        for (int i = 0; i < transactionsToRemove; i++)
        {
            transactions.pop_front();
        }
    }

    // Add it
    transactions.push_back(newTransaction);

    // If the button was disabled before, we can now enable it
    Main::get()->getGameWindow()->setUndoButtonEnabled(true);
}

void MyGameLogic::undoLastMove()
{

    //TODO: UNDO THIS
    this->isWon = true;
    // Make sure there is at least one transaction to undo
    if (transactions.empty()) return;

    // Last transaction
    Transaction lastTrans = transactions.back();

    qDebug() << "Undoing" << lastTrans.toString();

    // If it was a Stack<->Stack transaction
    if (lastTrans.type == Transaction::ETransactionType::StackToStack)
    {
        // If we have to, flip the current top card of the stack1
        if (lastTrans.flipCardBefore && lastTrans.stack1->getTopCard() != nullptr)
        {
            lastTrans.stack1->getTopCard()->setCardFlipped(false);
        }

        // Move the cards back from stack2 to stack1
        for (MyCard* card : lastTrans.cards)
        {
            lastTrans.stack2->removeCard(card);
            lastTrans.stack1->addCard(card);
        }
    }
    // If in this transaction the player drew a card from the draw stack
    else if (lastTrans.type == Transaction::ETransactionType::DrawFromDrawStack)
    {     
        // Stack1 has to be a draw stack, so call undo without any card
        static_cast<DrawStack*>(lastTrans.stack1)->undo();
    }
    // If in this transaction the player dragged a card from the draw stack to any other stack
    else if (lastTrans.type == Transaction::ETransactionType::DrawToStack)
    {
        // Remove the card from Stack2
        lastTrans.stack2->removeCard(lastTrans.cards[0]);

        // Undo the draw of this card from Stack1 which has to be a draw stack
        static_cast<DrawStack*>(lastTrans.stack1)->undo(lastTrans.cards[0]);
    }

    // Pop it from the list
    transactions.pop_back();

    // Decrement the moves
    Main::get()->getGameWindow()->decrementMove();

    // Change the score back
    this->score = lastTrans.scoreBefore;
    emit onScoreChanged();

    // If this was the last transaction to undo, disable the button again
    if (transactions.empty())
    {
        Main::get()->getGameWindow()->setUndoButtonEnabled(false);
    }
}

void MyGameLogic::restartGame()
{
    // Set up the new game board
    setUp();

    // Reset the score
    score = 0;
    isWon = false;
    emit onScoreChanged();
}
