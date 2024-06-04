#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QEventLoop>
#include <QElapsedTimer>
#include <QMessageBox>

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
protected:
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int m_size = 100;
    int* m_data = nullptr;
    int* arrayForTime = nullptr;
    QElapsedTimer timer;
    int numberForBinarySearch;
    int indexOfNumber;
    bool isSorted;
    bool isNumberGood;


    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
    void mergeSortTime(int l, int r);
    void mergeTime(int l, int m, int r);

    void heapify(int n, int i);
    void heapSort(int n);
    void heapSortTime(int n);
    void heapifyTime(int n, int i);

    int partition(int low, int high);
    void quickSort(int low, int high);
    void quickSortTime(int low, int high);
    int partitionTime(int low, int high);

    int binarySearch();
    void setIndexOfNumber();

    void interpolationSort();
    void interpolationSortTime();

    int binpow(int digit, int powder, int mod);

    void indexInBinpow();

    void printArray();
    void delay(int time);
    void getNumber();
    void lineChanged();
};
#endif // MAINWINDOW_H
