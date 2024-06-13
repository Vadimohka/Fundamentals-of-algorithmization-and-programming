#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_nextButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushInputButton_2_clicked()
{
    plant2.age = ui->ageBox_2->value();
    plant2.height = ui->heightBox_2->value();
    plant2.isFlowering = (ui->yesBox_2->isChecked()) ? true : false;
    plant2.nutrients[1] = ui->nutrientsBox_2->value();
    plant2.name[1] = ui->nameEdit_2->text();

    if (ui->aBox_2->isChecked()) {
        plant2.vitamin = 'A';
    } else if (ui->bBox_2->isChecked()) {
        plant2.vitamin = 'B';
    } else if (ui->cBox_2->isChecked()) {
        plant2.vitamin = 'C';
    } else if (ui->dBox_2->isChecked()) {
        plant2.vitamin = 'D';
    } else if (ui->eBox_2->isChecked()) {
        plant2.vitamin = 'E';
    }

    ui->textEdit_2->clear();
    ui->textEdit_2->setText("Name: " + plant2.name[1] + " | "
                            + "Nutrients: " + QString::number(plant2.nutrients[1]) + " | "
                            + plant2.plantToString());
}
