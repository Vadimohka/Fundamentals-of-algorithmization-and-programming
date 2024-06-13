#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
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

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model = new QStandardItemModel(this);
    BST<int> bst;

    void showBST(QStandardItem* parentItem, BST<int>::Node* node);
    void displayBST();
    void add();
    void remove();
    void find();
    void traverse();
    void insertSubBST();
    void removeSubBST();
    void findCommonParent();
};
#endif // MAINWINDOW_H
