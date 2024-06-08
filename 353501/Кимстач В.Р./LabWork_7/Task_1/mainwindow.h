#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"

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
    void on_enqueue_clicked();
    void on_dequeue_clicked();
    void on_makeMinFirst_clicked();
    void on_fillRandomQueue_clicked();
    void on_size_clicked();
    void on_peek_clicked();
    void on_isEmpty_clicked();

private:
    Ui::MainWindow *ui;
    Queue queue;

    void updateListWidget();
};

#endif // MAINWINDOW_H
