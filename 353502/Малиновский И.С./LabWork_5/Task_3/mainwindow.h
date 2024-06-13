#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "bitset.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_flipButton_clicked();
    void on_setButton_clicked();
    void on_resetButton_clicked();
    void on_testButton_clicked();

private:
    QTextEdit *posTextEdit;
    QLabel *bitsetLabel;
    BitSet bitset;
};

#endif // MAINWINDOW_H
