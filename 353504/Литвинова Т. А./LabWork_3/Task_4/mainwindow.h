#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QQueue>
#include <QGraphicsItemAnimation>


#include "hanoi.h"

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

private slots:

    void on_startButton_clicked();
    void on_spinBox_valueChanged(int arg1);

    void on_backButton_clicked();

    void on_forwardButton_clicked();

private:
    Ui::MainWindow *ui;
    hanoi *hanoi_towers;
    //QGraphicsScene* scene;
    QGraphicsView *view;

    int row = 1;

    void nextAnimation();
    void Move(QGraphicsRectItem *disk, QGraphicsRectItem *fromRod, QGraphicsRectItem *toRod);
    //void Move(QGraphicsRectItem *disk, QGraphicsRectItem fromRod, QGraphicsRectItem toRod);
    void moveDisk(int number,char _start,char _finish);
    void updateGraphics();
    void start(int n, char _start, char _temp, char _finish);
};
#endif // MAINWINDOW_H
