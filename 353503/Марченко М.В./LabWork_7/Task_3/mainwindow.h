#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"
#include "taskhashtable.h"

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
    void add();
    void find();
    void remove();
    void clear();
    void changeSize();
    void task();
    void task1();


private:
    int size = 10;
    void showTable();
    void showTable1();
    HashTable* hashTable;
    TaskHashTable* taskHashTable;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
