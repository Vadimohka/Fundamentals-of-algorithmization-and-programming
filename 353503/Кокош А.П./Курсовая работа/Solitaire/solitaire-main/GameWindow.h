
#pragma once

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "DrawStack.h"
#include "FinalStack.h"
#include "HoldingStack.h"
#include "MyCard.h"
#include "WinScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

// Implements the main window to be displayed by Qt
class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor and destructor
    GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

    // This functions displays the holding stacks, is called from game.cpp
    void displayHoldingStack(HoldingStack *stack, int column);

    // This functions displays the final stacks, is called from game.cpp
    void displayFinalStack(FinalStack* final, int column);

    // This function displays the draw stack, is called from game.cpp
    void displayDrawStack(DrawStack* draw);

    // Is called after every move
    void incrementMove();
    void decrementMove();
    void incrementScore(int scoreToAdd);

    // Clears the gridlayout where all cards are displayed, needed, when new game is chosen
    void removeAllWidgets(QLayout *layout);

    // Sets whether the undo button is enabled or not
    void setUndoButtonEnabled(bool enabled);

    // Shows the win screen
    void showWinScreen();

signals:
    // This signal is send when the new game menu item is chosen, connected with slot from CGame
    void resetGame();

private slots:
    // Called every second
    void updateTimer();

    // The "About" menu item
    void showAbout();

    // The "Undo" button
    void undo();

public slots:
    // Called when CGame changes its internal score-variable
    void updateScore();

    // The "new game" menu item
    void resetGameWindow();

    // Closes all windows
    void closeWindows();

private:
    // Reference to this window
    Ui::GameWindow* ui;

    // Variable for score and amount of moves
    int score = 0;
    int moves = 0;
    QTimer* timer;
    QTime* time;

    // Reference to the win screen, if any
    WinScreen *winScreen = nullptr;

    // The main grid layout
    QGridLayout* mainGrid;
};
