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
    void convertToBinary();
    QString decimalToBinary(long double number, int precision);

private:
    QLineEdit *inputLineEdit;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
