#ifndef GAME_H
#define GAME_H

#include <stack>
#include <deque>
#include "subject.h"
#include "board.h"
using namespace std;

class Game: public Subject
{
public:
    Game(int dimension);
    Game(const Game &other);
    ~Game();

    bool isGameOver() const { return gameOver; }
    int getScore() const { return score; }
    Board* getBoard() const { return board; }

    void restart();
    void move(int direction);
    bool won() const;
    void stepBack();
    void stepForward();

private:
    Board *board;
    bool gameOver;
    int score;
    static const int WINNING_SCORE = 2048;

    deque<Board*> backState;
    stack<Board*> forwardState;
    bool forwardValid;
    const int ROLLBACK_STEPS = 5;

};

#endif // GAME_H
