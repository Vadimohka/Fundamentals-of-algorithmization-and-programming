#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QDir>
#include <QDebug>
#include <QList>

#include "date.h"
#include "view_app.h"
#include "add_to_table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void App_is_open(QList <Date>, QString, int);

private slots:
    void View_Menu();
    void View_all_information();
    void Delete_information();
    void Add_information();

    void on_Table_itemSelectionChanged();
    void Reseive_new_day(QString);


private:
    int current_index;
    int count_of_row;
    int count_of_columns;
    QString current_path;

    Ui::MainWindow *ui;
    QList<Date> Date_list;

    QMenu* menu;
    View_App* view_app;
    Add_to_Table* add_to_table;


};
#endif // MAINWINDOW_H
