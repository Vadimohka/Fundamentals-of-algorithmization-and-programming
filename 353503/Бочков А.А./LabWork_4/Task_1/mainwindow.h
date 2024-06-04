#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int binsearch(int *, int, int);
    void heapify(int *, int, int);
    void HeapSort(int, int *);
    void Merge(int *, int, int);
    void MergeSort(int *, int, int);
    int partition(int *, int, int);
    void QuickSort(int *, int, int);
    void divide(int *, std::vector<int> &, int);
    void interpolationSort(int *, int);
    int binpow(int, int, int);
    int i, n, x;
    int *a, *b;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
