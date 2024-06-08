//
// Created by darina on 5/30/24.
//

#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include <QWidget>
#include "avltree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;

    Tree A, B;
    void Display();

public slots:

    void A_insert();
    void A_remove();
    void A_find();

    void B_insert();
    void B_remove();
    void B_find();

    void traverse_1();
    void traverse_2();
    void traverse_3();
    void traverse_4();
    void traverse_5();
    void traverse_6();

    void delete_subtree();
    void delete_ltree();
    void delete_rtree();

    void add_subtree();
    void add_ltree();
    void add_rtree();

    void lca_clicked();

};


#endif //TASK1_MAINWINDOW_H
