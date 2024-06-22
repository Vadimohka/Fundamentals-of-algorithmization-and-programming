#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "doublylinkedqueue.h"


#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonEnqueue_clicked();
    void on_pushButtonRing_clicked();
    void on_pushButtonForward_clicked();
    void on_pushButtonBackward_clicked();
    void on_pushButtonPushBack_clicked();
    void on_pushButtonPushFront_clicked();
    void on_pushButtonPopBack_clicked();
    void on_pushButtonPopFront_clicked();

private:
    Ui::MainWindow *ui;
    DoublyLinkedQueue queue;

    void updateDisplay();
    void updateCurrentPosition();
};

#endif // MAINWINDOW_H
