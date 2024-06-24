#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqueue.h"
#include "QLabel"

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
    void on_PUSH_clicked();

    void on_POP_clicked();

    void on_FRONT_clicked();

    void on_SIZE_clicked();

    void on_ISEMPTY_clicked();

    void on_BACK_clicked();

    void on_RANDOMRANDOM_clicked();

    void on_FUNCT_clicked();

private:
    Ui::MainWindow *ui;
    MyQueue* queue = new MyQueue();
};
#endif // MAINWINDOW_H
