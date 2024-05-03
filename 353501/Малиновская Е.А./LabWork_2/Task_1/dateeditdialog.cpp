#include "dateeditdialog.h"

DateEditDialog::DateEditDialog(const Date& date, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DateEditDialog),
    editedDate(date)
{
    ui->setupUi(this);
    ui->dayLineEdit->setText(QString::number(date.getDay()));
    ui->monthLineEdit->setText(QString::number(date.getMonth()));
    ui->yearLineEdit->setText(QString::number(date.getYear()));
}

DateEditDialog::~DateEditDialog()
{
    delete ui;
}

Date DateEditDialog::getEditedDate() const
{
    return editedDate;
}
void DateEditDialog::setEditedDate(const Date& date)
{
    editedDate = date;
    ui->dayLineEdit->setText(QString::number(date.getDay()));
    ui->monthLineEdit->setText(QString::number(date.getMonth()));
    ui->yearLineEdit->setText(QString::number(date.getYear()));
}

void DateEditDialog::on_buttonBox_accepted()
{
    int day = ui->dayLineEdit->text().toInt();
    int month = ui->monthLineEdit->text().toInt();
    int year = ui->yearLineEdit->text().toInt();

    editedDate = Date(day, month, year);
    emit dateEdited(editedDate);
}
