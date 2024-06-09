#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "DevidedQueue.h"

const int8_t RAND_BOUNDS = 100;

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
    void on_pushFront_clicked();
    void on_popFront_clicked();
    void on_pushBack_clicked();
    void on_popBack_clicked();
    void on_clear_clicked();
    void on_func_clicked();

private:
    Ui::MainWindow *ui;

    DevidedQueue _mainQ;
    DevidedQueue _posQ;
    DevidedQueue _negQ;

    void updateInfo();
};
#endif // MAINWINDOW_H
