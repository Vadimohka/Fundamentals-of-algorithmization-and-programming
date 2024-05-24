#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>

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
    QString recurse(int a, double b, int k);
    void changeLien();
    void getNumber();

private:
    Ui::MainWindow *ui;
    double number;
    double binaryNumber;
    bool status;
};
#endif // MAINWINDOW_H
