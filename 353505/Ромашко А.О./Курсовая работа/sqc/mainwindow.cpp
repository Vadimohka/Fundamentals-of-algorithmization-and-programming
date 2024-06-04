#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();

    saveMenu = new SaveMenu;
    mainMenu = new MainMenu;
    gameLevelsScene = new GameLevelsScene;

    mainMenu->showFullScreen();

    connect(saveMenu,&SaveMenu::SaveMenuExitSignal,mainMenu,&MainMenu::openMainMenu);
    connect(mainMenu,&MainMenu::MainMenutoSaveMenuSignal, saveMenu,&SaveMenu::openSlot);
    connect(saveMenu,&SaveMenu::SaveMenuExitTGLSoSignal,gameLevelsScene,&GameLevelsScene::openSlot);
    connect(gameLevelsScene,&GameLevelsScene::GameLevelSceneExitSignal,saveMenu,&SaveMenu::openSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
