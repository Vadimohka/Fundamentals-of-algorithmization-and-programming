//
// Created by darina on 3/3/24.
//

#ifndef LAB_MAINWINDOW_H
#define LAB_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <qgraphicsscene.h>
#include "../movingEllipse/movingEllipse.h"
#include "../baloon/baloon.h"
#include "../background/background.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

protected:
    Ui::mainwindow *ui;
    QGraphicsScene *scene;
    baloon *Baloon = new baloon(100, 100);
    Background *background = new Background();

private slots:
    void on_boomButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_closeButton_clicked();
};

#endif //LAB_MAINWINDOW_H
