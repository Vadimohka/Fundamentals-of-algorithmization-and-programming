#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
typedef unsigned long long ull;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString printBinary(double x);
    QString decimalToBin(double n);
    QString printIEEE754(double x);
    QString getM(double x);
    QString getExp(double x);
    QString fracToBin(double frac, int bits);
    QString getSign(double x);
private slots:

    void on_ieee754convert_clicked();

    void on_binaryconvert_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
