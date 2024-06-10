#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "static_lib/arrayheap.h"
#include "lib/listheap.h"
#include <QMainWindow>
#include <QStandardItemModel>

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
    void on_pushButton_push_clicked();

    void on_pushButton_pop_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_push_2_clicked();

    void on_pushButton_pop_2_clicked();

    void on_pushButton_clear_2_clicked();

private:
    Ui::MainWindow *ui;
    ArrayHeap arr;
    ListHeap list;
    QStandardItemModel * model;
    void displayTree(QStandardItem* parentItem, std::shared_ptr<ListNode> node);

};
#endif // MAINWINDOW_H
