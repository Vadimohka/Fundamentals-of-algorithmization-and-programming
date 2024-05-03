#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "balloon.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    Movingellipse* ellipse;
    Balloon* balloon;
    QTimer* timer2;
public slots:
    void startBurst();
    void burst();
    void stopBurst();
};
#endif  // MAINWINDOW_H
