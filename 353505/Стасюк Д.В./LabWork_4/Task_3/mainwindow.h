#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <random>
#include "median_treaples.h"

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
    void fillVectorWithRandom(QVector<long long> &vec, int count);

private slots:
    void on_random_clicked();

    void on_get_new_array_clicked();

private:
    Ui::MainWindow *ui;
    QVector<long long> start_vector;
};
#endif // MAINWINDOW_H
