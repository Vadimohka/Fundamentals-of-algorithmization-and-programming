#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarysearchtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_searchButton_clicked();
    void on_deleteButton_clicked();
    void on_balanceButton_clicked();
    void on_printInOrderButton_clicked();
    void on_printPreOrderButton_clicked();
    void on_printPostOrderButton_clicked();
    void on_NodesWithTwoChildrenButton_clicked();

private:
    Ui::MainWindow *ui;
    BinarySearchTree bst;
};

#endif // MAINWINDOW_H
