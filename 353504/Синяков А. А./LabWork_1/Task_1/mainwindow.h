#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "animatedrectangle.h"

#include <QMainWindow>

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
    void on_Up_clicked();



    void on_Down_clicked();



private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Rectangle *rectangle;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
