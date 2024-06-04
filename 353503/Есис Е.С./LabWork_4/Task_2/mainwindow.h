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
    Ui::MainWindow *ui;
    long long n, enterI = 0, find, mod;
    QVector<long long> arr;
    void printArr(QVector<long long>, QString, QString &);
    unsigned long long binpow(unsigned long long, unsigned long long, unsigned long long);
    unsigned long long bin_mul(unsigned long long, unsigned long long, unsigned long long);
    long long binSearch(QVector<long long>&, long long);
    void interpolationSort(QVector<long long>&, QString&);
    void divide(QVector<long long>& A, QVector<long long>& divideSize, int & end);
};
#endif // MAINWINDOW_H
