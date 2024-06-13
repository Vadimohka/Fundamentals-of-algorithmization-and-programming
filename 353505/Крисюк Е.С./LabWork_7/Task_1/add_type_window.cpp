#include "add_type_window.h"
#include "ui_add_type_window.h"

Add_type_window::Add_type_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_type_window)
{
    ui->setupUi(this);
}

Add_type_window::~Add_type_window()
{
    delete ui;
}


void Add_type_window::on_pushButton_clicked()
{

    QString text = ui -> comboBox -> currentText();

    QVariant variant (text);

    emit(OpenMainWindow(variant));

}

