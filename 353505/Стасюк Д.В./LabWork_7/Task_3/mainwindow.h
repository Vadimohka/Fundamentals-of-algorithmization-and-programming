#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_hash_table.h"
#include <QTableWidget>

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
    void printHashTable(MyHashTable *ht, QTableWidget *qTableW);
    void splitToPositiveNegative();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton_p_and_n_clicked();

private:
    Ui::MainWindow *ui;
    MyHashTable *htable;
    MyHashTable *positiveTable;
    MyHashTable *negativeTable;

};
#endif // MAINWINDOW_H
