#include "game.h"
#include<iostream>


Game::Game(int dimension)
{
    board = new Board(dimension);
    score = 0;
    //scoreTotal = 0;
    gameOver = false;
    restart();
}

Game::Game(const Game &other)
{
    board = new Board(*(other.board));
    score = other.getScore();
    gameOver = other.gameOver;
}

Game::~Game()
{
    delete board;
    while(!backState.empty()){
        Board *tmp = backState.back();
        backState.pop_back();
        delete tmp;
    }

    while(!forwardState.empty()){
        Board *tmp = forwardState.top();
        forwardState.pop();
        delete tmp;
    }
}

void Game::restart()
{
    board->resetBoard();
    score = 0;
    gameOver = false;

    while(!backState.empty()){
        Board *tmp = backState.back();
        backState.pop_back();
        delete tmp;
    }

    while(!forwardState.empty()){
        Board *tmp = forwardState.top();
        forwardState.pop();
        delete tmp;
    }
 /*   Board* curr = new Board(*board);
    backState.push_back(curr);  // save initialized board.  */

}

void Game::move(int direction)
{
    forwardValid = false;
    if(!gameOver){
        Board *tmp = new Board(*board);
        backState.push_back(tmp);
        if(backState.size() > this->ROLLBACK_STEPS){
            backState.pop_front();
        }
    }
    board->sigleMove(direction);

    if(!board->possibleMove())
        gameOver = true;

    score = board->getScore();

    notifyObservers();
}

bool Game::won() const
{
    for(int i = 0; i < board->getDimension(); i++){
        for(int j = 0; j < board->getDimension(); j++){
            if(board->getBrick(i,j) != nullptr && board->getBrick(i,j)->getVal() ==  WINNING_SCORE )
                return true;
        }
    }
    return false;
}

void Game::stepBack()
{
    if(!forwardValid){
        while(!forwardState.empty()){
            Board *tmp = forwardState.top();
            forwardState.pop();
            delete tmp;
        }
    }

    if(!backState.empty()){
        forwardValid = true;
        forwardState.push(board);

        board = new Board(*(backState.back()));
        backState.pop_back();
        score = board->getScore();
    }
    notifyObservers();
}

void Game::stepForward()
{
    std::cout << "forwarding... " <<forwardState.size()<< std::endl;
    if(forwardValid && !forwardState.empty()){
        
        backState.push_back(board);
        //delete board;
        board = forwardState.top();
        forwardState.pop();
        score = board->getScore();
    }
    notifyObservers();
}
