#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include "queue.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enqueueButton_clicked();
    void on_dequeueButton_clicked();
    void on_sortButton_clicked();

private:
    void updateListWidget();

    Queue queue;
    QListWidget* listWidget;
    QLineEdit* inputLineEdit;
};

#endif // MAINWINDOW_H
