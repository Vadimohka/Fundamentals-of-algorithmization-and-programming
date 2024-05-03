#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void reverseNumber();

private:
    QLineEdit *lineEdit;
    QPushButton *button;
    QLabel *label;
    int reverse(int n, int r = 0);
    bool isValidInput(const QString &input);
};

#endif // MAINWINDOW_H
