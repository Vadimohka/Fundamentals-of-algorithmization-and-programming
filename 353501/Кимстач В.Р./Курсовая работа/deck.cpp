#include "deck.h"
#include <iostream>
#include <random>
void Deck::ShowCards() {
    for (int i = 0;i < 16;++i) {
        std::cout << deck[i].right<<"  " << deck[i].left << "  " << deck[i].top << "  " << deck[i].bottom << "\n";
    }
}
void Deck::ShowData() {
    for (int i = 0;i < 15;++i) {
        std::cout << positionX[i] << "  " << positionY[i] << "\n";
    }
}
// void Deck::ChangeCord(int input,int i) {
//     switch (input) {
//     case 0:
//         deck[i + 1].x = deck[i].x + 1;
//         deck[i + 1].y = deck[i].y;
//         positionX[i] = deck[i + 1].x;
//         positionY[i] = deck[i + 1].y;
//         Check(i);
//         break;
//     case 1:
//         deck[i + 1].x = deck[i].x - 1;
//         deck[i + 1].y = deck[i].y;
//         positionX[i] = deck[i + 1].x;
//         positionY[i] = deck[i + 1].y;
//         Check(i);
//         break;
//     case 2:
//         deck[i + 1].x = deck[i].x;
//         deck[i + 1].y = deck[i].y + 1;
//         positionX[i] = deck[i + 1].x;
//         positionY[i] = deck[i + 1].y;
//         Check(i);
//         break;
//     case 3:
//         deck[i + 1].x = deck[i].x;
//         deck[i + 1].y = deck[i].y - 1;
//         positionX[i] = deck[i + 1].x;
//         positionY[i] = deck[i + 1].y;
//         Check(i);
//         break;

//     }

// }
Deck::Deck() {
    count = 0;
    positionX[0] = 0;
    positionY[0] = 0;
    deck[0].x = 0;
    deck[0].y = 0;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    int rand = dist(rng);
    for (int i = 0;i < 16;++i) {
        switch (rand) {
        case 0:
            if (deck[i].right != deck[i + 1].left) {
                deck[i + 1].left = deck[i].right;
                continue;
            }
            if (deck[i].left != deck[i + 1].right) {
                deck[i + 1].right = deck[i].left;
                continue;
            }
            if (deck[i].top != deck[i + 1].bottom) {
                deck[i + 1].bottom = deck[i].top;
                continue;
            }
            if (deck[i].bottom != deck[i + 1].top) {
                deck[i + 1].top = deck[i].bottom;
                continue;
            }
            break;
        case 1:
            if (deck[i].left != deck[i + 1].right) {
                deck[i + 1].right = deck[i].left;
                continue;
            }
            if (deck[i].right != deck[i + 1].left) {
                deck[i + 1].left = deck[i].right;
                continue;
            }
            if (deck[i].bottom != deck[i + 1].top) {
                deck[i + 1].top = deck[i].bottom;
                continue;
            }

            if (deck[i].top != deck[i + 1].bottom) {
                deck[i + 1].bottom = deck[i].top;
                continue;
            }

            break;
        case 2:
            if (deck[i].bottom != deck[i + 1].top) {
                deck[i + 1].top = deck[i].bottom;
                continue;
            }

            if (deck[i].top != deck[i + 1].bottom) {
                deck[i + 1].bottom = deck[i].top;
                continue;
            }
            if (deck[i].left != deck[i + 1].right) {
                deck[i + 1].right = deck[i].left;
                continue;
            }
            if (deck[i].right != deck[i + 1].left) {
                deck[i + 1].left = deck[i].right;
                continue;
            }

            break;
        case 3:
            if (deck[i].left != deck[i + 1].right) {
                deck[i + 1].right = deck[i].left;
                continue;

            if (deck[i].bottom != deck[i + 1].top) {
                deck[i + 1].top = deck[i].bottom;
                continue;
            }

            if (deck[i].top != deck[i + 1].bottom) {
                deck[i + 1].bottom = deck[i].top;
                continue;
            }
            if (deck[i].left != deck[i + 1].right) {
                deck[i + 1].right = deck[i].left;
                continue;
            }
        }
        }

    }
}
void Deck::Place() {

    int input;
    for(int i=0;i<15;++i){
        std::cout << "0-право, 1-лево, 2-вверх, 3-вниз" << "\n";
        std::cin >> input;

    }
}
bool Deck::Check(int i,int currentCard,int turnNumber) {
    switch (i){
    case 0:
        for(int j=0;j<15;++j){
        if(deck[j].x==deck[currentCard].x-1&&deck[j].y==deck[currentCard].y&&j!=turnNumber){
            return true;
        }
        if(deck[j].x==deck[currentCard].x-2&&deck[j].y==deck[currentCard].y&&deck[j].right!=deck[turnNumber].left){
            return true;
        }
        if(deck[j].x==deck[currentCard].x-1&&deck[j].y==deck[currentCard].y-1&&deck[j].bottom!=deck[turnNumber].top){
            return true;
        }
        if(deck[j].x==deck[currentCard].x-1&&deck[j].y==deck[currentCard].y+1&&deck[j].top!=deck[turnNumber].bottom){
            return true;
        }
        if(deck[turnNumber].right!=deck[currentCard].left){
            return true;
        }

        }
        return false;
        break;
    case 1:
        for(int j=0;j<15;++j){
        if(deck[j].x==deck[currentCard].x&&deck[j].y==deck[currentCard].y-1&&j!=turnNumber){
            return true;
        }
        if(deck[j].x==deck[currentCard].x&&deck[j].y==deck[currentCard].y-2&&deck[j].bottom!=deck[turnNumber].top){
            return true;
        }
        if(deck[j].x==deck[currentCard].x-1&&deck[j].y==deck[currentCard].y-1&&deck[j].right!=deck[turnNumber].left){
            return true;
        }
        if(deck[j].x==deck[currentCard].x+1&&deck[j].y==deck[currentCard].y-1&&deck[j].left!=deck[turnNumber].right){
            return true;
        }
        if(deck[turnNumber].bottom!=deck[currentCard].top){
            return true;
        }

        }
        return false;
        break;
    case 2:
        for(int j=0;j<15;++j){
        if(deck[j].x==deck[currentCard].x+1&&deck[j].y==deck[currentCard].y&&j!=turnNumber){
            return true;
        }
        if(deck[j].x==deck[currentCard].x+2&&deck[j].y==deck[currentCard].y&&deck[j].left!=deck[turnNumber].right){
            return true;
        }
        if(deck[j].x==deck[currentCard].x+1&&deck[j].y==deck[currentCard].y-1&&deck[j].bottom!=deck[turnNumber].top){
            return true;
        }
        if(deck[j].x==deck[currentCard].x+1&&deck[j].y==deck[currentCard].y+1&&deck[j].top!=deck[turnNumber].bottom){
            return true;
        }
        if(deck[turnNumber].left!=deck[currentCard].right){
            return true;
        }

        }
        return false;
        break;
    case 3:
        for(int j=0;j<15;++j){
        if(deck[j].x==deck[currentCard].x&&deck[j].y==deck[currentCard].y+1&&j!=turnNumber){
            return true;
        }
        if(deck[j].x==deck[currentCard].x&&deck[j].y==deck[currentCard].y+2&&deck[j].top!=deck[turnNumber].bottom){
            return true;
        }
        if(deck[j].x==deck[currentCard].x+1&&deck[j].y==deck[currentCard].y+1&&deck[j].left!=deck[turnNumber].right){
            return true;
        }
        if(deck[j].x==deck[currentCard].x-1&&deck[j].y==deck[currentCard].y+1&&deck[j].right!=deck[turnNumber].left){
            return true;
        }
        if(deck[turnNumber].top!=deck[currentCard].bottom){
            return true;
        }

        }
        return false;
        break;

    }

}
void Deck::ChangeColor() {
    for (int i = 0;i < 16;++i) {
        for (int j = 0;j < 16;++j) {
            if (deck[i].x == deck[j].x - 1 &&deck[i].y==deck[j].y &&deck[i].right == deck[j].left&&deck[i].right==1) {
            deck[i].rightRect->setBrush(QBrush(Qt::green));
            deck[j].leftRect->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x - 1 &&deck[i].y==deck[j].y &&deck[i].right == deck[j].left&&deck[i].right==2) {
                deck[i].rightCastle->setBrush(QBrush(Qt::green));
                deck[j].leftCastle->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x + 1 &&deck[i].y==deck[j].y &&deck[i].left == deck[j].right&&deck[i].left==1) {
                deck[i].leftRect->setBrush(QBrush(Qt::green));
                deck[j].rightRect->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x + 1 &&deck[i].y==deck[j].y &&deck[i].left == deck[j].right&&deck[i].left==2) {
                deck[i].leftCastle->setBrush(QBrush(Qt::green));
                deck[j].rightCastle->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x &&deck[i].y==deck[j].y+1 &&deck[i].bottom == deck[j].top&&deck[i].bottom==1) {
                deck[i].bottomRect->setBrush(QBrush(Qt::green));
                deck[j].topRect->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x &&deck[i].y==deck[j].y+1 &&deck[i].bottom == deck[j].top&&deck[i].bottom==2) {
                deck[i].bottomCastle->setBrush(QBrush(Qt::green));
                deck[j].topCastle->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x &&deck[i].y==deck[j].y-1 &&deck[i].top == deck[j].bottom&&deck[i].top==1) {
                deck[i].topRect->setBrush(QBrush(Qt::green));
                deck[j].bottomRect->setBrush(QBrush(Qt::green));
                break;
            }
            if (deck[i].x == deck[j].x &&deck[i].y==deck[j].y-1 &&deck[i].top == deck[j].bottom&&deck[i].top==2) {
                deck[i].topCastle->setBrush(QBrush(Qt::green));
                deck[j].bottomCastle->setBrush(QBrush(Qt::green));
                break;
            }
        }
    }
}
