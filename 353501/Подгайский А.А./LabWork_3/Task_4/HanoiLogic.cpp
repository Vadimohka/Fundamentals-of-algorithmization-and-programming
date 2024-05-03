#include "HanoiLogic.h"

void HanoiLogic::moveStack(int amount, short src, short dst){
    if(amount == 0){
        return;
    }

    short independentTower = 0;
    while(independentTower == src || independentTower == dst){
        independentTower++;
    }

    moveStack(amount-1, src, independentTower);
    actions.push_back({src, dst});
    moveStack(amount-1, independentTower, dst);
}

QVector< QPair<short, short>>  HanoiLogic::Hanoi(int n){
    actions.clear();
    moveStack(n, 0, 2);
    return actions;
}

