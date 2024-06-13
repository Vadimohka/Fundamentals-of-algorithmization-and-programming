#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "avl_tree.h"
#include "graphics_tree.h"
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

    void on_balanceButton_clicked();

private:
    Ui::MainWindow *ui;

    AVL_Tree* avl_tree;

    int currentKey;

    QString currentData;

    bool correctKey = false;

    bool correctData = false;

    void update(bool poisk = false, int value = 0);

    TreeNode* fillTree(Node* node);

    GraphicsTree* binaryTree = nullptr;

    void findAnimation(Node* node, int key);

    int hight;
};
#endif // MAINWINDOW_H
