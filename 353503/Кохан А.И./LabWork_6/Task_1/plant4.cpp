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
    refPlant.isFlowering = (ui->yesBox_4->isChecked()) ? true : false;
    refPlant.nutrients[3] = ui->nutrientsBox_4->value();
    refPlant.name[3] = ui->nameEdit_4->text();

    if (ui->aBox_4->isChecked()) {
        refPlant.vitamin = 'A';
    } else if (ui->bBox_4->isChecked()) {
        refPlant.vitamin = 'B';
    } else if (ui->cBox_4->isChecked()) {
        refPlant.vitamin = 'C';
    } else if (ui->dBox_4->isChecked()) {
        refPlant.vitamin = 'D';
    } else if (ui->eBox_4->isChecked()) {
        refPlant.vitamin = 'E';
    }

    ui->textEdit_4->clear();
    ui->textEdit_4->setText("Name: " + refPlant.name[3] + " | "
                            + "Nutrients: " + QString::number(refPlant.nutrients[3]) + " | "
                            + refPlant.plantToString());
}
