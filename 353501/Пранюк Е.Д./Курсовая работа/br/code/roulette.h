#pragma once

#include "menuwindow.h"
#include "gamewindow.h"
#include "Button.h"

class Roulette {
public:
    enum State { Exiting, Menu, Game, GameMode };
    Roulette();
    ~Roulette();
    void start();
    void toggleState();

private:
    State currentState = State::Menu;
    MenuWindow* menuWindow;
    GameWindow* gameWindow;
    Button* startButton = new Button("D:\\COURSEWORK\\BuckshotRoulette\\images\\start.png");
};
