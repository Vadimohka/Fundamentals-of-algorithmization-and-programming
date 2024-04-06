#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "wagon.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void moveWagon(int dx); // Объявление нового метода

private:
    QGraphicsScene *scene;
    Wagon *wagon;
    QGraphicsEllipseItem *leftWheel; // Используем QGraphicsEllipseItem для колес
    QGraphicsEllipseItem *rightWheel;
    QPushButton *leftButton;
    QPushButton *rightButton;
};

#endif // MAINWINDOW_H
