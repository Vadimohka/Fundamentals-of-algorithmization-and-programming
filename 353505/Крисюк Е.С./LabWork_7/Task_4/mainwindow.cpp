#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator* val = new QIntValidator(0,99999);

    ui -> key_line -> setValidator(val);
    ui -> value_line -> setValidator(val);


    table = new Hash_table(10);


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


    int temp = 0;
    int key = 0;

    QTableWidget* widget = ui -> tableWidget;

    QTableWidgetItem* first_item;
    QTableWidgetItem* second_item;

    ui -> tableWidget -> setRowCount(table -> size());

    for(int i = 0; i < table -> size(); ++i){

        temp = table -> get_element_from_index(i);
        key = table -> get_key_from_index(i);


        qDebug() << "key" << key;

        first_item = new QTableWidgetItem(QString::number(temp));
        second_item = new QTableWidgetItem(QString::number(key));


        qDebug() << temp << key;

        if(temp == -1){
            first_item = new QTableWidgetItem("");
            second_item = new QTableWidgetItem("");
        }

        widget -> setItem(i,0, second_item);
        widget -> setItem(i,1, first_item);

    }

}

void MainWindow::on_Remove_button_clicked()
{
    if(ui -> key_line -> text() == "") {
        QMessageBox::warning(nullptr, "Предупреждение", "Введите ключ");
    }
    else {

        int key = ui -> key_line -> text().toInt();


        table -> remove(key);

        this -> Update_table();
    }
}

