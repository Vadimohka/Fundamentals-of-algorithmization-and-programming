#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarytree.h"

class QPushButton;
class QTextEdit;
class QLineEdit;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addNode();
    void removeNode();
    void findNode();
    void traverseTree();
    void insertSubtree();
    void removeSubtree();
    void insertBranch();
    void removeBranch();
    void findLCA();

private:
    BinaryTree tree;
    QTextEdit *output;
    QLineEdit *inputData;
    QLineEdit *inputKey;
    QLineEdit *inputKey2;
    QLineEdit *inputParentKey;

    void updateOutput(const QString &message);
};

#endif // MAINWINDOW_H
