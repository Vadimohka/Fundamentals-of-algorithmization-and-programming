#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <treeextension.h>
#include <QTreeView>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_order_clicked();

    void on_pushButton_reverse_clicked();

    void on_pushButton_byValue_clicked();

    void on_pushButton_balance_clicked();

    void on_pushButton_minMaxSwap_clicked();

private:
    Ui::MainWindow *ui;

    TreeExtension tree;
    void showTree(QStandardItem*, Node*);
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
