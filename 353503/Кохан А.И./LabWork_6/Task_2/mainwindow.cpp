#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        && ui->doubleSpinBox->hasFocus()) {
        ui->inputEdit->setText(ui->inputEdit->toPlainText()
                               + QString::number(ui->doubleSpinBox->value()) + " | ");
        array.push_back(ui->doubleSpinBox->value());
    }
}

void MainWindow::on_inputButton_clicked()
{
    if (ui->inputEdit->toPlainText() != "") {
        switch (ui->comboBox->currentIndex()) {
        case 0: {
            FileInputOutput::writeToFile(pathToSimpleParagraph, ui->inputEdit->toPlainText());
            break;
        }
        case 1: {
            if (!array.empty()) {
                FileInputOutput::writeArrayToFile(pathToArray, array);
            }
            break;
        }
        case 2: {
            FileInputOutput::writeStructToTxtFile(pathToTxtStruct, plant);
            break;
        }
        case 3: {
            FileInputOutput::writeStructToBinFile(pathToBinStruct, plant);
            break;
        }
        case 4: {
            FileInputOutput::appendSentenceToFile(pathToListSentences, ui->inputEdit->toPlainText());
            break;
        }
        }
    }
}

void MainWindow::on_outputButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToSimpleParagraph));
        break;
    }
    case 1: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToArray));
        break;
    }
    case 2: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromTxtFile(pathToTxtStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromTxtFile(pathToTxtStruct)[i].plantToString());
        }
        break;
    }
    case 3: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromBinFile(pathToBinStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromBinFile(pathToBinStruct)[i].plantToString());
        }
        break;
    }
    case 4: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToListSentences));
        break;
    }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if (index == 0 || index == 4) {
        ui->inputEdit->setReadOnly(false);
    } else {
        ui->inputEdit->setReadOnly(true);
    }
    ui->inputEdit->clear();
    ui->outputEdit->clear();
}

void MainWindow::on_clearButton_clicked()
{
    ui->inputEdit->clear();
    if (ui->comboBox->currentIndex() == 1) {
        array.clear();
    }
}

void MainWindow::on_addButton_clicked()
{
    plant.age = ui->ageBox->value();
    plant.height = ui->heightBox->value();
    plant.isFlowering = (ui->yesBox->isChecked()) ? true : false;

    if (ui->aBox->isChecked()) {
        plant.vitamin = 'A';
    } else if (ui->bBox->isChecked()) {
        plant.vitamin = 'B';
    } else if (ui->cBox->isChecked()) {
        plant.vitamin = 'C';
    } else if (ui->dBox->isChecked()) {
        plant.vitamin = 'D';
    } else if (ui->eBox->isChecked()) {
        plant.vitamin = 'E';
    }

    ui->inputEdit->setText(plant.plantToString());
}

void MainWindow::on_addButtonBin_clicked()
{
    plant.age = ui->ageBox->value();
    plant.height = ui->heightBox->value();
    plant.isFlowering = (ui->yesBox->isChecked()) ? true : false;

    if (ui->aBox->isChecked()) {
        plant.vitamin = 'A';
    } else if (ui->bBox->isChecked()) {
        plant.vitamin = 'B';
    } else if (ui->cBox->isChecked()) {
        plant.vitamin = 'C';
    } else if (ui->dBox->isChecked()) {
        plant.vitamin = 'D';
    } else if (ui->eBox->isChecked()) {
        plant.vitamin = 'E';
    }

    ui->inputEdit->setText(plant.plantToString());
}
