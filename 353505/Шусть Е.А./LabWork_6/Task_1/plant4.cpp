#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_nextButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushInputButton_4_clicked()
{
    refPlant.age = ui->ageBox_4->value();
    refPlant.height = ui->heightBox_4->value();
    refPlant.SolarSystem = (ui->yesBox_4->isChecked()) ? true : false;
    refPlant.nutrients[3] = ui->nutrientsBox_4->value();
    refPlant.name[3] = ui->nameEdit_4->text();

    if (ui->bBox_4->isChecked()) {
        refPlant.number = 'Y';
    } else if (ui->eBox_4->isChecked()) {
        refPlant.number = 'N';
    }

    ui->textEdit_4->clear();
    ui->textEdit_4->setText("Name: " + refPlant.name[3] + " | "
                            + "Number: " + QString::number(refPlant.nutrients[3]) + " | "
                            + refPlant.plantToString());
}
