#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTextEdit;
class QLabel;
class QSpinBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEnterClicked();
    void onRestartClicked();

private:
    Ui::MainWindow *ui;
    QVector<long long> arr;
    QPushButton *pushButtonEnter;
    QPushButton *pushButtonRestart;
    int n;
    int enterI;
    int find;
    QTextEdit *textEdit;
    QLabel *labelN;
    QLabel *labelSpeed;
    QLabel *labelAns;
    QLabel *messageLabel;
    QSpinBox *spinBox;

    void printArr(QVector<long long> arr, QString pref, QString &out);
    void heapify(QVector<long long>& arr, long long n, long long i, long long &count);
    long long heapSort(QVector<long long> &arr, QString &text);
    long long partition(QVector<long long>& arr, long long start, long long end, long long &countSt);
    long long quickSort(QVector<long long> &arr, long long low, long long high, QString &text);
    long long merge(QVector<long long>& arr, long long l, long long m, long long r);
    long long mergeSort(QVector<long long> &arr, long long l, long long r, QString &text);
    long long binSearch(QVector<long long> &a, long long find);
};

#endif // MAINWINDOW_H


