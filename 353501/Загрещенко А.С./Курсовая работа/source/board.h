#ifndef BOARD_H
#define BOARD_H

#include "subject.h"
#include "brick.h"

#include <QVector>
#include <QString>
#include <utility>

class Brick;

class Board: public Subject
{
public:
    Board(int dimension);
    Board(const Board &board);
    ~Board();

    Brick* getBrick(int x, int y);
    void sigleMove(int direction);


    int getDimension() const;
    int getScore() const { return scoreTotal; }

    bool hasEmptyBrick() const;
    void resetBoard();
    bool possibleMove() const;
    bool validPosition(int x, int y) const;

    /* use for test */
    bool testShow();


private:
    const int UP = 0;
    const int DOWN = 1;
    const int LEFT = 2;
    const int RIGHT = 3;

    int scoreThisRound;
    int scoreTotal;
    //bool hasCollision;
    int dimension;

    QVector<QVector<Brick*>> board;
    QVector<Brick*> emptyBricks;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void handleCollionsion(int direction);

    pair<int,int> randomFreePosition();

    bool isFull() const;
    bool boardChanged(Board &pre);
    void prepareNextMove();
    void init();

};



#endif // BOARD_H
