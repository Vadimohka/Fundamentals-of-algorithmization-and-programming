#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Queue.h"
#include <QListWidget>
#include <QRandomGenerator64>

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
    void on_pushButton_clicked();

    void on_popButton_clicked();

    void on_fillButton_clicked();

    void on_insertButton_clicked();

private:
    void showQueue(QListWidget* showingWidget, Deque<int>& showedQueue);

    Ui::MainWindow *ui;

    Deque<int> deque;
    Deque<int> deque1;
    Deque<int> deque2;
};
#endif // MAINWINDOW_H
