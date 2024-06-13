#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"
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
public slots:

    void find();
    void generate();

private:
    int size = 10;
    void showTable(QTableWidget* tableWidget, HashTable* hashTable);
    void updateCollisionTable(QTableWidget* tableWidget, QVector<HashTable>& hashTables);
    HashTable* hashTable1;
    HashTable* hashTable2;
    HashTable* hashTable3;
    HashTable* hashTable4;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
