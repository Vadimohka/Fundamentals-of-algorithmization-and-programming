#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>

#include "avl.h"

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
    void on_On_insert_clicked();

    void on_On_print_forward_clicked();

    void on_On_balance_clicked();

    void on_On_find_clicked();

    void on_On_delete_clicked();

    void on_On_clear_clicked();

    void on_On_print_reverse_clicked();

    void on_On_MaxDepth_clicked();

private:
    Ui::MainWindow *ui;
    QString n = "AA";
    int t = 5;
    QTreeWidget* tree;
    AVL<QString> AVL_tree;
};
#endif // MAINWINDOW_H
