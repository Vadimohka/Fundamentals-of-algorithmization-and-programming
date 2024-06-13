#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

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
    void on_evaluateButton_clicked();

private:
    Ui::MainWindow *ui;
    int AccermanFunction(int m, int n);
    int col = 0;
    int a[900][900];
};
#endif // MAINWINDOW_H
