#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "binarysearchtree.h"
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
    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_findButton_clicked();

    void on_traverseButton_clicked();

    void on_InsertSubtreeButton_clicked();

    void on_RemoveSubtreeButton_clicked();

    void on_FindLCAButton_clicked();

    void on_InsertBranchButton_clicked();

    void on_RemoveBranchButton_clicked();

    void on_InsertAtPositionButton_clicked();

private:
    Ui::MainWindow *ui;
     BinarySearchTree bst;
};
#endif // MAINWINDOW_H
