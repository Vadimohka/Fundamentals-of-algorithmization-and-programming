
#include "Main.h"
#include <QApplication>
#include <QDebug>

// Singleton instance definition
Main *Main::singletonInstance = nullptr;

int Main::run(int argc, char *argv[])
{
    // Create a new QApplication instance
    QApplication app(argc, argv);

    // Set the applications icon
    app.setWindowIcon(QIcon(":/assets/icon.png"));

    // Assign the singleton instance
    singletonInstance = this;

    // Create the game window
    gameWindow = new GameWindow();
    gameWindow->show();

    // Create the game instance
    gameInstance = new MyGameLogic();

    // Run the app loop
    return app.exec();
}

Main *Main::get()
{
    // Return the singleton instance
    return singletonInstance;
}

GameWindow *Main::getGameWindow() const
{
    // Return the game window instance
    return gameWindow;
}

MyGameLogic *Main::getGameInstance() const
{
    // Returns the game instance
    return gameInstance;
}

// Applications entry point
int main(int argc, char* argv[])
{
    // Create a new Main and run it
    Main *main = new Main();
    return main->run(argc, argv);
}
