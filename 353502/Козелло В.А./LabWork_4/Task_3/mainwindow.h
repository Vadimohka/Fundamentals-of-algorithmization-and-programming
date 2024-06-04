#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "median.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_clicked();
    void on_Clear_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> arr;
};
#endif // MAINWINDOW_H
