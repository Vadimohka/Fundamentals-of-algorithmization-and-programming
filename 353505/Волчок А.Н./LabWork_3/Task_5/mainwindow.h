#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"counter.h"
#include<QFileDialog>
#include<QFileSystemModel>
#include<QTreeView>
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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    counter *ct;
    int count1=0;
    int count2=0;
};
#endif // MAINWINDOW_H
