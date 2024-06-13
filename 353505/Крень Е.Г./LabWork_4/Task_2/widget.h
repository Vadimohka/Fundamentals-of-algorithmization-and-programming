#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void sortAnimation(int, int);
    ~Widget();

private:
    QVector<int> nums = {};
    int delay = 100;
    int size;
    int firstSwitchedElement = 0;
    int secondSwitchedElement = 0;
    int lowPos = -1;
    int midPos = -1;
    int topPos = -1;
    uint64_t swaps = 0;
    uint64_t comparisions = 0;
    uint64_t arrayAccesses = 0;
    void paintEvent(QPaintEvent *event);
    int binarySearch(QVector<int>& arr, int target);
    int binPow(int num, int powder, int mod);
    void InterpolationSort(QVector<int> &arr);
    void heapify(QVector<int>& arr, int n, int i);
    void heapSort(QVector<int>& arr);
    void QSort(QVector<int> &arr, int left, int right);
    void mergeSort(QVector<int>& arr, int l, int r);
    void merge(QVector<int>& arr, int l, int m, int r);
    Ui::Widget *ui;
};
#endif // WIDGET_H
