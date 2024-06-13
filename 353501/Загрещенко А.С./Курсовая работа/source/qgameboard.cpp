#include "qgameboard.h"
#include "game.h"
#include "qbrick.h"
#include "qresetbutton.h"
#include "qbrick.h"
#include "board.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>

#include <iostream>
using namespace std;


QGameBoard::QGameBoard(QWidget *parent) : QWidget(parent)
{

    resize(650,450);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    boardLayout = nullptr;

    game = new Game(4);
    game->registerObserver(this);

    gui_board.resize(game->getBoard()->getDimension());
    for(int i = 0; i < game->getBoard()->getDimension(); i++)
        gui_board[i].resize(game->getBoard()->getDimension());
    for(int i = 0; i < game->getBoard()->getDimension(); i++){
        for(int j = 0; j < game->getBoard()->getDimension(); j++){
            gui_board[i][j] = nullptr;

        }
    }

    drawBoard();

    this->scoreLabel = new QLabel(QString("SCORE: %1").arg(game->getScore()));
    scoreLabel->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    scoreLabel->setFixedHeight(50);
    mainLayout->insertWidget(1, scoreLabel, 0, Qt::AlignRight);

    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.GetResetButton(), SIGNAL(clicked()), this, SLOT(resetGame()));
}

QGameBoard::~QGameBoard()
{
    delete game;
}

void QGameBoard::notify()
{
    cout << "click" << endl;
    if(game->isGameOver()){
        gameOverWindow.show();
    }
    if(game->won()){
        scoreLabel->setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore()));
    }
    else
        scoreLabel->setText(QString("SCORE: %1").arg(game->getScore()));

    //std::cout <<  game->getScore() << std::endl;
    drawBoard();
}

void QGameBoard::resetGame()
{

    game->restart();
    drawBoard();
    scoreLabel->setText(QString("SCORE: %1").arg(game->getScore()));
    gameOverWindow.hide();
}

void QGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for(int i = 0; i < game->getBoard()->getDimension(); i++){
        for(int j = 0; j < game->getBoard()->getDimension(); j++){
            delete gui_board[i][j];
            gui_board[i][j] = new QBrick(game->getBoard()->getBrick(i,j));
            boardLayout->addWidget(gui_board[i][j],i,j);
            gui_board[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}


void QGameBoard::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()){
    case Qt::Key_Up:
        game->move(0);
        break;
    case Qt::Key_Down:
        game->move(1);
        break;
    case Qt::Key_Left:
        game->move(2);
        break;
    case Qt::Key_Right:
        game->move(3);
        break;
    case Qt::Key_Comma:
        game->stepBack();
        break;
    case Qt::Key_Period:
        game->stepForward();
        break;
    }
}

