#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QVector>

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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QVector <long long> numbers;
    QVector <QVector<QVector<long long>>> razm_kuh;
    QVector <QVector<QVector<long long>>> sort_kuh;
    void InterSort(QVector<long long> &arr, bool);
    long long binpow(long long, long long, long long);
    long long BinarySearch(const QVector<long long> &arr, long long target);
};
#endif // MAINWINDOW_H
