
#pragma once

#include <QObject>
#include "MyGameLogic.h"
#include "GameWindow.h"

// Main program entry class
class Main : public QObject
{
    Q_OBJECT

public:
    // Constructor
    Main(QObject* parent = nullptr) : QObject(parent) {}

public:
    // Runs the complete program loop
    int run(int argc, char* argv[]);

    // Singleton getter
    static Main* get();

    // Returns the GameWindow instance
    GameWindow* getGameWindow() const;

    // Returns the Game instance
    MyGameLogic *getGameInstance() const;

private:
    // Singleton instance
    static Main* singletonInstance;

    // The GameWindow instance
    GameWindow* gameWindow;

    // The Game instance
    MyGameLogic* gameInstance;
};
