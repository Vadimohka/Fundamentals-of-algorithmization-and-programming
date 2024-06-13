#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVector>
#include <QElapsedTimer>
#include <algorithm>

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

    QString vectorToString(const QVector<int> &arr);
    void interpolationSort(QVector<int> &arr);
    int binpow(int digit, int powder, int mod);

private slots:
    void on_sortButton_clicked();

    void on_bin_powButton_clicked();

private:
    QVector<int> arr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
