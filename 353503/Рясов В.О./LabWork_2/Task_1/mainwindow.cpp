#include "date.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <fstream>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    messageBox.setWindowTitle("Ошибка");
    messageBox.setText("Неверный ввод");
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setStandardButtons(QMessageBox::Ok);
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::readFromFile);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::addDateToTable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkFormat(QString input)
{
    QRegularExpression dateRegEx(R"(^\d{2}-\d{2}-\d{4}$)");
    if(!dateRegEx.match(input).hasMatch()){
        messageBox.exec();
        isCorrect = false;
        return;
    }

    else{
        QStringList dates = input.split("-");
        Date date(dates[0].toInt(), dates[1].toInt(), dates[2].toInt());
        if((date.getMonth() <= 7 and date.getMonth() % 2 == 1 and date.getDay() > 31) or (date.getMonth() >= 8 and date.getMonth() % 2 == 0 and date.getDay() > 31)
            or (date.getMonth() == 2 and date.getDay() > 29 and date.isLeap(date.getYear())) or (date.getMonth() == 2 and date.getDay() > 28 and !date.isLeap(date.getYear())) or (date.getMonth() <= 7
            and date.getMonth() % 2 == 0 and date.getDay() > 30) or (date.getMonth() >= 8 and date.getMonth() % 2 == 1 and date.getDay() > 30) or date.getMonth() > 12){
            messageBox.exec();
            isCorrect = false;
            return;
        }

        isCorrect = true;
    }
}

void MainWindow::addDateToTable()
{
    int rowCount = ui->tableWidget->rowCount();
    QFile file(_pathToDateFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }
    static int i = -1;
    i == -1 ? i +=1 : i = _index + 1;
    for (i; i < _dates.size(); ++i){
            ui->tableWidget->insertRow(rowCount);
            QTableWidgetItem* item1 = new QTableWidgetItem;
            item1->setText(_dates.at(i).toQString()); // Измените формат даты, если он отличается
            ui->tableWidget->setItem(rowCount, 0, item1);

            QTableWidgetItem* item2 = new QTableWidgetItem;
            item2->setText(_dates.at(i).previousDay());
            ui->tableWidget->setItem(rowCount, 1, item2);

            QTableWidgetItem* item3 = new QTableWidgetItem;
            item3->setText(_dates.at(i).nextDay());
            ui->tableWidget->setItem(rowCount, 2, item3);

            QTableWidgetItem* item4 = new QTableWidgetItem;
            if(_dates.at(i).isLeap(_dates.at(i).getYear())){
                item4->setText("Да");
            }
            else {
                item4->setText("Нет");
            }
            ui->tableWidget->setItem(rowCount, 3, item4);

            QTableWidgetItem* item5 = new QTableWidgetItem;
            item5->setText(_dates.at(i).weekNumber());
            ui->tableWidget->setItem(rowCount, 4, item5);

            /*QTableWidgetItem* item6 = new QTableWidgetItem;
            item6->setText(_birthdiff);
            ui->tableWidget->setItem(rowCount, 5, item6);*/

            QTableWidgetItem* item6 = new QTableWidgetItem;
            QString dur = QString::number(_dates.at(i).duration(_dates.at(i)));
            item6->setText(dur);
            ui->tableWidget->setItem(rowCount, 5, item6);
            ++rowCount;
    }
    _index = i-1;
}

void MainWindow::on_pushButton_2_clicked()
{
    _pathToDateFile = QFileDialog::getOpenFileName(this, "иди нахуй пидарас", "/home/vlad/lab_2_task_1", "TXT File (*.txt)");
    entered = true;
}

std::vector<Date> MainWindow::readFromFile()
{
    std::ifstream file(_pathToDateFile.toStdString());
    int day;
    int month;
    int year;
    char delim;
    while (file >> day >> delim >> month >> delim >> year) {
        qDebug() << "d:" << day << "m:" << month << "y:" << year;
        _dates.emplace_back(day, month, year);
    }

    if (!file.eof()) {
        qDebug() << "Ошибка формата";
    }

    return _dates;
}

void MainWindow::addDateToFile()
{
    std::ofstream file(_pathToDateFile.toStdString(), std::ios::app);
    if (file.is_open()){
        file << _dates.back().getDay() << '-'
             << _dates.back().getMonth()
             << '-' << _dates.back().getYear() << ' ';
        file.close();
        QString line = _dates.back().toQString();
        _fileSize += line.length();
    }
    else{
        qDebug() << "Unable to open file";
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(entered){
        QString input = ui->lineEdit->text();
        checkFormat(input);
        if(isCorrect){
            QStringList dates = input.split("-");
            Date date(dates[0].toInt(), dates[1].toInt(), dates[2].toInt());
            _dates.push_back(date);
        }
        addDateToTable();
        addDateToFile();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString input = ui->lineEdit_2->text();
    checkFormat(input);
    if(isCorrect){
        QStringList dates = input.split("-");
        Date birthday(dates[0].toInt(), dates[1].toInt(), dates[2].toInt());
        _birthdiff = Date::daysTillYourBirthday(birthday);
        ui->label->setText(_birthdiff);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file(_pathToDateFile);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }

    ui->tableWidget->removeRow(_index);
    QString line = _dates.back().toQString();
    _dates.pop_back();
    --_index;
    int size = line.length(), delta = 1;
    file.resize(_fileSize - (size + delta));
    _fileSize -= (size + delta);
}

