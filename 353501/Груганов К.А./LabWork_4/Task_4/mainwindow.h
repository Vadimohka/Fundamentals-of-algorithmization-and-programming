#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "vector.h"
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
    void on_at_clicked();

    void on_push_back_clicked();

    void on_pop_back_clicked();

    void on_resize_clicked();

    void on_maxsize_clicked();

    void on_clear_clicked();

    void on_capacity_clicked();

    void on_erase_clicked();

    void on_empty_clicked();

    void on_reserve_clicked();

    void on_data_clicked();

    void on_size_clicked();

private:
    void updateVector();
    Vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
