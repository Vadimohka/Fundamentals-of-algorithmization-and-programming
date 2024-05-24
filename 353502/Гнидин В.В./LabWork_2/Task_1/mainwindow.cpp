//
// Created by volodya-petarda on 4/3/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->birthdayButton, SIGNAL(clicked()), this, SLOT(setBirthday()));
    connect(ui->changeButton, SIGNAL(clicked()), this, SLOT(setNewDate()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addDate()));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(openFile()));
}

mainwindow::~mainwindow() {
    delete ui;
}


void mainwindow::readFile(QString path) {
    QFile file(path);
    if(!file.exists()){
        QMessageBox b;
        b.setText("There is no such file, try again\n");
        b.exec();
        return;
    }
    this->path = path;
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString temp;
        temp = in.readLine();
        try {
            Date date(temp.toStdString());
            dates.push_back(date);
        }
        catch(...){
            QMessageBox b;
            b.setText("incorrect file format :((\n");
            b.exec();
            dates.clear();
            return;
        }
    }
    file.close();
}

void mainwindow::showDates() {
    QTableWidget *table = this->ui->tableWidget;
    table->setRowCount(dates.size());
    int ind = 0;
    for(Date d : dates){
        auto *dateItem = new QTableWidgetItem();
        QString text = QString::fromStdString(d.ToString());
        dateItem->setText(text);
        this->ui->tableWidget->setItem(ind, 0, dateItem);

        auto *nextDateItem = new QTableWidgetItem;
        text = QString::fromStdString(d.NextDay().ToString());
        nextDateItem->setText(text);
        if(d.ToString() == "31.12.9999")
            nextDateItem->setText("idk");
        this->ui->tableWidget->setItem(ind, 1, nextDateItem);

        auto *previousDateItem = new QTableWidgetItem;
        text = QString::fromStdString(d.PreviousDay().ToString());
        previousDateItem->setText(text);
        if(d.ToString() == "01.01.0001")
            previousDateItem->setText("idk");
        this->ui->tableWidget->setItem(ind, 2, previousDateItem);

        auto *deltDateItem = new QTableWidgetItem;
        if(ind != dates.size() - 1){
            deltDateItem->setText(QString::fromStdString(std::to_string(d.Duration(dates[ind + 1]))));
        }
        else{
            deltDateItem->setText("-");
        }
        this->ui->tableWidget->setItem(ind, 3, deltDateItem);

        auto *birthdayItem = new QTableWidgetItem;
        text = QString::fromStdString(std::to_string(d.DaysTillYourBirthday(birthday)));
        birthdayItem->setText(text);
        this->ui->tableWidget->setItem(ind, 4, birthdayItem);
        ind++;
    }
}

void mainwindow::setBirthday(){
    QDate date = this->ui->dateEdit->date();
    birthday = Date(date.day(), date.month(), date.year());
    showDates();
}

void mainwindow::setNewDate() {
    QList<QTableWidgetItem*> items = this->ui->tableWidget->selectedItems();
    if(items.size() == 0)
        return;
    auto *item = items[0];
    int ind = item->row();

    QDate date = this->ui->dateEdit->date();

    dates[ind] = Date(date.day(), date.month(), date.year());
    showDates();

    QFile file(path);
    file.open(QIODevice::ReadWrite);
    file.seek(11 * ind);

    QTextStream out(&file);
    out<<QString::fromStdString(dates[ind].ToString());
    file.close();
}

void mainwindow::addDate() {
    QDate date = this->ui->dateEdit->date();

    dates.push_back(Date(date.day(), date.month(), date.year()));
    showDates();
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    file.seek(dates.size() * 11 - 12);

    QTextStream out(&file);
    out<<'\n'<<QString::fromStdString(dates[dates.size() - 1].ToString());
    file.close();
}

void mainwindow::openFile() {
    QString filter = "(*.txt)";
    this->readFile(QFileDialog::getOpenFileName(nullptr, "Select a file...", QDir::homePath(), filter));
    this->showDates();
}


