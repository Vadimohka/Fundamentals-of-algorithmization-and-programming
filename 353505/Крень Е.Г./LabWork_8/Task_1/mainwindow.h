#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QMessageBox>
#include "BinSearchTree.h"

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
    void recursiveDisplayTree(QStandardItem *parentItem, BinSearchTree<int>::node* node);

private slots:
    void on_add1_push_button_clicked();

    void on_add2_push_button_clicked();

    void on_delete_push_button_clicked();

    void on_find_push_button_clicked();

    void on_find_root_push_button_clicked();

    void on_traverse_button_clicked();

    void on_add_subtree_push_button_clicked();

    void on_delete_subtree_push_button_clicked();

private:
    Ui::MainWindow *ui;
    BinSearchTree <int> tree;
    BinSearchTree <int> subTree;
    QStandardItemModel* model;
    QStandardItemModel* subModel;
};
#endif // MAINWINDOW_H
