#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<MyQueue.h>
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
    Queue<int> queue;

    Ui::MainWindow *ui;

    void addFrontElement();

    void addBackElement();

    void popBack();

    void popFront();

    void clear();
};
#endif // MAINWINDOW_H
