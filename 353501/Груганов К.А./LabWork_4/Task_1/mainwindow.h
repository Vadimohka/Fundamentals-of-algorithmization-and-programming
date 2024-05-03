#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e) override;
    void generRandomArr(int size);
    bool isSorted();
    void color();
    void colorElement();

    void MergeSort(QVector<int> &arr, int l, int r);
    void merge(QVector<int> &arr, int l, int m, int r);

    void QuickSort(QVector<int> &arr, int low, int high);
    int partition(QVector<int> &arr, int low, int high);

    void heapify(QVector<int> &arr, int n, int i);
    void HeapSort(QVector<int> &, int n);

    int binsearch(QVector<int> &, int size, int digit);
private slots:

    void on_sort_clicked();

    void on_restart_clicked();

    void changeArrSize();

    void on_searchButton_clicked();

private:
    int leftIndex;
    int rightIndex;
    int currIndex;
    QElapsedTimer *timer;
    bool isPaintingGreen = false;
    int delay;
    int index;
    bool stop = false;
    QGraphicsScene *scene;
    QVector<int> arr;
    QVector<QGraphicsRectItem *> rects;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
