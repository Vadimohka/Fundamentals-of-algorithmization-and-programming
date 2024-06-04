#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"reversive.h"
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
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    reversive a;
};
#endif // MAINWINDOW_H
