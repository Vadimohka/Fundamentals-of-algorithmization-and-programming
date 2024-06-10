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


    void on_insert_btn_clicked();

    void on_remove_btn_clicked();

    void on_search_btn_clicked();

    void on_print_btn_clicked();

    void on_loadFactor_btn_clicked();

    void on_execTask_btn_clicked();

    void on_rand_btn_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<int> hashtable;
};
#endif // MAINWINDOW_H
