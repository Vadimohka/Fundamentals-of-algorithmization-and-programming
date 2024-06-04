#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include<stdio.h>
#include"tobinary.h"
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
    void create();

private slots:
    void on_doubleSpinBox_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    ToBinary *to_binary=new ToBinary;
};
#endif // MAINWINDOW_H
