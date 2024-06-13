#include "add_new_element_window.h"
#include "ui_add_new_element_window.h"

Add_new_element_window::Add_new_element_window(QWidget *parent) :QDialog(parent),ui(new Ui::Add_new_element_window)
{
    ui->setupUi(this);

    QIntValidator* val = new  QIntValidator(0,999999);
    ui -> key_line -> setValidator(val);

}

Add_new_element_window::~Add_new_element_window()
{
    delete ui;
}

void Add_new_element_window::on_Cancel_button_clicked()
{
    close();
}


void Add_new_element_window::on_Add_button_clicked()
{

    if(!Check_if_not_empty()){
        QMessageBox::warning(nullptr, "Предупреждение", "Заполните недостающие строки");
    }

    else{
        QString text = ui -> text_line -> text();
        int key = ui -> key_line -> text().toInt();

        emit(OpenMainWindow(text, key));

        close();
    }
}


bool Add_new_element_window::Check_if_not_empty(){

    return ui -> text_line -> text() != "" && ui -> key_line -> text() != "";
}
