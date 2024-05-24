#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mybitset.h"

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
    void on_bnt_set_clicked();

    void on_bnt_size_clicked();

    void on_bnt_ulong_clicked();

    void on_bnt_ullong_clicked();

    void on_bnt_none_clicked();

    void on_bnt_reset_clicked();

    void on_bnt_flip_clicked();

    void on_bnt_count_clicked();

    void on_bnt_all_clicked();

    void on_bnt_any_clicked();

    void on_bnt_int_flip_clicked();

    void on_bnt_int_reset_clicked();

    void on_bnt_int_test_clicked();

    void on_bnt_int_set_clicked();

private:
    Ui::MainWindow *ui;
    MyBitSet *mybitset;
};
#endif // MAINWINDOW_H
