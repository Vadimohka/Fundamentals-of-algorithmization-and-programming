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

    void calculateMedian(QVector<int> &array);
    int findMedianOfThree(QVector<int> &array);

    void printArr(QVector<int> &array);

public slots:
    void start();

private:
    Ui::MainWindow *ui;
    QVector<int> array;

    void initializeArray();
};
#endif // MAINWINDOW_H
