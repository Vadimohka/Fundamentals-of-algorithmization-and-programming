//
// Created by Stas Maslakov on 29.04.2024.
//
#include <random>
#include "Stone.h"
Stone::Stone() {
    QString imagePath = "/Users/sagot/Documents/Snake-game/images/stone.png";
    setPixmap(QPixmap(imagePath).scaled(15, 15));

    // Create a random number generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Define the range for random positions
    std::uniform_int_distribution<int> xPosDistribution(0, 4000 - 15);
    std::uniform_int_distribution<int> yPosDistribution(0, 4000 - 15);

    // Generate random positions
    int xPos = xPosDistribution(generator);
    int yPos = yPosDistribution(generator);

    setPos(xPos, yPos);
}