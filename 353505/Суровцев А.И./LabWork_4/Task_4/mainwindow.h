#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <random>
#include <QMessageBox>
#include "my_vector.cpp"

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
    void fillVectorWithRandom(My_vector<long long>& vec, int count);
    void createLabelVector(const My_vector<long long> &data);

private slots:
    void on_bnt_random_clicked();

    void on_bnt_erase_clicked();

    void on_bnt_max_size_clicked();

    void on_bnt_pop_back_clicked();

    void on_bnt_push_back_clicked();

    void on_bnt_reserve_clicked();

    void on_bnt_resize_clicked();

    void on_bnt_size_clicked();

    void on_bnt_capacity_clicked();

    void on_bnt_at_clicked();

    void on_bnt_clear_clicked();

    void on_bnt_data_clicked();

    void on_bnt_empty_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *uptimer;
    My_vector<long long> start_vector;
};
#endif // MAINWINDOW_H
