#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStackedWidget>
#include "gameboard.h"
#include "menu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_game_start_clicked();

    void on_end_game_clicked();

    void showWinners();

    void showRules();

   // void showGameBoard();

    //void showMenu();


private:
    QStackedWidget* stackedWidget;

    QDialog* rulesDialog;

    Menu* menu;

    GameBoard* gameBoard;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
