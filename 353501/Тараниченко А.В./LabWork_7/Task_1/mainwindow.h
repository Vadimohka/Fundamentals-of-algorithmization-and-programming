#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include "queue.cpp"
#include <QAbstractItemModel>

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

    void print();

private slots:
    void on_pushQ1_clicked();

    void on_popQ1_clicked();

    void on_pushQ2_clicked();

    void on_popQ2_clicked();

    void on_genQ1_clicked();

    void on_genQ2_clicked();

    void on_insertButton_clicked();

private:
    Ui::MainWindow *ui;

    Queue<int> q1;
    Queue<int> q;
};
#endif // MAINWINDOW_H
