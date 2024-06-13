#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "queue.h"
#include <QMainWindow>
#include <QRandomGenerator>

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
    void addElements();
    void makeRings();
    void showtime();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Queue beginRing;
    Queue firstRing;
    Queue secondRing;
    int indexofmax;
    int indexofmin;
    bool valid = false;
    Queue::QueueIterator showRing;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
