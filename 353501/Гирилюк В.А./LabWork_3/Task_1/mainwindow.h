#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_lineEdit_editingFinished();

private:
    QString expToBinary(double dnum);
    QString decimalToBinary(long long integer, double fraction);
    QString integerToBinary(long long number);
    QString fractionToBinary(double number, int precision);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
