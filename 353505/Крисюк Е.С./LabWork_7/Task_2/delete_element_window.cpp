#include "delete_element_window.h"
#include "ui_delete_element_window.h"

Delete_element_window::Delete_element_window(QWidget *parent) :QDialog(parent),ui(new Ui::Delete_element_window)
{
    ui->setupUi(this);

    QIntValidator* val = new QIntValidator(0,999999);

    ui -> lineEdit -> setValidator(val);

}

Delete_element_window::~Delete_element_window()
{
    delete ui;
}

void Delete_element_window::on_Cancel_button_clicked()
{
    close();
}


void Delete_element_window::on_Delete_button_clicked()
{
    if(ui -> lineEdit -> text() == ""){
        QMessageBox::warning(nullptr, "Предупреждение", "Заполните поле");
    }
    else {
        emit(OpenMainWindow(ui -> lineEdit -> text().toInt()));

        close();
    }
}

