#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void outputNumber();

private:
    Ui::MainWindow *ui;
    QTimer* timer;

    QString decimalToBinaryInt(long long intNumber);
    QString decimalToBinaryFraction(double fraction, short precision);
    QString decimalToBinary(double number, short precision);
};
#endif // MAINWINDOW_H
