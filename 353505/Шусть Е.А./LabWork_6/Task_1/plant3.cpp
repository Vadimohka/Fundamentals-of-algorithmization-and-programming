#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_nextButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushInputButton_3_clicked()
{
    plant3->age = ui->ageBox_3->value();
    plant3->height = ui->heightBox_3->value();
    plant3->SolarSystem = (ui->yesBox_3->isChecked()) ? true : false;
    plant3->nutrients[2] = ui->nutrientsBox_3->value();
    plant3->name[2] = ui->nameEdit_3->text();

    if (ui->bBox_3->isChecked()) {
        refPlant.number = 'Y';
    } else if (ui->eBox_3->isChecked()) {
        refPlant.number = 'N';
    }

    ui->textEdit_3->clear();
    ui->textEdit_3->setText("Name: " + plant3->name[2] + " | "
                            + "Number: " + QString::number(plant3->nutrients[2]) + " | "
                            + plant3->plantToString());
}
