#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AVL_Tree.h"

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
    void on_pushButton_del_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_InOrder_clicked();

    void on_pushButton_PreOrder_clicked();

    void on_pushButton_PostOrder_clicked();

    void on_pushButton_leftBranch_clicked();

    void on_pushButton_balanse_clicked();

private:
    Ui::MainWindow *ui;
    AVL_Tree* tree;
};
#endif // MAINWINDOW_H
