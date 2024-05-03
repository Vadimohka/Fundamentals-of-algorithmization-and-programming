#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "movingrect.h"
#include "movingcart.h"
#include "QVector"
#include "QMouseEvent"
#include "myscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MovingCart *movCart;
    void moveObject();
    void mousePressEvent(QMouseEvent *event);
    MyScene *scene;
    void SlotMouseMoveEvent(QGraphicsSceneMouseEvent *event);

};
#endif // MAINWINDOW_H
