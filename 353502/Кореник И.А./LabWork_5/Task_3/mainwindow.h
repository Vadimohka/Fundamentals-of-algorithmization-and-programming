#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bitset.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_all_clicked();

    void on_pushButton_any_clicked();

    void on_pushButton_none_clicked();

    void on_pushButton_count_clicked();

    void on_pushButton_getsize_clicked();

    void on_pushButton_test_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_set_clicked();

    void on_pushButton_flip_clicked();

    void on_pushButton_ul_clicked();

    void on_pushButton_ull_clicked();

    void on_pushButton_bitset_clicked();

private:
    Ui::MainWindow *ui;
    BitSet *set;
};
#endif // MAINWINDOW_H
