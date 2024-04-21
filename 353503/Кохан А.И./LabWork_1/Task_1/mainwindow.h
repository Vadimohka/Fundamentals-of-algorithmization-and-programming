#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"
#include "stopbutton.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    lift* myLift;
    QTimer* timer;
    QRadioButton *RadioFloor_1, *RadioFloor_2, *RadioFloor_3, *RadioFloor_4;
    StopButton* stopButton;

private slots:
    void moveLift();
};
#endif // MAINWINDOW_H
