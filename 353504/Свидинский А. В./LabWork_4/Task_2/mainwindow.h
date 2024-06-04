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

public slots:
    void updateData(int newSize);

protected:
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    void heapSort();
    void heapSortTimer();
    void heapify(int n, int i);
    void heapifyTimer(int n, int i);


    void quickSort(int low, int high);
    void quickSortTimer(int low, int high);
    int partition(int low, int high);
    int partitionTimer(int low, int high);

    void mergeSort(int left, int right);
    void mergeSortTimer(int left, int right);
    void merge(int left, int mid, int right);
    void mergeTimer(int left, int mid, int right);

    void interpolationSort();
    void interpolationSortTimer();

    bool isSorted();
    int binsearch(int digit);

    int binpow(int digit, int powder, int mod);

    void printArray();

    int* m_data = nullptr;
    int* tempData = nullptr;
    int m_size = 100;
    QColor* m_colors = nullptr;

    void delay(int millisecondsToWait);

    bool isSorting = false;
    QElapsedTimer timer;
    int index;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
