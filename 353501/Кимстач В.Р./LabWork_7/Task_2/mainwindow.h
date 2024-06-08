#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarytree.h"

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
    void on_buildTreeButton_clicked();
    void on_balanceTreeButton_clicked();
    void on_addNodeButton_clicked();
    void on_findNodeButton_clicked();
    void on_removeNodeButton_clicked();
    void on_printOrderButton_clicked();
    void on_swapMaxMinButton_clicked();

private:
    Ui::MainWindow *ui;
    BinaryTree tree;
    QStringList data;
    QList<int> keys;

    void updateTreeView(const QStringList& treeData);
};

#endif // MAINWINDOW_H
