#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tree.h"
#include "qstandarditemmodel.h"
#include <QMainWindow>

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
    MainWindow(Ui::MainWindow *ui, BinarySearchTree<int> tree,
               BinarySearchTree<int> subTree, QStandardItemModel *model,
               QStandardItemModel *model1)
        : ui(ui), tree(std::move(tree)), subTree(std::move(subTree)),
        model(model), model1(model1) {}
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_add_to_sub_clicked();

    void on_pushButton_add_sub_clicked();

    void on_pushButton_del_sub_clicked();

    void on_pushButton_traverse_clicked();

    void on_pushButton_1_left_clicked();

    void on_pushButton_1_right_clicked();

    void on_pushButton_1_root_clicked();

    void on_pushButton_2_left_clicked();

    void on_pushButton_2_right_clicked();

    void on_pushButton_2_root_clicked();

    void on_pushButton_lcr_clicked();

    void on_pushButton_rem_sub_clicked();

private:
    Ui::MainWindow *ui;
    BinarySearchTree<int> tree, subTree;
    Node<int> * ptr1 = nullptr, * ptr2 = nullptr;
    void displayTree(QStandardItem* parentItem, Node<int> * node);
    QStandardItemModel * model, * model1;
};
#endif // MAINWINDOW_H
