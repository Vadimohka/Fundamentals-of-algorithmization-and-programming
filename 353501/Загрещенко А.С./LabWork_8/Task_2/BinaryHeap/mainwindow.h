#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QRandomGenerator64>
#include "BinaryHeapArray.h"
#include "BinaryHeapList.h"

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

private slots:
    void on_insertInArrHeap_clicked();
    void on_extractMaxArrHeap_clicked();
    void on_insertInLisstHeap_clicked();
    void on_extractMaxListHeap_clicked();

private:
    void fillTreeWidgetFromArrHeap(QTreeWidgetItem* treeWidget, int i);
    void displayArrHeap();
    void fillTreeWidgetFromListHeap(QTreeWidgetItem* treeWidget, std::shared_ptr<BinaryHeapList::Node>);
    void displayListHeap();

    Ui::MainWindow *ui;
    BinaryHeapArray arrHeap;
    BinaryHeapList listHeap;
};

#endif // MAINWINDOW_H
