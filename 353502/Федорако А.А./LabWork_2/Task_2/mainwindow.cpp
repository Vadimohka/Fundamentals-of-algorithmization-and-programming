#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QErrorMessage>
#include <QGraphicsView>
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Железнодорожный вокзал");
    ui->plainTextEdit->setReadOnly(true);
}


void MainWindow::showErrorEvent(QString information) {
    QMessageBox box;
    box.setWindowTitle("Ошибка");
    box.setText(information);
    box.setIcon(QMessageBox::Critical);
    box.exec();
}

void MainWindow::showInformationEvent(QString information) {
    QMessageBox box;
    box.setWindowTitle("Информационная панель");
    box.setIcon(QMessageBox::Information);
    box.setText(information);
    box.exec();
}
void MainWindow::on_pushButton_open_file_clicked()
{
    bool correct = file->setFilePath();
    if(correct == 0) {
        showErrorEvent("Выберите корректный файл!");
    }
    else {
        ui->plainTextEdit->setPlainText(file->getTextInformation());
    }

}

void MainWindow::on_pushButton_search_drive_place_clicked()
{
    if(file->getIsFileOpen() == true) {
    QString text = ui->lineEdit->text();
    QRegularExpression englishLettersRegex("^[a-zA-Z]+$");
    if(text.contains(englishLettersRegex)) {
        file->setSearchFinalDestination(text);
        ui->plainTextEdit->setPlainText(file->getTextInformation());
    }
    else {
        showErrorEvent("Введите корректное наименование населенного пункта!");
    }
    }
        else {
            showErrorEvent("Для поиска поездок необходимо открыть файл!");
    }
}



void MainWindow::on_pushButton_search_drive_date_clicked()
{
    if(file->getIsFileOpen() == true) {
    QDate currentDateTime = ui->dateEdit->date();

    file->setSearchDate(currentDateTime);
    ui->plainTextEdit->setPlainText(file->getTextInformation());
    }
    else {
            showErrorEvent("Для поиска поездок необходимо открыть файл!");

}
}

void MainWindow::on_pushButton_cancel_search_clicked()
{
    if(file->getIsFileOpen() == true) {
    file->setCanselAllSearchInformation();
    ui->plainTextEdit->setPlainText(file->getTextInformation());

    }
    else {
        showErrorEvent("Для отмены характеристик поиска необходимо открыть файл!");
    }
}


void MainWindow::on_pushButton_save_five_clicked()
{
    if(file->getIsFileOpen()) {
    file->saveFileAtFinishWork();
    ui->plainTextEdit->clear();
    showInformationEvent("Файл успешно сохранен");
    }
    else {
        showErrorEvent("Для сохранения необходимо открыть файл!");
    }
}


void MainWindow::on_pushButton_close_file_clicked()
{
    if(file->getIsFileOpen()) {
    file->closeFile();
    ui->plainTextEdit->clear();
    showInformationEvent("Файл успешно закрыт");}
    else {
        showErrorEvent("Для закрытия необходимо открыть файл!");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(file->getIsFileOpen() == true) {
        QString numberFlightDelete = ui->lineEdit_delete->text();
        if(file->deleteTrainTrip(numberFlightDelete) == true) {
            ui->plainTextEdit->setPlainText(file->getTextInformation());
            ui->lineEdit_delete->clear();
        }
        else {
            showErrorEvent("Поездки с данным номером не существует!");
        }
    }
    else {
        showErrorEvent("Для удаление поездки необходимо открыть файл!");
    }

}


void MainWindow::on_pushButton_add_trip_clicked()
{
    if(file->getIsFileOpen() == true) {

    QString flightNumber = ui->lineEdit_3->text();

    QDateTime timeDeparture = ui->dateTimeEdit_2->dateTime();
    QDateTime timeArrival = ui->dateTimeEdit_3->dateTime();
    QString finalDestination = ui->lineEdit_2->text();

    int numberOfCompartmentsSeats = ui->spinBox_4->value();
    int numberOfReservedSeats = ui->spinBox_3->value();
    int numberOfFreeCompartmentsSeats = ui->spinBox->value();
    int numberOfFreeReservedSeats = ui->spinBox_2->value();

    QDateTime resetDateTime = QDateTime::fromString("01.янв.00 00:00", "dd.MMM.yy hh:mm");


    int resultOfAddInformation = file->addNewTrainTrip(flightNumber, timeDeparture, timeArrival, finalDestination, numberOfCompartmentsSeats, numberOfReservedSeats, numberOfFreeCompartmentsSeats, numberOfFreeReservedSeats);
    if(resultOfAddInformation > 0) {
        ui->plainTextEdit->setPlainText(file->getTextInformation());
        ui->lineEdit_3->clear();
        ui->dateTimeEdit_2->setDateTime(resetDateTime);
        ui->dateTimeEdit_3->setDateTime(resetDateTime);
        ui->lineEdit_2->clear();
        ui->spinBox_4->setValue(0);
        ui->spinBox->setValue(0);
        ui->spinBox_2->setValue(0);
        ui->spinBox_3->setValue(0);
    }
    else {
        QString errorInformation = "Введите корректную информацию о ";
        switch (resultOfAddInformation) {
            case -1: {
                errorInformation += "номере рейса!";
                break;
            }
            case -2: {
                errorInformation += "дате убытия и прибытия поезда!";
                break;
            }
            case -3: {
                errorInformation += "конечном пункте!";
                break;
            }
            case -4: {
                errorInformation += "количестве мест!";
                break;
            }
        default: {
                errorInformation += "номере рейса!";
                break;
            }
        };
        showErrorEvent(errorInformation);
    }
    }
    else {
        showErrorEvent("Для добавление поездки необходимо открыть файл!");
    }

}

