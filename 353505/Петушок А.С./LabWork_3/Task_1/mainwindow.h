#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "converttobinary.h"

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
    void on_ConvertButton_clicked();
    bool check_input();

private:
    Ui::MainWindow *ui;
    ConvertToBinary b_number;
};
#endif // MAINWINDOW_H
