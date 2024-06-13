#include "Button.h"
Button::Button(std::string textureFilename) {
    _texture = new sf::Texture();
    if (!_texture->loadFromFile(textureFilename)) {
        std::cout << "Error while loading button texture!" << std::endl;
        return;
    }
    _size.x = static_cast<float>(_texture->getSize().x);
    _size.y = static_cast<float>(_texture->getSize().y);
    _rect.setSize(_size);
    _rect.setTexture(_texture);
    _rect.setTextureRect(sf::IntRect(0, 0, static_cast<float>(_size.x), static_cast<float>(_size.y)));
}
Button::~Button() {
    delete _texture;
}
void Button::draw(sf::RenderWindow* window) {
    if (_isVisible) {
        window->draw(_rect);
    }
}
void Button::setPosition(float x, float y) {
    _rect.setPosition(x, y);
}
void Button::setCenterPosition() {
    auto screen = sf::VideoMode::getDesktopMode();
    float centerX = screen.width / 2;
    float centerY = screen.height / 2;
    float dx = _size.x / 2;
    float dy = _size.y / 2;
    _rect.setPosition(centerX - dx, centerY - dy);
}
void Button::move(float x, float y) {
    _rect.move(x, y);
}
void Button::setRotation(int angle) {
    _rect.setRotation(angle);
}
bool Button::isClicked(sf::Event* event, sf::Window* window) const {
    if (event->type == sf::Event::MouseButtonPressed) {
        if (event->mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            if (_isVisible && _rect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                return true;
            }
        }
    }
    return false;
}
void Button::playSound() {
    if (!buffer.loadFromFile("D:\\COURSEWORK\\BuckshotRoulette\\images\\click1.wav"))
        return;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.play();
}
void Button::remove() {
    _isVisible = false;
}