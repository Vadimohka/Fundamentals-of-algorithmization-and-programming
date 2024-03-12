#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include <QtWidgets>
#include <rotatingwheel.h>
#include <road.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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
    QTimer *timer;
    RotatingWheel *wheel;
    Road *road;
    bool isRotating;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void on_pushButton_moveLeft_pressed();

    void on_pushButton_moveLeft_released();

    void on_pushButton_moveRight_pressed();

    void on_pushButton_moveRight_released();

    void moveLeft_slot();

    void moveRight_slot();

    void rotateLeft_slot();

    void rotateRight_slot();
};
#endif // MAINWINDOW_H
