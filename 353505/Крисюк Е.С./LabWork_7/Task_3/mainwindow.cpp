#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    table = new Speciall_hash_table(5);

    QIntValidator* val = new QIntValidator(0,99999);

    ui -> key_line -> setValidator(val);
    ui -> value_line -> setValidator(val);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_button_clicked()
{
    if(ui -> key_line -> text() == "" || ui -> value_line -> text() == "") {
        QMessageBox::warning(nullptr, "Предупреждение", "Введены не все параметры");
    }
    else {
        int key = ui -> key_line -> text().toInt();
        int value = ui -> value_line -> text().toInt();

        table -> insert(key, value);

        this -> Update_table();
    }
}

void MainWindow::Update_table(){

    ui -> tableWidget -> clear();

    int max = -1;

    QList<int>* temp;
    QList<int> data;

    QTableWidget* widget = ui -> tableWidget;
    QTableWidgetItem* item;

    ui -> tableWidget -> setRowCount(table -> size());

    for(int i = 0; i < table -> size(); ++i){

        temp = table -> Get_stack_from_index(i);
        data = *temp;

        if(temp -> size() > max){


            max = temp -> size();
            ui -> tableWidget -> setColumnCount(max);
        }

        for(int j = 0; j < temp -> size();++j){

            item = new QTableWidgetItem(QString::number(data[j]));
            widget -> setItem(i,j, item);
        }
    }

}

void MainWindow::on_Create_random_button_clicked()
{
    int count = QRandomGenerator::global() -> bounded(4,30);

    table -> clear();


    table -> generate_random_table(0,100,count);

    Update_table();
}


void MainWindow::on_Remove_button_clicked()
{

    if(ui -> key_line -> text() == "") {
        QMessageBox::warning(nullptr, "Предупреждение", "Введены не все параметры");
    }

    else{

        int key = ui -> key_line -> text().toInt();

        table -> remove(key);

        this -> Update_table();
    }

}


void MainWindow::on_Find_min_key_clicked()
{
    int index = table->find_stack_with_min_key();

    QMessageBox::warning(nullptr, "Сообщение", QString::number(index + 1));
}

