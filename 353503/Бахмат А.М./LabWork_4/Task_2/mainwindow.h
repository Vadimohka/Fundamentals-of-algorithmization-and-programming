#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonMerge_clicked();
    void on_pushButtonBubbe_clicked();
    void on_pushButtonQuick_clicked();
    void on_pushButtonHeap_clicked();
    void on_pushButtonMerge_2_clicked();
    void on_pushButtonFindElement_clicked();
    void on_pushButtonInter_clicked();

public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    long long *a;
    long long time = 0;
    bool isPossibleSort;

    void drawArray(long long *a);
    void findedElement(long long pos, long long value);
    void randomMerger(long long *a);
    void sortBubble(long long *a);
    void quickSort(long long *a, long long start, long long end);
    void heapify(long long *a, long long n, long long i);
    void heapSort(long long *a);
    void merge(long long *a, long long left, long long mid, long long right);
    void mergeSort(long long *a, long long begin, long long end);
    void interpolationSort(long long *a, long long low, long long high);
    bool isSorted(long long *a);
    long long partition(long long *a, long long start, long long end);
    long long BinSearch(long long value, long long l, long long mid, long long r);
    long long BinPow(long long num, long long pow, long long mod);
};

#endif // MAINWINDOW_H
