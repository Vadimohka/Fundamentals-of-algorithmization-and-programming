#include "mainmenu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
MainWindow::MainWindow(){
    this->soundManager = new Ara_Sound_Manager;
    soundManager->connectSound(this);
    soundManager->playSoundEffect("theme");
    createActions();
    createMenus();
    createScene();
    setCentralWidget(view);
}

void MainWindow::closeEvent(QCloseEvent *){
    setting->writeSettings();
    qApp->quit();
}

void MainWindow::createActions(){
    returnAction = new QAction(tr("&Return to Title"), this);
    returnAction->setShortcut(tr("Ctrl+R"));
    returnAction->setStatusTip(tr("Return to the title screen"));
    connect(returnAction, SIGNAL(triggered()), this, SLOT(returnTitle()));

    quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    settingsAction = new QAction(tr("&Settings"), this);
    connect(settingsAction, SIGNAL(triggered()), this, SLOT(settings()));

    aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAbout()));

    setting = new Settings(this);
    connect(setting, SIGNAL(bgmAdjust(int)), this, SLOT(bgmAdjust(int)));
    connect(setting, SIGNAL(sfxAdjust(int)), this, SLOT(sfxAdjust(int)));
    //connect(setting, SIGNAL(fullScreen(bool)), this, SLOT(fullScreen(bool)));
    setting->readSettings();
}

void MainWindow::createMenus(){

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(returnAction);


    fileMenu->addAction(quitAction);

    toolMenu = menuBar()->addMenu(tr("&Tools"));
    toolMenu->addAction(settingsAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);


}

void MainWindow::createScene(){
    view = new View;
    title = new Title(view);
    this->soundManager->connectSound(title);
}
void MainWindow::setSize(){
    this->setFixedSize(1280,760);
    int x = ((screenGeometry.width() - this->width()) / 2);
    int y = ((screenGeometry.height() - this->height()) / 2);
    this->move(x, y);
}

void MainWindow::returnTitle(){

    createActions();
    createScene();
    setCentralWidget(view);

}
void MainWindow::save(){


}
void MainWindow::settings(){
    setting->setState();
    setting->show();
}
void MainWindow::bgmAdjust(int volume){
    soundManager->setBGMVolume(volume);
}

void MainWindow::sfxAdjust(int volume){
    soundManager->setSFXVolume(volume);
}
void MainWindow::showAbout(){
    about = new About_Dialog;
    about->exec();
}





