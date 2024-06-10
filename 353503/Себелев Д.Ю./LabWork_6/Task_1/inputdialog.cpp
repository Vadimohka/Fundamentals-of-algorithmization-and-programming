#include "inputdialog.h"
#include "ui_inputdialog.h"

#include <QMessageBox>

InputDialog::InputDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputDialog)
{
    ui->setupUi(this);

    connect(ui->enter_btn, &QPushButton::clicked, this, &InputDialog::onEnterClicked);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::onEnterClicked()
{
    if (ui->name_lineEdit->text().isEmpty() ||
        ui->age_lineEdit->text().isEmpty() ||
        ui->gender_lineEdit->text().isEmpty() ||
        ui->weight_lineEdit->text().isEmpty() ||
        ui->sizes_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please fill all the fields");
        return;
    }

    Animal tempAnimal;
    bool ok;
    strcpy(tempAnimal.name, ui->name_lineEdit->text().toStdString().c_str());
    tempAnimal.age = ui->age_lineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Age should be a number");
        return;
    }
    char gender = ui->gender_lineEdit->text().toStdString().at(0);
    if (gender == 'M' || gender == 'F') {
        tempAnimal.gender = gender;
    } else {
        QMessageBox::critical(this, "Error", "Incorrect gender");
    }

    tempAnimal.isAlive = ui->isAlive_checkBox->isChecked();
    tempAnimal.weight = ui->weight_lineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Weight should be a number");
        return;
    }
    QString sizes = ui->sizes_lineEdit->text();
    QStringList sizeList = sizes.split(" ");
    for(int i = 0; i < sizeList.size(); i++) {
        tempAnimal.sizes[i] = sizeList[i].toInt(&ok);
        if (!ok) {
            QMessageBox::critical(this, "Error", "Size should be a number");
            return;
        }
    }

    emit animalEntered(tempAnimal);
    close();

    ui->name_lineEdit->clear();
    ui->age_lineEdit->clear();
    ui->gender_lineEdit->clear();
    ui->isAlive_checkBox->setChecked(false);
    ui->weight_lineEdit->clear();
    ui->sizes_lineEdit->clear();
}
