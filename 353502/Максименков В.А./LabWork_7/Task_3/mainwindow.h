#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "MyHashTable.h"

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
    void insertElement();
    void deleteElement();
    void deleteEvenKeys();

private:
    Ui::MainWindow *ui;
    int size = 100;
    MyHashTable table = MyHashTable(size);

    void showTable();
};
#endif // MAINWINDOW_H
