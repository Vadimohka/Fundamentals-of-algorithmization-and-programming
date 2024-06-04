#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    QVector<int> rect;
    int* arr;
    int n;
    int max;

private:
    Ui::MainWindow *ui;

private slots:
    void click_start();

};
#endif // MAINWINDOW_H
