#pragma once
#include "card.h"
#include <iostream>
class Deck :
             public Card
{
public:
    short count;
    short* positionX = new short[16];
    short* positionY = new short[16];
    Card* deck =new Card[16];
    Deck();
    void ShowData();
    void Place();
    bool Check(int,int,int);
    void ShowCards();
    // void ChangeCord(int, int);
    void ChangeColor();
};
