#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

#include "hashtable.h"

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

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    int GenerateRandomNumber();
    void FillTable(HashTable<int>& table, int size);

    int currTable = 0;

    HashTable<int> *Table16;
    HashTable<int> *Table64;
    HashTable<int> *Table128;
    HashTable<int> *Table2048;

};
#endif // MAINWINDOW_H
