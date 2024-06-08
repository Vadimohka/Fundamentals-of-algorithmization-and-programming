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
    void on_elemnumspinBox_valueChanged(int arg1);

private:
    QVector<long long> calculatemedians(QVector<long long>);
    static void quickSort(QVector<long long>& palki, int low, int high);
    static int partition(QVector<long long>& palki, int low, int high);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
