#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include "segment.h"
#include "rocket.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_timeout();

    void on_go_clicked();

    void on_start_clicked();

    void on_off_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Segment *s;
    Rocket *r0;
    Rocket *r1;
    QTimer *timer;
    int sec = 0;
    int sostoyanie = 0;
};
#endif // MAINWINDOW_H
