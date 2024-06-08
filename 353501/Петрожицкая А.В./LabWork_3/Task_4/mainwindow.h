#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QCoreApplication>
#include "towerwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int N = 3;
private slots:

    void moveDisc(int number, int source, int target);
    void startClicked();
    void onSpinBoxValueChanged(int arg1);
    void RestartButClicked();
    void start(int n, int source, int auxiliary, int target);
    void ValueOfSpin(int arg);

    void on_speed_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    towers *towerOfHanoi;
};

#endif // MAINWINDOW_H
