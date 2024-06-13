#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Array_BinHeap/array_binheap.h"
#include "List_BinHeap/list_binheap.h"
#include <QStandardItemModel>
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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
    QStandardItemModel* model;

    Array_BinHeap<QString> arrayHeap;
    List_BinHeap<QString> listHeap;

    void display(QStandardItem*, std::shared_ptr<Node<QString>> node);
};
#endif // MAINWINDOW_H
