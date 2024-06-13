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
    void on_enqueueButton_clicked();
    void on_dequeueButton_clicked();
    void on_findMaxAndMoveButton_clicked();
    void on_fillRandomButton_clicked();
    void on_fillRandomButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Queue<int> m_queue;
};
#endif // MAINWINDOW_H
