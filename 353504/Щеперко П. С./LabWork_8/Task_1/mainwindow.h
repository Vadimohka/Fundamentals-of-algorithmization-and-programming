#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binary_search_tree.h"

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

    void printTree(BinarySearchTree *tree, QTreeWidget* treeWidget);

private slots:
    void on_addButton1_clicked();

    void on_removeButton1_clicked();

    void on_findButton1_clicked();

    void on_addButton2_clicked();

    void on_removeButton2_clicked();

    void on_insertSubtreeButton_clicked();

    void on_removeSubtreeButton_clicked();

    void on_insertLBranchButton_clicked();

    void on_insertRBranchButton_clicked();

    void on_removeLBranchButton_clicked();

    void on_removeRBranchButton_clicked();

    void on_lowestCommonAncestorButton_clicked();

private:
    Ui::MainWindow *ui;
    BinarySearchTree tree;
    BinarySearchTree* subTree;
};
#endif // MAINWINDOW_H
