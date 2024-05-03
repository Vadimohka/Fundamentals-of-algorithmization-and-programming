#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void calculateAckermann();

private:
    QLineEdit *mLineEdit;
    QLineEdit *nLineEdit;
    QLabel *resultLabel;
    int ackermann(int m, int n);
};

#endif // MAINWINDOW_H
