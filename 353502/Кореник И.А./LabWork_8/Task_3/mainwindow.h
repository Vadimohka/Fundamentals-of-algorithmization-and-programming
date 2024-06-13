#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicstree.h"
#include "rbtree.h"
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
    void on_insertButton_clicked();

    void on_eraseButton_clicked();

    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;

    RBTree<int, QString>* rbTree = nullptr;

    GraphicsTree* binaryTree = nullptr;

    int currentKey;

    QString currentData;

    bool correctKey = false;

    bool correctData = false;

    //void update(bool poisk = false, int value = 0);

    TreeNode* fillTree(RBTree<int, QString>::Node* node);

    void update();
};
#endif // MAINWINDOW_H
