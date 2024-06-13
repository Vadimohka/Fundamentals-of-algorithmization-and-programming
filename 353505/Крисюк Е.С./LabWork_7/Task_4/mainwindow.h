#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QIntValidator>
#include <QMessageBox>

#include "hash_table.h"

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
    void on_Add_button_clicked();

    void on_Remove_button_clicked();

private:
    Ui::MainWindow *ui;

    Hash_table* table;
    void Update_table();
};
#endif // MAINWINDOW_H
