#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "deque.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enqueueButton_clicked();
    void on_dequeueButton_clicked();
    void on_convertToRingButton_clicked();

private:
    Deque deque;
    QTextEdit* textEdit;
    QLineEdit* lineEdit;
    QPushButton* enqueueButton;
    QPushButton* dequeueButton;
    QPushButton* convertToRingButton;
};

#endif // MAINWINDOW_H
