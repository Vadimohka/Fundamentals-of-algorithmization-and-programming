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
    plant3->isFlowering = (ui->yesBox_3->isChecked()) ? true : false;
    plant3->nutrients[2] = ui->nutrientsBox_3->value();
    plant3->name[2] = ui->nameEdit_3->text();

    if (ui->aBox_3->isChecked()) {
        plant3->vitamin = 'A';
    } else if (ui->bBox_3->isChecked()) {
        plant3->vitamin = 'B';
    } else if (ui->cBox_3->isChecked()) {
        plant3->vitamin = 'C';
    } else if (ui->dBox_3->isChecked()) {
        plant3->vitamin = 'D';
    } else if (ui->eBox_3->isChecked()) {
        plant3->vitamin = 'E';
    }

    ui->textEdit_3->clear();
    ui->textEdit_3->setText("Name: " + plant3->name[2] + " | "
                            + "Nutrients: " + QString::number(plant3->nutrients[2]) + " | "
                            + plant3->plantToString());
}
