#include "add_element_window.h"
#include "ui_add_element_window.h"

Add_element_window::Add_element_window(QWidget *parent) :QDialog(parent),ui(new Ui::Add_element_window)
{
    ui->setupUi(this);

    QIntValidator* val = new QIntValidator(0,999999);

    ui -> lineEdit -> setValidator(val);


}

Add_element_window::~Add_element_window()
{
    delete ui;
}



void Add_element_window::on_Cancel_button_clicked()
{
    close();
}


void Add_element_window::on_Add_button_clicked()
{
    if(ui -> lineEdit -> text() == ""){
        QMessageBox::warning(nullptr, "Предупреждение", "Введите текст");
    }

    else {
        emit(OpenMainWindow(ui -> lineEdit -> text()));

        close();
    }
}

