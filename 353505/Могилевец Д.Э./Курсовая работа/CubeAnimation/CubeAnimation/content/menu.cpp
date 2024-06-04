#include "menu.h"


MainMenu::MainMenu(QObject *parent)
{}

void MainMenu::setCurrState(int newState)
{
    if (currState != newState) prevState = currState;
    currState = newState;
    emit currStateChanged();
}

void MainMenu::quit()
{
    QGuiApplication::quit();
}
