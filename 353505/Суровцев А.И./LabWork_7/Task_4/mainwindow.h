#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QDateTime>
#include <ctime>
#include <QGraphicsRectItem>
#include "myhashtable.h"

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
    void printHashTable(QTableWidget *tableWidget, MyHashTable *hashTable);

private slots:


    void on_bnt_printResult_clicked();

    void on_bnt_regen_clicked();

private:
    Ui::MainWindow *ui;
    MyHashTable * table16, *table64, *table128, *table2048;
};
#endif // MAINWINDOW_H
