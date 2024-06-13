#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "dequeue.h"
#include "add_element_window.h"

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
    void on_add_front_button_clicked();

    void on_delete_front_button_clicked();

    void Add_front_item(QString );
    void Add_back_item(QString );

    void on_add_back_button_clicked();

    void on_delete_back_button_clicked();

    void on_Clear_button_clicked();

private:
    Ui::MainWindow *ui;

    Add_element_window* add_element_window;
    Dequeue<int> deq;

    void Update_table();

};
#endif // MAINWINDOW_H
