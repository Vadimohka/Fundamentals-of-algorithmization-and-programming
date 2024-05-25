#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QWidget>
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

    void on_buttonbin_clicked();

private:
    Ui::MainWindow *ui;

    void redirection1 (int arr[], int size);
    void redirection2 (int arr[], int size);
    void redirection3 (int arr[], int size);

    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);
    void printArray(int arr[], int n);
    void qsortRecursive(int *mas, int size);
    void merge(int array[], int const left, int const mid, int const right);
    void mergeSort(int array[], int const begin, int const end);
    void binsearch();
};
#endif // MAINWINDOW_H
