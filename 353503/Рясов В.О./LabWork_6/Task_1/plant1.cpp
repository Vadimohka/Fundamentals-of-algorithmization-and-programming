#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_nextButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushInputButton_clicked()
{
    char vitamin = '-';
    bool isFlowering = false;
    if (ui->aBox->isChecked()) {
        vitamin = 'A';
    } else if (ui->bBox->isChecked()) {
        vitamin = 'B';
    } else if (ui->cBox->isChecked()) {
        vitamin = 'C';
    } else if (ui->dBox->isChecked()) {
        vitamin = 'D';
    } else if (ui->eBox->isChecked()) {
        vitamin = 'E';
    }

    if (ui->yesBox->isChecked()) {
        isFlowering = true;
    }
    plant1 = {ui->ageBox->value(), ui->heightBox->value(), vitamin, isFlowering};

    plant1.nutrients[0] = ui->nutrientsBox->value();
    plant1.name[0] = ui->nameEdit->text();

    ui->textEdit->clear();
    ui->textEdit->setText("Name: " + plant1.name[0] + " | " + "Nutrients: "
                          + QString::number(plant1.nutrients[0]) + " | " + plant1.plantToString());
}
