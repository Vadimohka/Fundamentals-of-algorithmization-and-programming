//
// Created by u on 10.04.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


void main_window::setMaxDay()
{
    ui->day->setMaximum(daysInMonths[ui->month->value() - 1] + (ui->month->value() == 2 ? Date::isLeap({1, 1, ui->year->value()}) : 0));
}

void main_window::save()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save a file", "../saves");
    if (file_name.isEmpty())
        return;

    if (file_name.mid(file_name.size() - 4, 4) != ".txt")
        file_name += ".txt";

    std::ofstream fout(file_name.toStdString());

    fout << birthdayDay << " " << birthdayMonth << " " << birthdayYear << '\n';

    for (auto &u : curDates)
        fout << u.getDay() << " " << u.getMonth() << " " << u.getYear() << "\n";

    fout.close();
}

void main_window::load()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Load a file", "../saves");
    if (file_name.isEmpty())
        return;

    if (file_name.mid(file_name.size() - 4, 4) != ".txt")
        file_name += ".txt";

    std::ifstream fin(file_name.toStdString());
    curDates.clear();

    fin >> birthdayDay >> birthdayMonth >> birthdayYear;

    while (!fin.eof())
    {
        try
        {
            int day, month, year;
            fin >> day >> month >> year;
            curDates.emplace_back(day, month, year);
        }
        catch(const char* error_message)
        {
            qDebug() << error_message << "\n";
            return;
        }
    }
    curDates.pop_back();
}

void main_window::add()
{
    curDates.emplace_back(Date(ui->day->value(), ui->month->value(), ui->year->value()));
}

void main_window::updateTable()
{
    ui->tableWidget->setRowCount((int)curDates.size());
    ui->changeBox->setMaximum(std::max(0, (int)curDates.size() - 1));

    for (int i = 0; i < curDates.size(); i++)
    {
        auto *dt = new QTableWidgetItem();
        QString day, month, year;
        day = QString::number(curDates[i].getDay());
        month = QString::number(curDates[i].getMonth());
        year = QString::number(curDates[i].getYear());
        while (day.size() < 2)
            day = "0" + day;
        while (month.size() < 2)
            month = "0" + month;
        while (year.size() < 4)
            year = "0" + year;
        dt->setText(day + "." + month + "." + year);
        ui->tableWidget->setItem(i, 0, dt);


        auto *isLeap = new QTableWidgetItem();
        if (Date::isLeap({curDates[i].getDay(), curDates[i].getMonth(), curDates[i].getYear()}))
            isLeap->setText("true");
        else
            isLeap->setText("false");
        ui->tableWidget->setItem(i, 1, isLeap);


        auto *nextDay = new QTableWidgetItem();
        date next = curDates[i].nextDay();
        day = QString::number(next.day);
        month = QString::number(next.month);
        year = QString::number(next.year);
        while (day.size() < 2)
            day = "0" + day;
        while (month.size() < 2)
            month = "0" + month;
        while (year.size() < 4)
            year = "0" + year;
        nextDay->setText(day + "." + month + "." + year);
        ui->tableWidget->setItem(i, 2, nextDay);


        auto *weekDay = new QTableWidgetItem();
        switch (curDates[i].weekNumber({curDates[i].getDay(), curDates[i].getMonth(), curDates[i].getYear()}))
        {
            case 0:
                weekDay->setText("Monday");
                break;
            case 1:
                weekDay->setText("Tuesday");
                break;
            case 2:
                weekDay->setText("Wednesday");
                break;
            case 3:
                weekDay->setText("Thursday");
                break;
            case 4:
                weekDay->setText("Friday");
                break;
            case 5:
                weekDay->setText("Saturday");
                break;
            case 6:
                weekDay->setText("Sunday");
                break;
            default:
                break;
        }
        ui->tableWidget->setItem(i, 3, weekDay);


        auto *daysTillNext = new QTableWidgetItem();
        int j = std::min(i + 1, (int)curDates.size() - 1);
        daysTillNext->setText(QString::number(curDates[i].duration(curDates[j].getDay(), curDates[j].getMonth(), curDates[j].getYear())));
        ui->tableWidget->setItem(i, 4, daysTillNext);


        auto *daysTillBirthday = new QTableWidgetItem();
        daysTillBirthday->setText(QString::number(curDates[i].daysTilYourBirthday(birthdayDay, birthdayMonth)));
        ui->tableWidget->setItem(i, 5, daysTillBirthday);


        day = QString::number(birthdayDay);
        month = QString::number(birthdayMonth);
        year = QString::number(birthdayYear);
        while (day.size() < 2)
            day = "0" + day;
        while (month.size() < 2)
            month = "0" + month;
        while (year.size() < 4)
            year = "0" + year;
        QString birthdayDate;
        birthdayDate = day + "." + month + "." + year;
        ui->bithday->setText(birthdayDate);
    }
}

void main_window::setBirthday()
{
    birthdayDay = ui->day->value();
    birthdayMonth = ui->month->value();
    birthdayYear = ui->year->value();
}

void main_window::change()
{
    curDates[ui->changeBox->value()].setDate(ui->day->value(), ui->month->value(), ui->year->value());
}

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);

    auto *timer = new QTimer(this);
    timer->setInterval(1);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTable()));
    timer->start();

    connect(ui->month, SIGNAL(valueChanged(int)), this, SLOT(setMaxDay()));
    connect(ui->year, SIGNAL(valueChanged(int)), this, SLOT(setMaxDay()));

    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->loadButton, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(ui->birthdayButton, SIGNAL(clicked(bool)), this, SLOT(setBirthday()));
    connect(ui->changeButton, SIGNAL(clicked(bool)), this, SLOT(change()));
}

main_window::~main_window()
{
    delete ui;
}
