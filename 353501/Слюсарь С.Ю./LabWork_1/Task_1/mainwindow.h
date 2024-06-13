#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsView>
#include "car.h"


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

    Car *car;


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPushButton *RightButton;
    QPushButton *LeftButton;
    QPushButton *Lights;
    QPushButton *DoorOpen;
    QTimer *animationTimer;
    QTimer *animationTimerBack;

public slots:
    void RightButton_clicked();
    void LeftButton_clicked();
};
#endif // MAINWINDOW_H
