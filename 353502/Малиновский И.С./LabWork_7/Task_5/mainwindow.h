#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "deque.h"

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
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_popBackButton_clicked();
    void on_popFrontButton_clicked();
    void on_clearButton_clicked();
    void on_updateSizeButton_clicked();
    void on_updateCapacityButton_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> deque;
    size_t capacity;
    size_t size;

    QLabel *dequeInfoLabel;
    void updateDequeInfo();
};

#endif // MAINWINDOW_H
