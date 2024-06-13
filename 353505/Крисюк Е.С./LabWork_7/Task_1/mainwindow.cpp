#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    queue = new Queue<QString>;

    ui -> is_empty_line -> setText("Да");


    Queue<int> a;


    for(int i = 0; i < 5; ++i){
        a.push(i + 1);
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_button_clicked()
{
    add_element_window = new Add_element_window();

    connect(add_element_window, &Add_element_window::OpenMainWindow, this, &MainWindow::Add_item);

    add_element_window -> exec();

}

void MainWindow::Add_item(QString element){

    queue -> push(element);

    ui -> listWidget -> addItem(element);

    if(ui -> first_element_line -> text() == ""){
        ui -> first_element_line -> setText(queue -> front());
        ui -> is_empty_line -> setText("Нет");
    }

    ui -> second_element_line -> setText(queue -> back());

}

void MainWindow::on_delete_button_clicked()
{
    if(queue -> size() == 0){

        QMessageBox::warning(nullptr, "Предупреждение", "Очередь пустая");

    }
    else{
        queue -> pop();

        int last_table_element = 0;
        QListWidgetItem* lastItem = ui -> listWidget -> takeItem(last_table_element);

        delete lastItem;


        if(queue -> size() == 0){
            ui -> is_empty_line -> setText("Да");
            ui -> first_element_line -> setText("");
            ui -> second_element_line -> setText("");
        }
        else{
            ui -> first_element_line -> setText(queue -> front());
            qDebug() << queue -> back();

            ui -> second_element_line -> setText(queue -> back());
        }
    }

}


void MainWindow::on_Up_button_clicked()
{
    if(first_selected_index > 0){
        first_selected_index--;

        QAbstractItemModel* model = ui -> listWidget -> model();

        QItemSelection selection_range(

            model->index(first_selected_index, 0, QModelIndex()),

            model->index(second_selected_index, 0, QModelIndex())
        );


        ui -> listWidget -> setCurrentRow(second_selected_index);


        ui -> listWidget -> selectionModel() -> select(selection_range, QItemSelectionModel::Select | QItemSelectionModel::Rows);


    }

    else{
        QMessageBox::warning(nullptr, "Предупреждение", "Невозможно выделить данную область");
    }
}


void MainWindow::on_Down_button_clicked()
{
    if(second_selected_index < queue -> size() - 1){

        second_selected_index++;

        QAbstractItemModel* model = ui -> listWidget -> model();

        QItemSelection selection_range(

            model->index(first_selected_index, 0, QModelIndex()),

            model->index(second_selected_index, 0, QModelIndex())
            );


        ui -> listWidget -> setCurrentRow(first_selected_index);


        ui -> listWidget -> selectionModel() -> select(selection_range, QItemSelectionModel::Select | QItemSelectionModel::Rows);


    }

    else{
        QMessageBox::warning(nullptr, "Предупреждение", "Невозможно выделить данную область");
    }
}


void MainWindow::on_listWidget_currentRowChanged(int current_row)
{

    first_selected_index = current_row;
    second_selected_index = current_row;

}



void MainWindow::Update_window() {

    ui -> listWidget -> clear();

    for(int i = 0; i < queue -> size(); ++i){
        ui -> listWidget -> addItem(queue -> Get_element_of_index(i));
    }
}

void MainWindow::on_Move_up_button_clicked()
{
    if(first_selected_index == -1){
        QMessageBox::warning(nullptr, "Предупреждение", "(Добавьте элемент, если у вас их нет) выделите область");
    }

    else{
        if(first_selected_index != 0){

            queue -> Move_rows(first_selected_index, second_selected_index, "up");

            this -> Update_window();
        }
    }

}




void MainWindow::on_Move_down_button_clicked()
{
    if(first_selected_index == -1){
        QMessageBox::warning(nullptr, "Предупреждение", "(Добавьте элемент, если у вас их нет) выделите область");
    }

    else{
        if(second_selected_index < queue -> size() - 1) {

            queue -> Move_rows(first_selected_index, second_selected_index, "down");

            this -> Update_window();
        }

    }
}

