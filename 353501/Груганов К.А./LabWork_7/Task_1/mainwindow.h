#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "deque.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateBrowser();
    bool is_sorted();
private slots:

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_at_clicked();

    void on_get_size_clicked();

    void on_is_empty_clicked();

    void on_peek_back_clicked();

    void on_peek_front_clicked();

    void on_sort_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> *deque;
};
#endif // MAINWINDOW_H
