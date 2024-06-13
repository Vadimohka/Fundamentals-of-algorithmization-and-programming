#include "roulette.h"

Roulette::Roulette() {
    menuWindow = new MenuWindow();
    gameWindow = new GameWindow();

    startButton->setCenterPosition();
    //startButton->draw();
}

Roulette::~Roulette() {
    delete menuWindow;
    delete gameWindow;
}

void Roulette::start() {
    sf::VideoMode customMode(1900, 1000);
    sf::RenderWindow window(customMode, "Roulette", sf::Style::Close);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Space || gameWindow->inMenu()) {
                   // if (currentState == State::Menu) {
                        toggleState();
                   // }
                }
            }
            else {
                if (currentState == State::Menu) {
                    menuWindow->handleEvent(&event, &window);
                }
                else if (currentState == State::Game && menuWindow->isModeStr()) { gameWindow->buckshotRoulette(&event, &window);
                    
                }
                else if (currentState == State::Game && !menuWindow->isModeStr()) {
                   gameWindow->russianRoulette(&event, &window);
                }
            }
        }
            window.clear();
            if (currentState == State::Menu) {
                menuWindow->draw(&window);
                startButton->draw(&window);
            }
            else if (currentState == State::Game) {
                gameWindow->draw(&window);
            }
            window.display();
    }
}

void Roulette::toggleState() {
    if (currentState == State::Menu) {
        currentState = State::Game;
    }
    else if (currentState == State::Game) {
        currentState = State::Menu;
    }
}