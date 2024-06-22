#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "queue.h"
#include "add_element_window.h"
#include "add_type_window.h"

#include <QItemSelectionModel>



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
    void on_add_button_clicked();

    void Add_item(QString);

    void on_delete_button_clicked();

    void on_Up_button_clicked();

    void on_Down_button_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_Move_up_button_clicked();

    void on_Move_down_button_clicked();

private:
    Ui::MainWindow *ui;
    Add_element_window* add_element_window;

    int first_selected_index = -1;
    int second_selected_index = -1;

    Queue<QString>* queue;

    void Add_elements_to_window();

    void Update_window();

};
#endif // MAINWINDOW_H
