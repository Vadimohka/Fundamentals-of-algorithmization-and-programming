#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphics_tree.h"
#include "binarytree.h"

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
    void on_insertButton_2_clicked();

    void on_findButton_clicked();

    void on_insertButton_clicked();

    void on_eraseButton_clicked();

private:
    Ui::MainWindow *ui;

    int currentKey;

    QString currentData;

    bool correctKey = false;

    bool correctData = false;

    BinaryTree<QString>* Tree1;
    BinaryTree<QString>* Tree2;

    GraphicsTree* grahicsTree1 = nullptr;
    GraphicsTree* grahicsTree2 = nullptr;

    TreeNode* fillTree(BinaryTree<QString>::Node* node);

    void update1(bool poisk = false, int value = 0);
    void update2(bool poisk = false, int value = 0);

    void findAnimation(BinaryTree<QString>::Node* node, int key);
};
#endif // MAINWINDOW_H
