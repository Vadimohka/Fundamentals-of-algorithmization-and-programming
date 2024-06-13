#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

#include "binarysearchtree.h"

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

    void addNode();

private slots:
    void on_insert_btn_clicked();

    void on_remove_btn_clicked();

    void on_find_btn_clicked();

    void on_preorder_btn_clicked();

    void on_inorder_btn_clicked();

    void on_postorder_btn_clicked();

    void on_lowAnces_btn_clicked();

private:
    Ui::MainWindow *ui;
    BinarySearchTree<int> bst;

    QTreeWidget *tree;
};
#endif // MAINWINDOW_H
