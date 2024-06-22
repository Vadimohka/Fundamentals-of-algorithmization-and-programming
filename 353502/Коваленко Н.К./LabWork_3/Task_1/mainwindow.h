#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool ok;
    long long decimal;
    long double fraction;
    QTimer *timer;
    void calculate();
    std::string DecimalToBinary(int n);
    std::string FractionToBinary(double fraction, int precision);
    MainWindow();
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
};
