#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"

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
    void on_pushButtonMaxKey_clicked();
    void on_pushButtonRandomFill_clicked();
    void on_pushButtonClear_clicked();

private:
    Ui::MainWindow *ui;
    ExtendedHashTable *hashTable;

    void updateDisplay();
};
#endif // MAINWINDOW_H
