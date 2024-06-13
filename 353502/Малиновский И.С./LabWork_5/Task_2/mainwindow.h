#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "string.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_copyButton_clicked();
    void on_concatButton_clicked();
    void on_compareButton_clicked();

private:
    QTextEdit *srcTextEdit;
    QTextEdit *destTextEdit;
    QTextEdit *str1TextEdit;
    QTextEdit *str2TextEdit;
    QTextEdit *cmpTextEdit1;
    QTextEdit *cmpTextEdit2;
    QLabel *cmpResultLabel;
};

#endif // MAINWINDOW_H
