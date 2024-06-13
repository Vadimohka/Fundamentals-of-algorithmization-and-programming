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

    QStandardItem* createItemForNode(std::shared_ptr<Node> root, const QString& position = "");
    void preorderTraversal(std::shared_ptr<Node> node);
    void postorderTraversal(std::shared_ptr<Node> node);
    void inorderTraversal(std::shared_ptr<Node> node);

private slots:
    void on_addBtn_clicked();
    void on_deleteBtn_clicked();
    void on_findBtn_clicked();
    void on_minBtn_clicked();
    void on_maxBtn_clicked();
    void on_inorderBtn_clicked();
    void on_preorderBtn_clicked();
    void on_postorderBtn_clicked();
    void on_insertSubtreeBtn_clicked();
    void on_insertBranchBtn_clicked();
    void on_removeSubtreeBtn_clicked();
    void on_removeBranchBtn_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Node> root_;
    QStandardItemModel* model;
    BST bst;

    void updateTreeView();
};
#endif // MAINWINDOW_H


