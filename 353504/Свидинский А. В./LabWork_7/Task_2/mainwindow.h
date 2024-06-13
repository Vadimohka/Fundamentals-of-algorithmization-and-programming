#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytree.h"
#include "qstandarditemmodel.h"
#include "qtreeview.h"
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
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_InOrder_clicked();

    void on_pushButton_PreOrder_clicked();

    void on_pushButton_PostOrder_clicked();

    void on_pushButton_eachLevel_clicked();

    void on_peth_clicked();

    void on_pushButton_balance_clicked();

private:
    Ui::MainWindow *ui;
    MyTree tree;
    void displayTree(QStandardItem* parentItem, TreeNode* node);
    QStandardItemModel * model;
};
#endif // MAINWINDOW_H
