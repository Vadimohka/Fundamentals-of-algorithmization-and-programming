#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rectangle.h"
#include "sort.h"
#include <QThreadPool>
#include <QRunnable>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Rectangle;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<Rectangle*> rect;
    QVector<Rectangle*> rect1;
    QVector<Rectangle*> rect2;
    int* arr;
    int* arr1;
    int* arr2;
    int n;
    int max;

private:
    Ui::MainWindow *ui;

private slots:
    void click_start();
    void click_search();

};
#endif // MAINWINDOW_H
