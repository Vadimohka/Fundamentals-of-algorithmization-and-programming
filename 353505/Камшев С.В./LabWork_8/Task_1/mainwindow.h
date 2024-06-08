#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QMessageBox>
#include "bstree.h"

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
    void recursiveDisplayTree(QStandardItem *parentItem, TreeNode <QString> *node);

private slots:
    void on_bnt_add_item_clicked();

    void on_bnt_remove_clicked();

    void on_bnt_search_clicked();

    void on_bnt_cnt_of_list_clicked();

    void on_bnt_pre_clicked();

    void on_bnt_post_clicked();

    void on_bnt_in_clicked();

    void on_bnt_add_subtree_clicked();

    void on_bnt_remove_subtree_clicked();

    void on_bnt_add_item_2_clicked();

private:
    Ui::MainWindow *ui;
    BSTree <QString> tree;
    BSTree <QString> subTree;
    QStandardItemModel* model;
    QStandardItemModel* subModel;
};
#endif // MAINWINDOW_H
