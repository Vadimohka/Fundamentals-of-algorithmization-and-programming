#include "dialog.h"
#include "ui_dialog.h"

UserInputDialog::UserInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInputDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(Sportik::MAX_NAME_SIZE - 1);
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
    input.BirthdayYear = ui->spinBox->value();
    input.teamletter = ui->lineEdit_2->text().toStdString().front();
    input.wage = ui->doubleSpinBox->value();
    input.isCoolGuy = ui->checkBox->isChecked();

    input.tournametsYear[0] = ui->spinBox_2->value();
    input.tournametsYear[1] = ui->spinBox_3->value();
    input.tournametsYear[2] = ui->spinBox_4->value();
    input.tournametsYear[3] = ui->spinBox_5->value();
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
