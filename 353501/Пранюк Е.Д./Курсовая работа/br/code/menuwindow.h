#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Button.h"

class MenuWindow {
public:
    MenuWindow();
    void playMusic();
    void draw(sf::RenderWindow* window);
    void handleEvent(sf::Event* event, sf::RenderWindow* window);
    void swapButtons();
    bool isModeStr();

private:
    bool classic=true;
    std::unique_ptr<sf::Music> music;
    std::unique_ptr<sf::Texture> backgroundTexture;
    std::unique_ptr<sf::Texture> minimizeTexture;
    std::unique_ptr<sf::Texture> closeTexture;
    std::unique_ptr<sf::Texture> startTexture;
    std::unique_ptr<sf::Sprite> background;
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::Text> opening;
    std::unique_ptr<sf::Text> mode;
    std::unique_ptr<Button> minimizeButton;
    std::unique_ptr<Button> closeButton;
    std::unique_ptr<Button> noButton;
    std::unique_ptr<Button> yesButton;
    std::unique_ptr<Button> musicButton;
    std::unique_ptr<Button> noMusicButton;
    bool isClassicMode = true;
    bool isMusic = true;
};
