#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "heapsorting.h"
#include "sortinganimation.h"
#include "mergesorting.h"
#include "quicksorting.h"
#include "interpolationsorting.h"
#include "random"
#include "binaryalgorithms.h"
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
    void on_sortStarting_clicked();

    void on_addButton_clicked();

    void on_generateButton_clicked();



    void on_sortStartHeap_clicked();

    void on_sortStartmerge_clicked();

    void on_sortStaringinterpolation_clicked();

    void on_searching_clicked();

private:
    Ui::MainWindow *ui;

    QVector<int> array;

    //QVector<int>arrayForAnimation;

    SortingAnimation* sortingAnimation;

    //void animation(QVector<QPair<int, int>>*);

    //QVector<QPair<int, int>>swap;
    bool sorted = false;



};
#endif // MAINWINDOW_H
