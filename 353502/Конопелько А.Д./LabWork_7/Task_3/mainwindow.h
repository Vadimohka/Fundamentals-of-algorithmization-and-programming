#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "extendedhashtable.h"

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
    void on_insertButton_clicked();
    void on_removeButton_clicked();
    void on_findButton_clicked();
    void on_countAboveAvgButton_clicked();
    void updateDisplay();

private:
    Ui::MainWindow *ui;
    ExtendedHashTable* hashTable;
};

#endif // MAINWINDOW_H
