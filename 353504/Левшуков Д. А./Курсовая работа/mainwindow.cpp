#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "log.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cl();
    game=nullptr;
    add_log("Main menu open");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlayButton_clicked()
{

    delete game;
    game=new Game();
    connect(game, &Game::mainWindow, this, &MainWindow::show);
    add_log("Play button pushed");
    this->close();
    add_log("Main menu close");

    game->show();

    add_log("Game start...");

}


void MainWindow::on_ExitButton_clicked()
{
    add_log("Exit button pushed");
    exit(0);
}
