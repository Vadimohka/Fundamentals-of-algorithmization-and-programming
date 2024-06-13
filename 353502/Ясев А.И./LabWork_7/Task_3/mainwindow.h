#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "hashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

private:
    Ui::MainWindow *ui;
    HashTable* hashtable = nullptr;
    void UpdateTable();
};
#endif // MAINWINDOW_H
