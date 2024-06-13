#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class GameOver
{
public:
	GameOver();
	void draw(sf::RenderWindow* window);
	//void handleEvent(sf::Event* event, sf::RenderWindow* window);

private:
	std::unique_ptr<sf::Texture> backgroundTexture;
	std::unique_ptr<sf::Sprite> background;

	std::unique_ptr<sf::Font> font;
	std::unique_ptr<sf::Text> text;
};

