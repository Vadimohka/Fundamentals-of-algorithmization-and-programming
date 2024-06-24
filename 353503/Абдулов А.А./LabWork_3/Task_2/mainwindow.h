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
    void getNumberM();
    void getNumberN();
    int functionAkerman(int m, int n);
    void changeLien();

private:
    Ui::MainWindow *ui;
    int m;
    int n;

};
#endif // MAINWINDOW_H
