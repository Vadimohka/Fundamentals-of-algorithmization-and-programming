#include "userinputdialog.h"
#include "ui_userinputdialog.h"

UserInputDialog::UserInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInputDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(Auto::MAX_NAME_SIZE - 1);

    // Connect the signal for spinBox value changes to the slot
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
}

UserInputDialog::~UserInputDialog()
{
    delete ui;
}

void UserInputDialog::on_buttonBox_accepted()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(this, tr("Wrong Input"), tr("None of the fields should be empty"), QMessageBox::Ok);
        return;
    }

    QString name = ui->lineEdit->text();
    std::copy(name.begin(), name.end(), input.name);
    input.name[name.length()] = '\0';

    input.year = ui->spinBox->value();
    input.model = ui->lineEdit_2->text().isEmpty() ? '\0' : ui->lineEdit_2->text().at(0).toLatin1();
    input.cost = ui->doubleSpinBox->value();
    input.isPassengerCar = ui->checkBox->isChecked();

    input.wheelsYear[0] = ui->spinBox_2->value();
    input.wheelsYear[1] = ui->spinBox_3->value();
    input.wheelsYear[2] = ui->spinBox_4->value();
    input.wheelsYear[3] = ui->spinBox_5->value();

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
