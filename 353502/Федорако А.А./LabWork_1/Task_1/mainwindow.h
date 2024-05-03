#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "background.h"
#include "ui_mainwindow.h"
#include "plane.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private slots:
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer* timerForUpdateScene;
private slots:

    void on_ButtonChassis_clicked();


    void on_ButtonUp_pressed();

    void on_ButtonUp_released();

    void on_ButtonLeft_pressed();

    void on_ButtonLeft_released();

    void on_ButtonRight_pressed();

    void on_ButtonRight_released();

    void on_ButtonDown_pressed();

    void on_ButtonDown_released();

private:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    Ui::MainWindow *ui;
    Plane *plane;
    Background *background;
    QGraphicsScene *scene;
    QTimer *timerForButtonLeft;
    QTimer *timerForButtonRight;
    QTimer *timerForButtonUp;
    QTimer *timerForButtonDown;
};
#endif // MAINWINDOW_H
