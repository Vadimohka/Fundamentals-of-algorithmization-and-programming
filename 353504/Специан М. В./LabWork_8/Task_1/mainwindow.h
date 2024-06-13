#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bst.h"
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

    void on_pushButton_remove_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_traverse_clicked();

    void on_pushButton_commonNode_clicked();

    void on_pushButton_addSub_clicked();

    void on_pushButton_addToSub_clicked();

    void on_pushButton_removeFromSub_clicked();

    void on_pushButton_removeSub_clicked();

    void on_pushButton_left1_clicked();

    void on_pushButton_right1_clicked();

    void on_pushButton_root1_clicked();

    void on_pushButton_left2_clicked();

    void on_pushButton_right2_clicked();

    void on_pushButton_root2_clicked();

private:
    Ui::MainWindow *ui;
    BST<long> bst, sub;
    Node<long>* node1 = nullptr, * node2 = nullptr;
    QStandardItemModel* model, * subModel;

    void display(QStandardItem* parent, Node<long>* node);
};
#endif // MAINWINDOW_H
