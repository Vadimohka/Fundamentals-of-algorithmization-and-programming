#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> is_empty_line -> setText("Да");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_front_button_clicked()
{
    add_element_window = new Add_element_window();

    connect(add_element_window, &Add_element_window::OpenMainWindow, this, &MainWindow::Add_front_item);

    add_element_window -> exec();
}

void MainWindow::Add_front_item(QString number){


    deq.push_front(number.toInt());


    ui -> is_empty_line -> setText("Нет");
    Update_table();

}

void MainWindow::on_delete_front_button_clicked()
{
    if(deq.size() == 0){

        QMessageBox::warning(nullptr, "Предупреждение", "Очередь пустая");

    }
    else{
        deq.pop_front();

        int last_table_element = 0;
        QListWidgetItem* lastItem = ui -> listWidget -> takeItem(last_table_element);

        delete lastItem;

        if(deq.size() == 0){
            ui -> is_empty_line -> setText("Да");
        }

    }
}


void MainWindow::Update_table(){
    ui -> listWidget -> clear();
    
    for(Iterator<int> i = deq.begin(); i != deq.end(); ++i){
        ui -> listWidget -> addItem(QString::number(*i));
    }
    
}

void MainWindow::on_add_back_button_clicked()
{
    add_element_window = new Add_element_window();

    connect(add_element_window, &Add_element_window::OpenMainWindow, this, &MainWindow::Add_back_item);

    add_element_window -> exec();
}

void MainWindow::Add_back_item(QString number){


    deq.push_back(number.toInt());

    ui -> listWidget -> addItem(number);

    ui -> is_empty_line -> setText("Нет");

}

void MainWindow::on_delete_back_button_clicked()
{
    if(deq.size() == 0){

        QMessageBox::warning(nullptr, "Предупреждение", "Очередь пустая");

    }
    else{
        deq.pop_back();

        Update_table();

        if(deq.size() == 0){
            ui -> is_empty_line -> setText("Да");
        }
    }
}


void MainWindow::on_Clear_button_clicked()
{
    if(deq.size() == 0){

        QMessageBox::warning(nullptr, "Предупреждение", "Очередь пустая");

    }
    else{
        deq.clear();
        ui -> listWidget -> clear();
    }
}

