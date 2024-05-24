
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_convertButton_clicked();

private:
    Ui::MainWindow *ui;

    QString decimalToBinary(double num, int precision);
    QString fractionToBinary(double fraction, int precision);
    QString integerToBinary(int integer);
};

#endif // MAINWINDOW_H
