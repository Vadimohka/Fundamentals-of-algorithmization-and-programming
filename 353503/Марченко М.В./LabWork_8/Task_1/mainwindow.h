#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <bst.h>
//#include <taskbst.h>

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

public slots:
    void addNode();
    void addNewNode();
    void addTree();
    void searchNode();
    void removeNode();
    void printPreorder1();
    void printInorder1();
    void printPostorder1();
    void clearTree();
    void balanceTree();
    void removeTree();
    void task();
    void findAnc();
private:
    void updateTreeWidget();
    void updateTreeWidget1();
    void updateTreeWidgetRecursive(Node* node, QTreeWidgetItem* parentItem = nullptr);
    void updateTreeWidgetRecursive1(Node* node, QTreeWidgetItem* parentItem = nullptr);

    BST m_bst;
    BST new_bst;
    Node* m_root = nullptr;
    Node* new_root = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
