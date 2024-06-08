#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "avltree.h"
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
    void on_preOrder_clicked();

    void on_postOrder_clicked();

    void on_inOrder_clicked();

    void on_levelsButton_clicked();

    void on_insertNodButton_clicked();

    void on_findNodeButton_clicked();

    void on_deleteNodeButton_clicked();

private:
    Ui::MainWindow *ui;
    AVLTree *avlTree;
    QGraphicsScene *scene;

    void drawTree();
    void drawNode(AVLTree::Node *node, qreal x, qreal y, qreal offset);
};
#endif // MAINWINDOW_H
