
#include "GameWindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include "HoldingStack.h"
#include "Main.h"
#include "MyCard.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    // Setup the UI
    ui->setupUi(this);

    // Place the window at the center of the screen
    QWidget *desktop = new QWidget();
    int screenW = desktop->width();
    int screenH = desktop->height();
    int windowW = this->size().width();
    int windowH = this->size().height();
    this->move((screenW / 2) - (windowW / 2), (screenH / 2) - (windowH / 2));

    // Set background-image
    ui->centralwidget->setStyleSheet("background-image: url(:/assets/table_background.png);");
    ui->centralwidget->resize(600, 800);

    // Displays the initial score and moves
    ui->score_label->setText("Score: " + QString::number(score));
    ui->move_label->setText("Moves: " + QString::number(moves));

    QPixmap undoArrow(":/assets/backarrow.png");
    ui->undoButton->setIcon(undoArrow);
    ui->undoButton->setEnabled(false);
    ui->undoButton->setFlat(true);
    ui->undoButton->setToolTip("Undo");
    ui->undoButton->setIconSize(QSize(25,25));

    // Creation of timer and time as well as connection of timeout signal with updateTime
    timer = new QTimer(this);
    timer->start(1000);
    time = new QTime(0,0);

    // Connection from timer and the CGameWindow
    QObject::connect(timer, &QTimer::timeout, this, &GameWindow::updateTimer);

    // Connection from the ui menubar with CGameWindow
    QObject::connect(ui->actionQuit, &QAction::triggered, this, &GameWindow::closeWindows);
    QObject::connect(ui->actionAbout, &QAction::triggered, this, &GameWindow::showAbout);
    QObject::connect(ui->actionCall_Win, &QAction::triggered, this, &GameWindow::showWinScreen);
    QObject::connect(ui->actionNew_Game, &QAction::triggered, this, &GameWindow::resetGameWindow);

    // Connection from the ui undo button with GameWindow
    QObject::connect(ui->undoButton, &QPushButton::clicked, this, &GameWindow::undo);

    // Set the distance between the 3 labels
    ui->labelLayout->setSpacing(55);
    ui->labelLayout->setAlignment(ui->move_label, Qt::AlignRight);
    ui->labelLayout->setAlignment(ui->score_label, Qt::AlignRight);
    ui->labelLayout->setAlignment(ui->time_label, Qt::AlignRight);

    // Style the 3 labels: Timer, Score, Moves and hide the statusbar
    ui->score_label->setStyleSheet("QLabel {color: white}");
    ui->move_label->setStyleSheet("QLabel {color: white}");
    ui->time_label->setStyleSheet("QLabel {color: white}");
    ui->statusbar->hide();

    // Create the main layout
    QWidget* layout = new QWidget();
    mainGrid = new QGridLayout();
    mainGrid->setSpacing(12);
    layout->setLayout(mainGrid);
    ui->gridLayout_3->addWidget(layout);
}

void GameWindow::displayHoldingStack(HoldingStack *stack, int column)
{
    // Set a minimum height to avoid layout glitches
    stack->setMinimumHeight(MyCard::getCardScreenSize().height());
    mainGrid->addWidget(stack, 1, column, 1, 1, Qt::AlignTop);

    // We need a dummy-widget with size policy set to expanding in vertical to force the layout to not change when adding cards
    // to a holdingstack
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    policy.setVerticalStretch(1);
    QWidget* stretchDummy = new QWidget();
    stretchDummy->setSizePolicy(policy);
    mainGrid->addWidget(stretchDummy, 2, column);
    mainGrid->setHorizontalSpacing(70);
}

void GameWindow::displayFinalStack(FinalStack *final, int column)
{
    // Add the final stack to the widget
    mainGrid->addWidget(final, 0, column + 3, 1, 1);

    // setRowMinimumHeight is needed, so that the layout is not changing, when cards are added to the holdingstacks
    mainGrid->setRowMinimumHeight(0, 200);
}

void GameWindow::displayDrawStack(DrawStack *draw)
{
    // Add the stack to the layout
    mainGrid->addLayout(draw->getHBoxLayout(), 0, 0, 1, 2);
}

void GameWindow::showWinScreen()
{
    // Stop the timer
    timer->stop();

    // If any win screen was already displayed, don't do anything
    if (winScreen != nullptr) return;

    // Create a new win screen
    winScreen = new WinScreen(score, moves, time->toString("mm:ss"));
    winScreen->show();
}

void GameWindow::incrementMove()
{
    // Increment the moves and update the text
    ++moves;
    ui->move_label->setText("Moves: " + QString::number(moves));
}

void GameWindow::decrementMove()
{
    // Decrement the moves and update the text
    --moves;
    ui->move_label->setText("Moves: " + QString::number(moves));
}

void GameWindow::incrementScore(int scoreToAdd)
{
    // Increment the score by the given value and update the text
    score += scoreToAdd;
    ui->score_label->setText("Score: " + QString::number(score));
}

void GameWindow::updateTimer()
{
    // Add a second to the timer and update the text
    *time = time->addSecs(1);
    ui->time_label->setText("Timer: " + time->toString("mm:ss"));
}

void GameWindow::showAbout()
{
    // Simply show a message box
    QMessageBox msgBox(QMessageBox::Information, "About Solitaire", "Solitaire\n\
Written in C++ and Qt.\n\n\
Created by Alexandr Kokosh 35350063");
    msgBox.exec();
}

void GameWindow::updateScore()
{
    // Get the score off the game instance and update the text
    score = Main::get()->getGameInstance()->getScore();
    ui->score_label->setText("Score: " + QString::number(score));
}

void GameWindow::resetGameWindow()
{
    // Removes all widgets, resets the time and moves
    removeAllWidgets(mainGrid);

    // Close a winning screen if present
    if (winScreen)
    {
        winScreen->close();
        winScreen = nullptr;
    }

    // Reset the time and move count
    time = new QTime(0,0);
    timer->start(1000);
    moves = -1;
    incrementMove();
    ui->undoButton->setEnabled(false);
    emit resetGame();
}

void GameWindow::closeWindows()
{
    // If a win screen is present, close it
    if (winScreen)
    {
        winScreen->close();
        delete winScreen;
        winScreen = nullptr;
    }

    // Close this window too
    this->close();
}

void GameWindow::undo()
{
    // Tell the game instance to undo the last move
    Main::get()->getGameInstance()->undoLastMove();
}

void GameWindow::removeAllWidgets(QLayout *layout)
{
    QLayoutItem *temp;

    // Iterating over all widgets from the layout
    // if temp is layout: call this method again, otherwise delete the temp
    while(layout->count() != 0)
    {
        temp = layout->takeAt(0);
        if (temp->layout() != 0) {
            removeAllWidgets(temp->layout());
        } else if (temp->widget() != 0) {
            delete temp->widget();
        }
    }
}

void GameWindow::setUndoButtonEnabled(bool enabled)
{
    // Sets the undo button to be enabled or not
    ui->undoButton->setEnabled(enabled);
}

GameWindow::~GameWindow()
{
    // Delete the UI
    delete ui;
}
