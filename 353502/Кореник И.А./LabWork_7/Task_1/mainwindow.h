#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include </home/lidskae/Lab7_task1/queue.h>
#include <QRandomGenerator64>
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
    void on_append_button_clicked();

    void on_pop_back_button_clicked();

    void on_pop_front_button_clicked();

    void on_push_front_button_clicked();

    void on_filling_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Queue<int> test;

    Queue<int> test2;

    void update();
};
#endif // MAINWINDOW_H
