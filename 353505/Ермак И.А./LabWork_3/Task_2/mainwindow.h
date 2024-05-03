#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_N_valueChanged(int arg1);

    void on_spinBox_M_valueChanged(int arg1);
    int AkeraMAN(int m, int n);
private:
    Ui::MainWindow *ui;
    int M;
    int N;
};
#endif // MAINWINDOW_H
