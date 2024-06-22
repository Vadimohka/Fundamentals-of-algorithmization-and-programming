#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QTreeView>
#include <QStandardItemModel>
#include <QTextStream>
#include "extendedbinarysearchtree.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsertButtonClicked();
    void onSearchButtonClicked();
    void onRemoveButtonClicked();
    void onPrintInOrderButtonClicked();
    void onPrintPreOrderButtonClicked();
    void onPrintPostOrderButtonClicked();
    void onCountLeftNodesButtonClicked();

private:
    ExtendedBinarySearchTree tree;
    QLineEdit *keyLineEdit;
    QLineEdit *dataLineEdit;
    QTextEdit *outputTextEdit;
    QTreeView *treeView;
    QStandardItemModel *treeModel;

    void setupUi();
    void updateTreeView();
    void addNodeToModel(QStandardItem *parentItem, BinarySearchTree::Node *node);
};

#endif // MAINWINDOW_H
