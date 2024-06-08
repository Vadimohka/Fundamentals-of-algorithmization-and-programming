#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
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
    void displayQueue(QListWidget *listWidget,const Queue &queue);

private slots:

    void on_pushButton_random_clicked();

    void on_pushButton_new_queue_clicked();

    void on_pushButton_front_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_pop_clicked();

    void on_pushButton_push_clicked();

private:
    Ui::MainWindow *ui;
    Queue mainQueue;
};
#endif // MAINWINDOW_H
