#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pushButton_push_clicked();

    void on_pushButton_push_pop_clicked();

    void on_pushButton_push_proc_clicked();

private:
    Ui::MainWindow *ui;
    Queue<QString> queue;
    void displayQueue();
};
#endif // MAINWINDOW_H
