#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <modHashTable.h>
#include <multHashTable.h>

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
    MultHashTable<int> *mult = new MultHashTable<int>(10000);
    ModHashTable<int> *mod = new ModHashTable<int>(10000);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
