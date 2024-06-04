#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"
#include "button.h"

#pragma once

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void log(std::string s);
private slots:
    void on_PlayButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
    //GameWindow *gamewindow;
    Game* game;
};
#endif // MAINWINDOW_H
