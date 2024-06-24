#include "userinputdialog.h"
#include "ui_userinputdialog.h"

UserInputDialog::UserInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInputDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(Car::NAME_SIZE - 1);
}

UserInputDialog::~UserInputDialog()
{
    delete ui;
}

void UserInputDialog::on_buttonBox_accepted()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(nullptr, tr("Wrong Input"), "None of the fields should be empty", QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QString name = ui->lineEdit->text();
    for (int i = 0; i < name.length(); ++i)
    {
        input.name[i] = name.at(i);
    }

    input.name[name.length()] = QChar('\0');

    input.year = ui->spinBox->value();
    input.model = ui->lineEdit_2->text().toStdString().front();
    input.mileage = ui->doubleSpinBox->value();
    input.isPassengerCar = ui->checkBox->isChecked();

    input.tirePressures[0] = ui->spinBox_2->value();
    input.tirePressures[1] = ui->spinBox_3->value();
    input.tirePressures[2] = ui->spinBox_4->value();
    input.tirePressures[3] = ui->spinBox_5->value();
    emit inputInit(input);
    close();
}


void UserInputDialog::on_spinBox_valueChanged(int value)
{
    ui->spinBox_2->setMinimum(value);
    ui->spinBox_3->setMinimum(value);
    ui->spinBox_4->setMinimum(value);
    ui->spinBox_5->setMinimum(value);
}

