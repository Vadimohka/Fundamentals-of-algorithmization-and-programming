#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <circlemoving.h>
#include <QGraphicsEllipseItem>
#include <QPushButton>
#include <QTimer>
#include <circlerotation.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene *scene ;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CircleMoving* circleMove;
    CircleRotation* circleRotate;
    QPainter* painter;
    void movingCircle();
};
#endif // MAINWINDOW_H
