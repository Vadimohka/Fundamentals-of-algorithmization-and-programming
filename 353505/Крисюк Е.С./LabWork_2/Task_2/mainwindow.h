#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "menu_add_window.h"
#include "list_create_menu.h"
#include "information_view.h"

#include <QTreeWidget>
#include <QMessageBox>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString File_path, File_name;
    QString Path_to_create_File;

private slots:
    void on_Menu_action_triggered();

    void on_Order_action_triggered();

    void on_Add_order_button_clicked();

    void on_Add_dish_button_clicked();

    void on_View_order_button_clicked();

    void on_Sort_button_clicked();

public slots:
    void Reseive_data(const QString &File_path);
    void Reseive_path(const QString &file_path);

    void Infotmation_view();

signals:
    void Send_path(const QString &File_path);
    void Send_information_path(const QString &file_path, const QString &Path_to_create_file);
    void Send(const QString &File_path);



private:
    Ui::MainWindow *ui;
    Menu_add_window* menu_add_window;
    List_create_menu* list_create_menu;
    Information_View* information_view;
};
#endif // MAINWINDOW_H
