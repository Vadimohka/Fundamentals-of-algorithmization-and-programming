// Button.h
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Button {
public:
    Button(std::string textureFilename);
    ~Button();

    void draw(sf::RenderWindow* window);
    bool isClicked( sf::Event* event, sf::Window* window) const;
    void setCenterPosition();
    void move(float x, float y);
    void setPosition(float x, float y);
    void remove();
    const sf::Vector2f& getPosition() const { return _rect.getPosition(); }
    void playSound();
    void setRotation(int angle);
    bool isVisible() const { return _isVisible; } 

private:
    sf::Texture* _texture;
    sf::RectangleShape _rect;
    sf::Vector2f _size;
    sf::Sound sound;
    sf::SoundBuffer buffer;
    bool _isVisible = true;
};