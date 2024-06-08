#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Deque<int> deque;
};
#endif // MAINWINDOW_H
