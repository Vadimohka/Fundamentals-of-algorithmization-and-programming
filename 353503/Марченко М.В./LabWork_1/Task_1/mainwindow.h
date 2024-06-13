#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <movingellipse.h>
#include <eyes.h>
#include <mouth.h>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow  *ui;
    QGraphicsScene  *scene;
    Eyes   *eyes;
    Mouth   *mouth;
    QGraphicsEllipseItem *ellipse;
    QGraphicsEllipseItem *ellipseGl;
    QGraphicsEllipseItem *ellipseGr;
 };

#endif // MAINWINDOW_H
