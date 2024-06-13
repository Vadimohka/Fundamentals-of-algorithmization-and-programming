#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeView>
#include <QStandardItem>
#include "priorityqueue.h"

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
    void display(PriorityQueue<int>& priorityQueue);

private slots:
    void on_bnt_add_item_clicked();

    void on_bnt_remove_clicked();

    void on_bnt_getMax_clicked();

    void on_bnt_getMin_clicked();

private:
    Ui::MainWindow *ui;
    PriorityQueue <int> binHeap;
};
#endif // MAINWINDOW_H
