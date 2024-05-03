#include "add_to_table.h"
#include "ui_add_to_table.h"

Add_to_Table::Add_to_Table(QWidget *parent) :QDialog(parent),ui(new Ui::Add_to_Table)
{
    ui->setupUi(this);
    this -> setStyleSheet("background-color: #03ecfc");

}

Add_to_Table::~Add_to_Table()
{
    delete ui;
}

void Add_to_Table::on_pushButton_clicked()
{
    emit(Send_new_day(ui -> Date -> text()));
    close();
}


void Add_to_Table::on_pushButton_2_clicked()
{
    close();
}

