#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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
    void printHashTable();

private slots:
    void on_bnt_randgen_clicked();

    void on_bnt_add_clicked();

    void on_bnt_printMin_clicked();

    void on_bnt_delete_clicked();

private:
    Ui::MainWindow *ui;
    MyHashTable * htable;
};
#endif // MAINWINDOW_H
