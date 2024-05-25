#include "dialog.h"
#include "ui_dialog.h"

StructInputDialog::StructInputDialog(QWidget *parent, Sportik* ref) :
    QDialog(parent), ui(new Ui::StructInputDialog),
    a(ref)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(Sportik::MAX_NAME_SIZE - 1);
}

StructInputDialog::~StructInputDialog()
{
    delete ui;
}

void StructInputDialog::on_buttonBox_accepted()
{
    QString name = ui->lineEdit->text();
    for (int i = 0; i < name.length(); ++i)
    {
        a->name[i] = name.at(i).toLatin1();
    }

    a->name[name.length()] = char('\0');

    a->BirthdayYear = ui->spinBox->value();
    a->teamletter = ui->lineEdit_2->text().toStdString().front();
    a->wage = ui->doubleSpinBox->value();
    a->isCoolGuy = ui->checkBox->isChecked();

    a->tournametsYear[0] = ui->spinBox_2->value();
    a->tournametsYear[1] = ui->spinBox_3->value();
    a->tournametsYear[2] = ui->spinBox_4->value();
    a->tournametsYear[3] = ui->spinBox_5->value();
    close();
}

void StructInputDialog::on_spinBox_valueChanged(int value)
{
    ui->spinBox_2->setMinimum(value);
    ui->spinBox_3->setMinimum(value);
    ui->spinBox_4->setMinimum(value);
    ui->spinBox_5->setMinimum(value);
}
