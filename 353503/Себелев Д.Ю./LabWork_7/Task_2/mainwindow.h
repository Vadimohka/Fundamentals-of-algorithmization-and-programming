#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

#include "bst.h"

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

    void on_find_btn_clicked();

    void on_preOrder_clicked();

    void on_inOrder_btn_clicked();

    void on_postOrder_btn_clicked();

    void on_clear_btn_clicked();

    void on_execTask_btn_clicked();

    void on_balance_btn_clicked();

    void on_getInfo_btn_clicked();

private:
    Ui::MainWindow *ui;
    QTreeWidget *tree;

    BST<QString> bst;
};
#endif // MAINWINDOW_H
