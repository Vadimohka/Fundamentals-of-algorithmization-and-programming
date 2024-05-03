#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hashtable.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    void display();
    HashTable * table16 = nullptr, *table64 = nullptr, *table128 = nullptr, *table2048 = nullptr;
};
#endif // MAINWINDOW_H
