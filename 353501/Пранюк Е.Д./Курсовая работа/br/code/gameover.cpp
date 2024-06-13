#include "gameover.h"
GameOver::GameOver() {
    backgroundTexture = std::make_unique<sf::Texture>();
    if (!backgroundTexture->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\table.png")) {
        std::cout << "Error while loading table!" << std::endl;
        return;
    }
    background = std::make_unique<sf::Sprite>();
    background->setTexture(*backgroundTexture);

    font = std::make_unique<sf::Font>();
    if (!font->loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\fonts\\EpilepsySansBold.ttf")) {
        std::cout << "Error while loading font!" << std::endl;
    }
    text = std::make_unique<sf::Text>();
    text->setFont(*font);
    text->setCharacterSize(150);
    text->setPosition(600, 300);
    text->setString("GAME OVERRRR");
}

void GameOver::draw(sf::RenderWindow* window) {
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2u textureSize = backgroundTexture->getSize();
    background->setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);
    window->draw(*background);
    window->draw(*text);
}
