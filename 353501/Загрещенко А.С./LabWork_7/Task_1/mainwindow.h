#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Queue.h"
#include <QTableWidget>
#include <random>
#include <ctime>
#include <QMessageBox>

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

    void showQueue(int index_of_max=-1);
private slots:
    void on_gen1_clicked();

    void on_pop_clicked();

    void on_push_clicked();

    void on_clear_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    queue<int>q1,q2;
    std::mt19937 gen;
};
#endif // MAINWINDOW_H

