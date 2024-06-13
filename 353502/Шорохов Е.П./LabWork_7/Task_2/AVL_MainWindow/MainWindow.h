//
// Created by shosh on 5/29/24.
//

#ifndef LABWORK_7_MAINWINDOW_H
#define LABWORK_7_MAINWINDOW_H

#include "QIntValidator"
#include "QLineEdit"
#include "QMainWindow"
#include "QTreeWidget"
#include "QTreeWidgetItem"
#include "QToolBar"
#include "QPushButton"
#include "../AWL/Node.h"

class MainWindow : public QMainWindow {
    int count_of_inserted = 0;
    Node *Root = nullptr;
    QTreeWidget *Central = new QTreeWidget;
    QToolBar *Tools = new QToolBar;
    QPushButton *AddNode = new QPushButton;
    QLineEdit *EnterKey = new QLineEdit;
public:
    MainWindow(Node* node);
};


#endif //LABWORK_7_MAINWINDOW_H
