#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <QFileDialog>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QTimer* myTimer = new QTimer(this);

    ui->setupUi(this);
    myTimer->setInterval(TimePeriodToChange);
    connect(myTimer, &QTimer::timeout, this, &MainWindow::showDateTime);
    myTimer->start();



}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showDateTime() {
    ui->label_4->setText(dateBirthday.getStrNowDate());
    ui->label_5->setText(dateBirthday.getStrNowTime());
}

void MainWindow::on_addBirthdayDay_clicked()
{
    strDateBirthday = ui->lineEdit->text();
    if(isLineCorrect(strDateBirthday) == true) {
    dateBirthday.fromString(strDateBirthday);
    ui->label->setText(strDateBirthday);
    }
    else {
        showErrorEvent("Введите корректное значение строки!");
    }
}


void MainWindow::on_ButtonAddDate_clicked()
{
    QString strNewDate = ui->lineEdit_2->text();
if(isLineCorrect(strNewDate) == true ) {
    if(file->getIsFileOpen() == true) {

        addNewDate(strNewDate);
        file->arrStrDate.push_back(strNewDate);
        ui->lineEdit_2->clear();
    }
    else {
        showErrorEvent("Для добавления даты необходимо открыть файл!");
    }
}
else {
    showErrorEvent("Введите корректное значение строки!");
}
}

void MainWindow::addNewDate(QString strNewDate) {

    Date newDate;
    newDate.fromString(strNewDate);


    arrDate.push_back(newDate);
    int coordinateOnX = arrDate.size() - NumberSecondColumb;
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    QTableWidgetItem *firstItem = new QTableWidgetItem;
    firstItem->setText(newDate.toString());
    ui->tableWidget->setItem(coordinateOnX, NumberFirstColumb, firstItem);

    QTableWidgetItem *secondItem = new QTableWidgetItem;
    secondItem->setText(newDate.NextDay().toString());
    ui->tableWidget->setItem(coordinateOnX, NumberSecondColumb, secondItem);

    QTableWidgetItem *thirdItem = new QTableWidgetItem;
    thirdItem->setText(newDate.PreviousDay().toString());
    ui->tableWidget->setItem(coordinateOnX, NumberThirdColumb, thirdItem);

    QTableWidgetItem *fourthItem = new QTableWidgetItem;
    fourthItem->setText(QVariant(newDate.IsLeap()).toString());
    ui->tableWidget->setItem(coordinateOnX, NumberFourColumb, fourthItem);

    QTableWidgetItem *fifthItem = new QTableWidgetItem;
    fifthItem->setText(newDate.getNameDayOfWeek());
    ui->tableWidget->setItem(coordinateOnX, NumberFiveColumb, fifthItem);

    QTableWidgetItem *sixthItem = new QTableWidgetItem;
    sixthItem->setText(QVariant(newDate.WeekNumber()).toString());
    ui->tableWidget->setItem(coordinateOnX, NumberSixColumb, sixthItem);

    QTableWidgetItem *seventhItem = new QTableWidgetItem;
    seventhItem->setText(QVariant(newDate.daysTillYourBithday(dateBirthday)).toString());
    ui->tableWidget->setItem(coordinateOnX, NumberSevenColumb, seventhItem);

    QTableWidgetItem *eighthItem = new QTableWidgetItem;
    eighthItem->setText(QVariant(newDate.Duration()).toString());
    ui->tableWidget->setItem(coordinateOnX, NumberEightColumb, eighthItem);
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


void MainWindow::on_pushButton_2_clicked()
{
    if(file->getIsFileOpen() == true) {
        showErrorEvent("Файл уже окрыт!");
    }
    else {
    if(strDateBirthday == "") {
        showErrorEvent("Выберите дату рождения!");
    }
    else {
    bool correct = file->setFilePath();
    if(correct == 0) {
        showErrorEvent("Выберите корректный файл!");
    }

    else {
        setAllTableWidget();
    }
    }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(file->getIsFileOpen()) {
    file->saveFileAtFinishWork();
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    QStringList headerLabels;
    headerLabels << "День" << "Следующий день" << "Предыдущий день" << "Високосный ли год" << "День недели" << "Номер недели" << "Дней до дня рождения  " << "Дней до сегодняшнего дня";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    arrDate.clear();
    showInformationEvent("Файл успешно сохранен");
    }
    else {
        showErrorEvent("Для сохранения необходимо открыть файл!");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(file->getIsFileOpen()) {
    file->closeFile();
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }

    QStringList headerLabels;
    headerLabels << "День" << "Следующий день" << "Предыдущий день" << "Високосный ли год" << "День недели" << "Номер недели" << "Дней до дня рождения  " << "Дней до сегодняшнего дня";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    arrDate.clear();

    showInformationEvent("Файл успешно закрыт");}
    else {
        showErrorEvent("Для закрытия необходимо открыть файл!");
    }
}

void MainWindow::setAllTableWidget() {
    for(unsigned int i = 0; i < (file->arrStrDate).size(); i++) {
        addNewDate(file->arrStrDate[i]);
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QString line = ui->lineEdit_3->text();

    if(isLineCorrect(line) == true) {
    if(file->getIsFileOpen() == false) {
        showErrorEvent("Для удаления даты необходимо открыть файл!");
    }
    else {
        if((int)file->arrStrDate.size() > NumberSecondColumb) {
        for(unsigned int i = 0; i < file->arrStrDate.size(); i++) {
            if(file->arrStrDate[i] == line) {
                qDebug() << file->arrStrDate[i] << ' ' << line << '\n';
                (file->arrStrDate).erase((file->arrStrDate).begin() + i);
                ui->tableWidget->removeRow(i);
            }
        }
        ui->lineEdit_3->clear();
        }
        else {
            showErrorEvent("Вы не можете удалить весь файл!");
        }
    }
    }
    else {
        showErrorEvent("Введите коррестное значение строки!");
    }
}

bool MainWindow::isLineCorrect(QString line) {
    if(line.size() != CorrectSizeLine) {
        return false;
    }
    else {

        for(int i = 0; i < line.size(); i++)  {
            if(i == NumberCoordinateOfSpaceFirst || i == NumberCoordinateOfSpaceSecond) {
                if(line[i] != '.') {
                    return false;
                }
            }
            else {
                if(line[i].isDigit() == false) {
                    return false;
                }
            }
        }
        QString strDay = line.mid(0,2);
        QString strMonth = line.mid(3,2);
        QString strYear = line.mid(NumberCoordinateOfYear,4);
        int valueDay = strDay.toInt();
        int valueMonth= strMonth.toInt();
        int valueYear = strYear.toInt();

        if(valueDay > NumberMaxDaysInMonth || valueMonth > NumberMaxMonthInYear || valueMonth < 1 ||valueYear == 0) {
            return false;
        }
        std::vector<int> arrDayIntMonth = date->getVectorDayIntMonth(valueYear);
        if(valueDay >  arrDayIntMonth[valueMonth - 1]) {
             return false;
        }

    }
    return true;

}
