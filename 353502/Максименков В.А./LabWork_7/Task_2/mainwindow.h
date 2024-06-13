#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
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
    void add();

    void del();

    void find();

    void InOrder();

    void PreOrder();

    void PostOrder();

    void balanse();

    void subtree();

private:
    Ui::MainWindow *ui;
    MyTree tree;
    void displayTree(QStandardItem* parentItem, TreeNode* node);
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
