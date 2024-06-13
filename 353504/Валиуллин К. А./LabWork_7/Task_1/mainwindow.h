#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QRandomGenerator>

#include "deque.h"
#include "deque.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_randomButton1_clicked();
    void on_buttonTask_clicked();
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_popFrontButton_clicked();
    void on_popBackButton_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> deque1;

    void updateUI();
    void fillRandom(Deque<int> &deque, QListWidget *listWidget);
    void displayDeque(const Deque<int> &deque, QListWidget *listWidget);
};

#endif // MAINWINDOW_H
