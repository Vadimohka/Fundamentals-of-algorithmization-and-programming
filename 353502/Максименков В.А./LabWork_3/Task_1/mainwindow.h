#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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
    void integerToBinarySystem(int n, QString &now);
    void fractionToBinarySystem(double n, QString &now, const int &precision);
};
#endif // MAINWINDOW_H
