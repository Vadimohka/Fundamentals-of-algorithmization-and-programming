#include <iostream>
#include "board.h"

Board::Board(int dimension)
{
    this->dimension = dimension;
    this->scoreThisRound = 0;
    this->scoreTotal = 0;
    init();

}

Board::Board(const Board &b){
    dimension = b.getDimension();
    scoreTotal = b.scoreTotal;
    scoreThisRound = b.scoreThisRound;
    init();
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(b.board[i][j]){
                board[i][j] = new Brick(*(b.board[i][j]));
            }
        }
    }
}

Board::~Board(){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            delete board[i][j];
        }
    }
}


Brick *Board::getBrick(int x, int y)
{
    return this->board[x][y];
}

void Board::sigleMove(int direction)
{
    Board pre(*this);
    prepareNextMove();

    if(direction == UP){
        moveUp();
    }
    else if(direction == DOWN){
        moveDown();
    }
    else if(direction == LEFT){
        moveLeft();
    }
    else if(direction == RIGHT){
        moveRight();
    }

    if(this->boardChanged(pre)){
        pair<int,int> nextPos = randomFreePosition();
        board[nextPos.first][nextPos.second] = new Brick();
        int randomNum = rand() % 100;
        if(randomNum <= 4 || randomNum >= 96 )  // for a new brick, 90% -> '2' , 10% -> '4',
            board[nextPos.first][nextPos.second]->update();
    }

    notifyObservers();
}

int Board::getDimension() const
{
    return dimension;
}

bool Board::hasEmptyBrick() const
{
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(board[i][j] == nullptr)
                return true;
        }
    }
    return false;
}

void Board::resetBoard()
{
    scoreThisRound = 0;
    scoreTotal = 0;

    for (int i = 0; i < dimension ; ++i) {
            for (int j = 0; j < dimension; ++j) {
                delete board[i][j];
                board[i][j] = NULL;
            }
    }

    pair<int,int> start = randomFreePosition();
    board[start.first][start.second] = new Brick();
    start = randomFreePosition();
    board[start.first][start.second] = new Brick();
}

bool Board::possibleMove() const
{
    if(hasEmptyBrick()){
        return true;
    }
    else{
        for(int i = 0; i < dimension; i++){
            int p = 0, q = p + 1;
            while(q < dimension){
                while(p < dimension && board[i][p] == nullptr)  p++;
                if(p >= dimension-1) break;
                q = max(q,p+1);
                while(p < dimension && board[i][q] == nullptr)  q++;
                if(q >= dimension) break;

                if(board[i][p]->getVal() == board[i][q]->getVal())
                    return true;
                else{
                    p++;
                    q = p+1;
                }
            }

            p = 0, q = p + 1;
            while(q < dimension){
                while(p < dimension && board[p][i] == nullptr)  p++;
                if(p >= dimension-1) break;
                q = max(q,p+1);
                while(p < dimension && board[q][i] == nullptr)  q++;
                if(q >= dimension) break;

                if(board[p][i]->getVal() == board[q][i]->getVal())
                    return true;
                else{
                    p++;
                    q = p+1;
                }
            }
        }
    }
   return false;
}


void Board::moveLeft()
{
    for(int i = 0; i < dimension; i++){
        int p = 0, q = 1;
        while(p < dimension && q < dimension){
            while(p < dimension && board[i][p] == nullptr){
                p++;
            }
            if(p >= dimension-1) break;
            q = max(q,p+1);
            while(q < dimension && board[i][q] == nullptr){
                q++;
            }
            if(q >= dimension) break;

            if(board[i][p]->getVal() == board[i][q]->getVal()){
                board[i][p]->update();
                delete board[i][q];
                board[i][q] = nullptr;
                scoreThisRound += board[i][p]->getVal();
                scoreTotal += scoreThisRound;
                p = q+1;
            }
            else{
                p = q;
                q = p+1;
            }
        }
    }
    handleCollionsion(LEFT);
}

void Board::moveRight()
{
    for(int i = 0; i < dimension; i++){
        int p = dimension-1, q = p-1;
        while(p > 0 && q >= 0){
            while(p > 0 && board[i][p] == nullptr){
                p--;
            }
            if(p <= 0) break;
            q = min(q,p-1);
            while(q >= 0 && board[i][q] == nullptr){
                q--;
            }
            if(q < 0) break;

            if(board[i][p]->getVal() == board[i][q]->getVal()){
                board[i][p]->update();
                delete board[i][q];
                board[i][q] = nullptr;
                scoreThisRound += board[i][p]->getVal();
                scoreTotal += scoreThisRound;
                p = q-1;

            }
            else{
                p = q;
                q = p-1;
            }
        }
    }
    handleCollionsion(RIGHT);
}

void Board::moveUp()
{
    for(int i = 0; i < dimension; i++){
        int p = 0, q = 1;
        while(p < dimension && q < dimension){
            while(p < dimension && board[p][i] == nullptr){
                p++;
            }
            if(p >= dimension-1) break;
            q = max(q,p+1);
            while(q < dimension && board[q][i] == nullptr){
                q++;
            }
            if(q >= dimension) break;

            if(board[p][i]->getVal() == board[q][i]->getVal()){
                board[p][i]->update();
                delete board[q][i];
                board[q][i] = nullptr;
                scoreThisRound += board[p][i]->getVal();
                scoreTotal += scoreThisRound;
                p = q+1;
            }
            else{
                p = q;
                q = p+1;
            }
        }
    }
    handleCollionsion(UP);
}

void Board::moveDown()
{
    for(int i = 0; i < dimension; i++){
        int p = dimension-1, q = p-1;
        while(p > 0 && q >= 0){
            while(p > 0 && board[p][i] == nullptr){
                p--;
            }
            if(p <= 0) break;
            q = min(q,p-1);
            while(q >= 0 && board[q][i] == nullptr){
                q--;
            }
            if(q < 0) break;

            if(board[p][i]->getVal() == board[q][i]->getVal()){
                board[p][i]->update();
                delete board[q][i];
                board[q][i] = nullptr;
                scoreThisRound += board[p][i]->getVal();
                scoreTotal += scoreThisRound;
                p = q-1;
            }
            else{
                p = q;
                q = p-1;
            }
        }
    }
    handleCollionsion(DOWN);
}

void Board::handleCollionsion(int direction)
{
    if(direction == LEFT){
        for(int i = 0; i < dimension; i++){
            int p = 0, q = p+1;
            while(q < dimension){
                while(p < dimension && board[i][p] != nullptr) p++;
                if(p >= dimension-1) break;
                q = max(q,p+1);
                while(q < dimension && board[i][q] == nullptr) q++;
                if(q >= dimension) break;
                board[i][p] = board[i][q];
                board[i][q] = nullptr;
            }
        }
    }
    else if(direction == RIGHT){
        for(int i = 0; i < dimension; i++){
            int p = dimension-1, q = p-1;
            while(q >= 0){
                while(p >= 0 && board[i][p] != nullptr) p--;
                if(p <= 0) break;
                q = min(q,p-1);
                while(q >= 0 && board[i][q] == nullptr) q--;
                if(q < 0) break;
                board[i][p] = board[i][q];
                board[i][q] = nullptr;
            }
        }
    }
    else if(direction == UP){
        for(int i = 0; i < dimension; i++){
            int p = 0, q = p+1;
            while(q < dimension){
                while(p < dimension && board[p][i] != nullptr) p++;
                if(p >= dimension-1) break;
                q = max(q,p+1);
                while(q < dimension && board[q][i] == nullptr) q++;
                if(q >= dimension) break;
                board[p][i] = board[q][i];
                board[q][i] = nullptr;
            }
        }
    }

    else if(direction ==  DOWN){
        for(int i = 0; i < dimension; i++){
            int p = dimension-1, q = p-1;
            while(q >= 0){
                while(p >= 0 && board[p][i] != nullptr) p--;
                if(p <= 0) break;
                q = min(q,p-1);
                while(q >= 0 && board[q][i] == nullptr) q--;
                if(q < 0) break;
                board[p][i] = board[q][i];
                board[q][i] = nullptr;
            }
        }
    }
}

pair<int,int> Board::randomFreePosition()
{
    pair<int,int> pos;
    if(this->isFull()){
        pos = make_pair(-1,-1);
    }
    else{
        int x,y;
        do{
            x = rand() % dimension;
            y = rand() % dimension;
        }while(board[x][y] != nullptr);
        pos = make_pair(x,y);

    }
    return pos;

}

void Board::init(){
    board.resize(dimension);
    for(int i = 0; i < board.size(); i++){
        board[i].resize(dimension);
        for(int j = 0; j < board[i].size(); j++)
               board[i][j] = nullptr;
    }
}


bool Board::testShow()
{
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            std::cout << board[i][j]->getVal() << " " ;
        }
        std::cout << std::endl;
    }
    return true;
}


bool Board::isFull() const{
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(!this->board[i][j]){
                return false;
            }
        }
    }
    return true;
}


bool Board::boardChanged(Board &pre)
{
   for(int i = 0; i < dimension; i++){
       for(int j = 0; j < dimension; j++){
           if( (this->board[i][j] == nullptr && pre.board[i][j] != nullptr) || (this->board[i][j] != nullptr && pre.board[i][j] == nullptr) || ( this->board[i][j]!= nullptr && pre.board[i][j] != nullptr && this->board[i][j]->getVal() != pre.board[i][j]->getVal()))
               return true;
       }
   }
   return false;
}

void Board::prepareNextMove()
{

    this->scoreThisRound = 0;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(board[i][j] != nullptr){
                board[i][j]->setUpdated(false);
            }
        }
    }
}
