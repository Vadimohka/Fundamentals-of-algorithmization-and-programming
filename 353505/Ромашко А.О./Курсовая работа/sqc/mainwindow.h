#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "savemenu.h"
#include "gamelevelsscene.h"
#include "gamescene.h"
#include "mainmenu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SaveMenu *saveMenu;
    GameLevelsScene *gameLevelsScene;
    GameScene *gameScene;
    MainMenu *mainMenu;
};

#endif // MAINWINDOW_H
