#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_enter_clicked();

    void on_pushButton_restart_clicked();

private:
    long long n, enterI = 0, find;
    QVector<long long> arr;
    long long heapSort(QVector<long long>&, QString &);
    void heapify(QVector<long long>&, long long, long long, long long &);
    long long partition(QVector<long long>&, long long, long long, long long &);
    long long quickSort(QVector<long long> &, long long, long long, QString &);
    long long merge(QVector<long long>&, long long, long long, long long);
    long long mergeSort(QVector<long long> &, long long, long long, QString &);
    long long binSearch(QVector<long long> &, long long);
    void printArr(QVector<long long>, QString, QString &);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
