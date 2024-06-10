#ifndef L8_T1_MAINWINDOW_H
#define L8_T1_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <ui_MainWindow.h>
#include "AVLTree.h"
#include "Widget.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void add();

    void addNode();

    void remove();

    void create();

    void find();

    void findCommonParent();

    void post();

    void pre();

private:
    Ui::MainWindow *ui;
    Widget *widget;
    Node *treeNode;

    QLabel* label;
    QLineEdit* keyInput;
    QPushButton* createButton;
    QPushButton* addButton;
    QPushButton* addNodeButton;
    QPushButton* findButton;
    QPushButton* findCommonParentButton;
    QPushButton* removeButton;
    QPushButton* preButton;
    QPushButton* postButton;

    void updateTreeView();
};


#endif //L8_T1_MAINWINDOW_H
