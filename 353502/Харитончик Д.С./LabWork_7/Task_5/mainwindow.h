#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Dequeue.h"

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
    void on_pushbackButton_clicked();

    void on_popbackButton_2_clicked();

    void on_pushfrontButton_clicked();

    void on_popfrontButton_clicked();

    void on_clearButton_clicked();

private:
    void printDeq();

    Ui::MainWindow *ui;
    Dequeue<int> deq;
};
#endif // MAINWINDOW_H
