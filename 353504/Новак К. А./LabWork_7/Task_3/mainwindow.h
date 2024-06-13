#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hashtable.h"

#include <QMainWindow>
#include <QRandomGenerator>

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

private:
    int GetRandNum();

    Ui::MainWindow *ui;

    HashTable<QString> *Table;
};
#endif // MAINWINDOW_H
