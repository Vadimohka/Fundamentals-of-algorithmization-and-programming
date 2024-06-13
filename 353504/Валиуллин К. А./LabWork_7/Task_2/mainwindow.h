#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "bst.h"
#include "deletingbranchbst.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNodeButton_clicked();
    void on_balanceTreeButton_clicked();
    void on_findNodeButton_clicked();
    void on_deleteNodeButton_clicked();
    void on_directBypassButton_clicked();
    void on_reverseBypassButton_clicked();
    void on_ascendingBypassButton_clicked();
    void on_deleteBranchButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    deletingBranchBST *bst;

    void displayTree(QStandardItem *parentItem, BSTNode *node);
};

#endif // MAINWINDOW_H
