#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "bst.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();
    void on_searchButton_clicked();
    void on_deleteButton_clicked();
    void on_balanceButton_clicked();
    void on_inorderButton_clicked();
    void on_preorderButton_clicked();
    void on_postorderButton_clicked();

private:
    void updateTreeView();
    void updateTextEdit(const std::vector<std::string>& data);

    BST bst;
    QTreeWidget* treeWidget;
    QTextEdit* textEdit;
    QLineEdit* keyLineEdit;
    QLineEdit* dataLineEdit;
};

#endif // MAINWINDOW_H
