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
    void calculateAckermann();

private:
    int ackermann(int m, int n);

    QLineEdit *mInput;
    QLineEdit *nInput;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
