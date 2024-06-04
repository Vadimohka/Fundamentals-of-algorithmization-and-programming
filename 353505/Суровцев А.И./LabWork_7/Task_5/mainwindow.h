#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "deque.h"

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
    void printDeque();

private slots:
    void on_bnt_push_back_clicked();

    void on_bnt_push_front_clicked();

    void on_bnt_pop_back_clicked();

    void on_bnt_pop_front_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> dek;
};
#endif // MAINWINDOW_H
