#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushInputButton_clicked()
{
    char number = '-';
    bool SolarSystem = false;
    if (ui->bBox->isChecked()) {
        number = 'Y';
    } else if (ui->eBox->isChecked()) {
        number = 'N';
    }

    if (ui->yesBox->isChecked()) {
        SolarSystem = true;
    }
    plant1 = {ui->ageBox->value(), ui->heightBox->value(), number, SolarSystem};

    plant1.nutrients[0] = ui->nutrientsBox->value();
    plant1.name[0] = ui->nameEdit->text();

    ui->textEdit->clear();
    ui->textEdit->setText("Name: " + plant1.name[0] + " | " + "Nutrients: "
                          + QString::number(plant1.nutrients[0]) + " | " + plant1.plantToString());
}
