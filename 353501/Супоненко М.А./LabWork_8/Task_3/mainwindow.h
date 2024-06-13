#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "redblacktree.h"
#include "treeviewwidget.h"
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
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void updateTreeView();
    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;
    RedBlackTree tree;
    void findAndUpdateTreeView(int value);
};

#endif // MAINWINDOW_H
