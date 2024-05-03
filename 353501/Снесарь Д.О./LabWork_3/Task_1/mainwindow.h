#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    QString iToBin(double x);
    QString decimalToBinary(const QString& decimal);
    QString dToBin(double x);
    QString toIEEE754 (QString integer, QString fractional, bool sign);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
