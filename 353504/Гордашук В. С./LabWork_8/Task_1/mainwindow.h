#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "bst.h"
#include "qtreewidget.h"

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
    BST tree;
    void toQTreeWidget(QTreeWidget *treeWidget, Node *node, QTreeWidgetItem *parentItem = nullptr);

private slots:
    void on_add_clicked();
    void on_pushButton_2_clicked();
    void on_removetree_clicked();
    void on_find_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
