#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    const QStringList name = {"Day","Next Day","Difference"};
    ui -> tableWidget->setHorizontalHeaderLabels(name);
    date = new MyDate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    vecDates.clear();
    ui->tableWidget->clear();
    sFilePath = QFileDialog::getOpenFileName(this, "Выбрать файл", "/home/senya/qt/Lab_2", "Text Files(*.txt)");
    QFile fileDates(sFilePath);
    QString line;
    if (fileDates.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&fileDates);
        int i = 0;
        while (!stream.atEnd()){
            line = stream.readLine();
            QDate dateList = QDate::fromString(line, "dd.MM.yyyy");
            mDate = new MyDate(dateList);
            ui -> tableWidget -> setItem(i, 0, new QTableWidgetItem(dateList.toString("dd.MM.yyyy")));
            ui -> tableWidget -> setItem(i, 1, new QTableWidgetItem((dateList.addDays(1)).toString("dd.MM.yyyy")));
            if(i > 0){
                ui -> tableWidget -> setItem(i-1, 2, new QTableWidgetItem(QString::number((vecDates.back().date).daysTo(mDate->date))));
            }
            vecDates.push_back(*mDate);
            i++;
            if(i >= 1){
                ui->tableWidget->setRowCount(i + 1);
            }
            szInFile = i;
        }
    }

    fileDates.close();
}

void MainWindow::on_pushButton_next_clicked()
{
    if(choseDateCheck){
        ui -> lineEdit_2 -> setText(MyDate::NextDay(chosenDate).toString("dd.MM.yyyy"));
    }
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    cellChosen = true;
    chosenRow = row;
    chosenColumn = column;
    if(vecDates.size() > row && (column == 0 || column == 1)){
        chosenDate = vecDates[row].date.addDays(column);
        choseDateCheck = true;
    }
    else{
        choseDateCheck = false;
    }
}

void MainWindow::on_pushButton_previous_clicked()
{
    if(choseDateCheck){
        ui -> lineEdit_2 -> setText(MyDate::PreviousDay(chosenDate).toString("dd.MM.yyyy"));
    }
}



void MainWindow::on_pushButton_BD_clicked()
{
    mmDate = new MyDate(ui->dateEdit->date());
    int n = (mmDate->DaysTillYourBirthday(mmDate->date));
    ui -> lineEdit_2 -> setText(QString::number(n));
}


void MainWindow::on_pushButton_diverse_clicked()
{
    miDate = new MyDate(chosenDate);
    int n = (miDate->Duration(miDate->date));
    ui -> lineEdit_2 -> setText(QString::number(n));
}


void MainWindow::on_pushButton_change_clicked()
{
    srand(time(NULL));
    if(!cellChosen)
        return;
    int szOfVec = vecDates.size();
    if(chosenColumn == 0){
        if(chosenRow >= szOfVec){
            if(chosenRow == szOfVec){
                vecDates.push_back(ui->dateEdit_2->date());
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
            }
            else
            {
                return;
            }
        }
        else{
            vecDates[chosenRow].date = ui->dateEdit_2->date();
        }
    }
    else{
        return;
    }
    chosenDate = ui -> dateEdit_2 -> date();
    szOfVec = vecDates.size();
    ui -> tableWidget -> setItem(chosenRow, 0, new QTableWidgetItem(vecDates[chosenRow].date.toString("dd.MM.yyyy"))); //  ? ? ?
    ui -> tableWidget -> setItem(chosenRow, 1, new QTableWidgetItem((vecDates[chosenRow].date.addDays(1)).toString("dd.MM.yyyy")));
    if(chosenRow > 0 && chosenRow < szOfVec){
        ui -> tableWidget -> setItem(chosenRow - 1, 2, new QTableWidgetItem(QString::number((vecDates[chosenRow - 1].date).daysTo(vecDates[chosenRow].date))));
    }
    if(chosenRow < szOfVec - 1){
        ui -> tableWidget -> setItem(chosenRow, 2, new QTableWidgetItem(QString::number((vecDates[chosenRow].date).daysTo(vecDates[chosenRow + 1].date))));
    }
    QDate dt;
    int dt_day = rand() % 31;
    int dt_month = rand() % 12;
    int dt_year = 1900 + rand() % 130;
    dt = QDate(dt_year, dt_month, dt_day);
    ui -> dateEdit_2->setDate(dt);
}

