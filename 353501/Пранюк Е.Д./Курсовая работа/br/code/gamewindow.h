#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

const int NUM_HINT_TYPES = 7;
const std::string HINT_TEXTURES[NUM_HINT_TYPES] = {
    "D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png", "D:\\COURSEWORK\\BuckshotRoulette\\images\\cigarettes.png", "D:\\COURSEWORK\\BuckshotRoulette\\images\\handcuffs.png",
    "D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png", "D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png","D:\\COURSEWORK\\BuckshotRoulette\\images\\minimize.png"
};
//Button hintButtons[NUM_HINT_TYPES];

enum HintType {
    MAGNIFIER,
    CIGARETTES,
    HANDCUFFS,
    KNIFE,
    BEER,
    INVERTER,
    ADRENALINE
};

struct Hint {
    HintType type;
    std::string name;
};

class GameWindow {
public:
    GameWindow();
   // void play();
    void anim1(sf::RenderWindow* window);
    bool binarySearchHint( std::vector<int>& hints,  int& targetHint, int left, int right);
    void buckshotRoulette(sf::Event* event, sf::RenderWindow* window);
    void russianRoulette(sf::Event* event, sf::RenderWindow* window);
    void draw(sf::RenderWindow* window);
    void nextRound(sf::RenderWindow* window);
    void reloadText(sf::RenderWindow* window, int live, int blank);
    void drawHintButtons(sf::RenderWindow* window);
    void createHintButtons(const std::vector<Hint>& playerHints);
    void drawH(sf::RenderWindow* window);
    std::vector<int> hintsBtns;
    std::vector<Hint> generateHints(int round);
    void lives(sf::RenderWindow* window, int pl, int dl);
    Hint getRandomHint();
    bool inMenu();
    void quickSort(std::vector<int>& arr, int left, int right);
    bool useHint(Hint hint, std::vector<bool>& chamber, int& lives, int& opponentLives, std::vector<Hint>& hints, std::vector<Hint>& opponentHints);
void handleHintButtons(std::vector<Hint>& playerHints, std::vector<bool>& chamber, int& playerLives, int& computerLives, std::vector<Hint>& computerHints, sf::Event* event, sf::Window* window);
private:
    std::unique_ptr<sf::Text> livesText;
    std::vector<Hint> playerHints;
    std::vector<Hint> computerHints;
    bool isPlayer = true;
    std::vector<bool> chamber;
    std::vector<bool> chamber2;
    //bool bullet;
    int r = 2;
    int round = 1;
   std::vector<std::unique_ptr<Button>> hintButtons;
    int getInitialLives(int round);
   
    std::vector<bool> loadChamber();
    //std::vector<Hint> generateHints(int round);
    //Hint getRandomHint();
    //bool useHint(Hint hint, std::vector<bool>& chamber, int& lives, int& opponentLives, std::vector<Hint>& hints, std::vector<Hint>& opponentHints);
    void playerTurn( int& playerLives, int& computerLives, sf::Event* event, sf::Window* window, std::vector<Hint>& playerHints, std::vector<Hint>& computerHints);
    void computerTurn(std::vector<bool>& chamber, int& playerLives, int& computerLives, sf::Window* window);
    std::unique_ptr<sf::Text> statusText;
    std::unique_ptr<sf::Texture> backgroundTexture;
    std::unique_ptr<sf::Sprite> background;
    std::unique_ptr<sf::Texture> dealerTexture;
    std::unique_ptr<sf::Sprite> dealer;
    std::unique_ptr<sf::Texture> gun1Texture;
    std::unique_ptr<sf::Sprite> gun1;
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::Text> textRound;
    std::unique_ptr<sf::Text> textReload;
    std::unique_ptr<sf::Text> textHint;
    std::unique_ptr<Button> u ;
    std::unique_ptr<Button> nu;
    std::unique_ptr<Button> menu;

    float dealerY = 100.0f;
    float dealerDirection = 1.0f; // 1 для движения вверх, -1 для движения вниз
    bool imenu=false;
};