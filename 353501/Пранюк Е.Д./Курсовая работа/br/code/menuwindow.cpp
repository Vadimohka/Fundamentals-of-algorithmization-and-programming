#include "menuwindow.h"

MenuWindow::MenuWindow() {
    music = std::make_unique<sf::Music>();
    backgroundTexture = std::make_unique<sf::Texture>();
    minimizeTexture = std::make_unique<sf::Texture>();
    closeTexture = std::make_unique<sf::Texture>();
    startTexture = std::make_unique<sf::Texture>();
    background = std::make_unique<sf::Sprite>();
    font = std::make_unique<sf::Font>();
    opening = std::make_unique<sf::Text>();
    mode = std::make_unique<sf::Text>();
    minimizeButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png");
    closeButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\close.png");
    noButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\no.png");
    yesButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\yes.png");
    musicButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\nota.png");
    noMusicButton = std::make_unique<Button>("D:\\COURSEWORK\\BuckshotRoulette\\images\\notnota.png");

    if (!music->openFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\angrybirds.mp3")) {
        std::cout << "Error while loading music!" << std::endl;
        return;
    }
    if (!backgroundTexture->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\formenu.png")) {
        std::cout << "Error while loading background!" << std::endl;
        return;
    }
    if (!font->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\fonts\\EpilepsySansBold.ttf")) {
        std::cout << "Error while loading font!" << std::endl;
        return;
    }

    opening->setFont(*font);
    opening->setString("BUCKSHOT ROULETTE");
    opening->setCharacterSize(150);
    opening->setFillColor(sf::Color::White);
    opening->setPosition(280, 200);

    mode->setFont(*font);
    mode->setString("classic mode\n\nstrategy mode");
    mode->setCharacterSize(60);
    mode->setFillColor(sf::Color::White);
    mode->setPosition(800, 700);

    background->setTexture(*backgroundTexture);
}

void MenuWindow::draw(sf::RenderWindow* window) {
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2u textureSize = backgroundTexture->getSize();
    background->setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
    window->draw(*background);
    window->draw(*opening);
    window->draw(*mode);

    noMusicButton->setPosition(50, 900);
    noMusicButton->draw(window);

    musicButton->setPosition(-150, 900);
    musicButton->draw(window);

    minimizeButton->setPosition(1500, 20);
    closeButton->setPosition(1700, 20);
   // startButton->setCenterPosition();

    swapButtons();
    noButton->draw(window);
    yesButton->draw(window);
   // startButton->draw(window);
    closeButton->draw(window);
    minimizeButton->draw(window);
}
void MenuWindow::handleEvent(sf::Event* event, sf::RenderWindow* window) {
    if (event->type == sf::Event::MouseButtonPressed) {
        if (event->mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            if (minimizeButton->isClicked(event, window)) {
                HWND hWnd = window->getSystemHandle();
                ShowWindow(hWnd, SW_MINIMIZE);
            }
            else if (closeButton->isClicked(event, window)) {
                window->close();
            }
            else if (yesButton->isClicked(event, window) || noButton->isClicked(event, window)) {
                classic = !classic;
                isClassicMode = !isClassicMode;
                swapButtons();
            }
            else if (noMusicButton->isClicked(event, window) || musicButton->isClicked(event, window)) {
                if (isMusic) {
                    music->stop();
                }
                isMusic = !isMusic;
                playMusic();
            }
        }
    }
}

bool MenuWindow::isModeStr() {
    if (classic) {
        return true;
    }
    else return false;
}

void MenuWindow::swapButtons() {
    if (!isClassicMode) {
        yesButton->setCenterPosition();
        noButton->setCenterPosition();
        noButton->move(-200, 210);
        yesButton->move(-200, 330);
    }
    else {
        noButton->setCenterPosition();
        yesButton->setCenterPosition();
        yesButton->move(-200, 210);
        noButton->move(-200, 330);
    }
}

void MenuWindow::playMusic() {
    if (!isMusic) {
        std::swap(musicButton, noMusicButton);
        music->setVolume(50);
        music->play();
        music->setLoop(true);
    }
    else {
        std::swap(musicButton, noMusicButton);
        music->stop();
    }
}
