#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ackermann.h"
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
    void on_SolutionButton_clicked();

private:
    Ui::MainWindow *ui;
    Ackermann ackermannFunction;
};
#endif // MAINWINDOW_H
