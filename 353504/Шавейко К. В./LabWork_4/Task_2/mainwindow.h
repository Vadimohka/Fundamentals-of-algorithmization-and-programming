// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_interpolation_Sort_clicked();

    void on_binpow_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<int> array;
    void   interpolationSort(const std::vector<int>& arr,int first,int last);
    void printArray(const std::vector<int>& arr);
    void _interpSort(std::vector<int>& arr, size_t beg, size_t end);
    int  binpow(int digit, int power, int mod);
    int  binarySearch(const std::vector<int>& arr, int digit);
    std::vector<int> sortedArray;
};

#endif // MAINWINDOW_H
