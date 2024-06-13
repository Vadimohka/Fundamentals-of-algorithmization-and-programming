#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>

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
    ~Widget();
    void update();
    void quickSort(QVector<int>& arr, int left, int right);
    void mergeSort(QVector<int>& arr, int left, int right);
    void heapify(QVector<int>& nums, int n, int i);
    void heapSort(QVector<int>& nums);
    void shuffle(QVector<int>& vector);
    int binarySearch(QVector<int>& nums, int target);
private slots:
    void on_clearPushButton_clicked();

    void on_addPushButton_clicked();

    void on_pushButton_clicked();

    void on_shufflePushButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::Widget *ui;
    QVector<int> vector;
};
#endif // WIDGET_H
