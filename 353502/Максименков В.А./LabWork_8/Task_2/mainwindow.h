#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <QStandardItemModel>
#include <queue>
#include "bh.h"
#include "bhlist.h"

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

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model = new QStandardItemModel(this);
    BHList<int> bhlist;
    BH<int> bh;

    void showBHList(QStandardItem* parentItem, BHList<int>::Node *node);
    void displayBHList();
    void displayBH();
    void insert();
    void removeMax();

};
#endif // MAINWINDOW_H
