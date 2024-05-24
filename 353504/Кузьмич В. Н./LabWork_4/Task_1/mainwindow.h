#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QVector>
#include <QElapsedTimer>

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
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString input = "";
    QVector<long long> numbers;
    QVector<long long> numbersHeapSort;
    QVector<long long> numbersQuickSort;
    QVector<long long> numbersMergeSort;
    void HeapSort(QVector<long long> &arr);
    void heapify(QVector<long long> &arr, long long n, long long i);
    long long partition(QVector<long long> &array, long long low, long long high);
    void QuickSort(QVector<long long> &array, long long low, long long high);
    void MergeSort(QVector<long long> &arr, long long l, long long r);
    void merge(QVector<long long> &arr, long long p, long long q, long long r);
    long long BinarySearch(const QVector<long long> &arr, long long target);
    QElapsedTimer timer;
};
#endif // MAINWINDOW_H
