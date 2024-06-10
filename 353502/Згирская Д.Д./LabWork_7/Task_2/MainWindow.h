//
// Created by zgdarya on 5/29/24.
//

#ifndef L7_T2_MAINWINDOW_H
#define L7_T2_MAINWINDOW_H

#include <QMainWindow>
#include "AVLTree.h"
#include "widget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_createButton_clicked();

    void on_containButton_clicked();

    void on_postButton_clicked();

    void on_preButton_clicked();

    void on_increaseButton_clicked();

private:
    Ui::MainWindow *ui;
    Widget *widget;
    Node *treeNode;

    void updateTreeView();
};


#endif //L7_T2_MAINWINDOW_H
