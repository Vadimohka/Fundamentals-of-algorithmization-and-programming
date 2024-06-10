#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

#include "queue.h"

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

public slots:
    void pushBack();
    void pushFront();
    void popBack();
    void popFront();
    void print();
    void clear();
    void front();
    void back();
    void executeTask();

private:
    Ui::MainWindow *ui;

    Queue<int> queue;

    Queue<int> mainQueue;
    Queue<int> negativeQueue;
    Queue<int> positiveQueue;
};
#endif // MAINWINDOW_H
