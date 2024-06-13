#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    QString answer = "";
    HashTable hash16 = HashTable(16);
    HashTable hash64 = HashTable(64);
    HashTable hash128 = HashTable(128);
    HashTable hash2048 = HashTable(2048);

    void insertInHash16();
    void demonstrateHash16();
};
#endif // MAINWINDOW_H
