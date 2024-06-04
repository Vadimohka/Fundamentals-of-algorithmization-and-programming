//
// Created by darina on 5/8/24.
//

#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox>
#include <qgraphicsscene.h>
#include <QTimer>
#include "../ArrayOperations/ArrayOperations.h"
#include "../Rectangle/Rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

protected:
    Ui::mainwindow *ui;
    QGraphicsScene *scene;

private:
    int* a;
    int cur = 0;
    int n;
    std::vector<std::vector<int> > steps;
    void StartArray();
    QVector <Rectangle*> array_draw;
    int d;
    int mn;

private slots:
    void do_sort_clicked(int type);
    void do_binary_search_clicked();
    void set_enable();
    void next_step_clicked();
    void close_clicked();
};

#endif //TASK1_MAINWINDOW_H
