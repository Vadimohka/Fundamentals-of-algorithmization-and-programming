#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>

#include "queue.h"

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

    void on_On_front_clicked();

    void on_On_back_clicked();

    void on_On_Empty_clicked();

    void on_On_Sort_clicked();

    void on_On_Print_clicked();

    void on_On_clear_clicked();

    void on_On_push_back_clicked();

    void on_On_push_front_clicked();

    void on_On_pop_back_clicked();

    void on_On_pop_front_clicked();

private:
    Ui::MainWindow* ui;
    Queue<long long> queue;
};
#endif // MAINWINDOW_H
