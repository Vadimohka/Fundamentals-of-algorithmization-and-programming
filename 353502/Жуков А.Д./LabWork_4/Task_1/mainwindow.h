#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QElapsedTimer>
#include <QStringList>
#include <QDebug>

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

private:
    QElapsedTimer * timer;
    QList<int> list;

    void heapSort(QList<int> &);
    void quickSort(QList<int> &);
    void mergeSort(QList<int> &);
    int binSeacrh(QList<int> &, const int);

    void mergeSort(QList<int> &, int, int);
    void merge(QList<int> &, int, int, int);

    void quickSort(QList<int> &array, int low, int high);
    int partition(QList<int> &array, int low, int high);

    void heapify(QList<int> &array, int, int);

private slots:
    void on_sortButton_clicked();

    void on_sortButton_2_clicked();

    void on_sortButton_3_clicked();

    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
