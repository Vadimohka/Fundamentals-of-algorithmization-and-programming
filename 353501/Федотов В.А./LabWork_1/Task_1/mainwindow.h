#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include "ui_mainwindow.h"
#include "people.h"
#include "elevator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Rectangle *rectangle;
    Elevator *elevator;
    People *personRed;
    People *personGreen;
    People *personBlue;
    QList<QPushButton*> buttons;

private slots:
    void handleFloor1Clicked();
    void handleFloor2Clicked();
    void handleFloor3Clicked();

    void handleRedClicked();
    void handleGreenClicked();
    void handleBlueClicked();

    void lockButtons();
    void unlockButtons();

};
#endif // MAINWINDOW_H
