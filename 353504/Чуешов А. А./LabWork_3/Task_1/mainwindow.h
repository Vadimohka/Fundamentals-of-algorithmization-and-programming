#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertToBinary();
private:
    QPushButton *button;
    QLineEdit *lineEdit;
    QLabel *label;
    QString decimalToBinary(int decimal);
};

#endif // MAINWINDOW_
