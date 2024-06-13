#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MyDequeue.h>


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
    MyDeque<int> deque;

    void clear();

    void isEmpty();

    void pushBack();

    void pushFront();

    void popBack();

    void popFront();

    void getElement();

};
#endif // MAINWINDOW_H
