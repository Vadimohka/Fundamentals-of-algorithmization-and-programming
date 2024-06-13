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
    void displayQueue(QListWidget* listWidget, const Queue& queue);

private slots:
    void on_bnt_generation_clicked();

    void on_bnt_split_clicked();

private:
    Ui::MainWindow *ui;
    Queue mainQueue;
    Queue negativeQueue;
    Queue positiveQueue;
};
#endif // MAINWINDOW_H
