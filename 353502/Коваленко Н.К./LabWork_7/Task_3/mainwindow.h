#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QMessageBox>

#include "speciall_hash_table.h"


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

    void on_Create_random_button_clicked();

    void on_Remove_button_clicked();

    void on_Find_min_key_clicked();

private:
    Ui::MainWindow *ui;

    Speciall_hash_table* table;

    void Update_table();

};
#endif // MAINWINDOW_H
