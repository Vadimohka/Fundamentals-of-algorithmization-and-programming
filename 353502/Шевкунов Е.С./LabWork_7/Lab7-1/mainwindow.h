#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QListWidget>
#include <QProgressBar>
#include <QLabel>
#include <QTimer>
#include "circular_deque.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_popButton_clicked();
    void on_fillButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void updateDisplay();

private:
    QPushButton *pushButton;
    QPushButton *popButton;
    QPushButton *fillButton;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QSpinBox *valueSpinBox;
    QListWidget *listWidget;
    QProgressBar *gauge;
    QLabel *label;
    QTimer *timer;
    CircularDeque<int> deque;

    void setupUi();
};

#endif // MAINWINDOW_H

