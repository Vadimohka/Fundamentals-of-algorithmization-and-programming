#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "validator.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double reverseNum(long long num, long long res = 0);
    void number(const QString &text);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
