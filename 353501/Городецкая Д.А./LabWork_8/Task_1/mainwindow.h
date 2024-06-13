#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include "bst.h"

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
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_findButton_clicked();
    void on_traverseButton_clicked();
    void on_balanceButton_clicked();
    void on_removeSubtreeButton_clicked();
    void on_lcaButton_clicked();

private:
    Ui::MainWindow *ui;
    BST t;
    int key;
    QString str;

    void showTree();
    void updWidget(QTreeWidgetItem *anc, node *v);
    bool check_key();
    bool check_str();
};

#endif // MAINWINDOW_H
