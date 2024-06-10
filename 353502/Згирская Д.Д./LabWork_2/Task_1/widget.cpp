#include "widget.h"
#include "./ui_widget.h"
#include "Date.h"

Widget::Widget(QWidget *parent)
        : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->tableWidget->setRowCount(2);
    QTableWidgetItem *now = new QTableWidgetItem(
            QString::number(currentTime.getDay()) + '.' + QString::number(currentTime.getMonth()) + '.' +
            QString::number(currentTime.getYear()));
    QTableWidgetItem *previous = new QTableWidgetItem(QString::number(currentTime.PreviousDay().getDay()) + '.' +
                                                      QString::number(currentTime.PreviousDay().getMonth()) + '.' +
                                                      QString::number(currentTime.PreviousDay().getYear()));
    QTableWidgetItem *next = new QTableWidgetItem(
            QString::number(currentTime.NextDay().getDay()) + '.' + QString::number(currentTime.NextDay().getMonth()) +
            '.' + QString::number(currentTime.NextDay().getYear()));
    QTableWidgetItem *weekNumber = new QTableWidgetItem(QString::number(currentTime.WeekNumber()));
    ui->tableWidget->setItem(0, 1, now);
    ui->tableWidget->setItem(0, 0, previous);
    ui->tableWidget->setItem(0, 2, next);
    ui->tableWidget->setItem(0, 3, weekNumber);
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 4, new QTableWidgetItem("_"));
    ui->tableWidget->setItem(1, 5, new QTableWidgetItem("_"));
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_open_file_clicked() {
    _path = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;");
    fromFileToVector();
    showTable();
}

void Widget::fromFileToVector() {
    if (_path != nullptr && !input.is_open()) {
        input.open(_path.toUtf8(), std::ofstream::in);
    }
    if (input.is_open()) {
        _dateVector.clear();
        Date temp;
        QString day, month, year;
        std::string line;
        while (std::getline(input, line)) {
            qDebug() << 5;
            day = QString(line[0]) + QString(line[1]);
            month = QString(line[3]) + QString(line[4]);
            year = QString(line[6]) + QString(line[7]) + QString(line[8]) + QString(line[9]);
            temp = Date(day.toUInt(), month.toUInt(), year.toUInt());
            _dateVector.push_back(temp);
        }
        input.close();
    }
    showTable();
}

void Widget::addToFile(QString added) {
    if (_path != nullptr) {
        output.open(_path.toUtf8(), std::ofstream::app);
        if (output.is_open()) {
            output << '\n' << added.toStdString();
            output.close();
            fromFileToVector();
        }
    }
    showTable();
}


void Widget::on_add_to_file_clicked() {
    if (_path == nullptr) {
        qDebug() << "File is not selected";
    } else {
        QString date = ui->add_date->text();
        if (checkInput(date) == 0) {
            ui->add_date->setText("Error!");
            QTimer::singleShot(600, this, SLOT(error()));
        } else {
            addToFile(date);
        }
    }
}

void Widget::error() {
    ui->add_date->setText("");
}

void Widget::showTable() {
    ui->tableWidget->setRowCount(2 + _dateVector.size());

    if (isBirthdaySet == 1) {
        if (birthday.getYear() == 0) {
            //currentTime 4, 5
            ui->tableWidget->setItem(0, 4, new QTableWidgetItem("_"));
            ui->tableWidget->setItem(0, 5, new QTableWidgetItem("_"));

            //birthday row
            for (int i = 0; i < 6; ++i) {
                ui->tableWidget->setItem(1, i, new QTableWidgetItem("Date doesn't exists!"));
            }

            //birthday
            for (int i = 0; i < _dateVector.size(); ++i) {
                ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem("_"));
            }
        }
        else {
            //currentTime 4, 5
            ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(currentTime.Duration(birthday))));
            ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(currentTime.DaysTillYourBirthday(nextBirthday))));

            //birthday row
            ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(birthday.getDay()) + '.' + QString::number(birthday.getMonth()) + '.' + QString::number(birthday.getYear())));
            ui->tableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(birthday.WeekNumber())));
            ui->tableWidget->setItem(1, 4, new QTableWidgetItem("_"));

            //birthday
            if (birthday.getYear() < 9999 && birthday.getYear() >= 1) {
                ui->tableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(nextBirthday.getDay()) + '.' + QString::number(nextBirthday.getMonth()) + '.' + QString::number(nextBirthday.getYear())));
                ui->tableWidget->setItem(1, 5, new QTableWidgetItem(QString::number(birthday.DaysTillYourBirthday(nextBirthday))));
                for (int i = 0; i < _dateVector.size(); ++i) {
                    if (_dateVector[i].getYear() == 0) {
                        ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem("_"));
                    }
                    else {
                        if (_dateVector[i].getYear() < birthday.getYear() || _dateVector[i].getYear() == birthday.getYear() && _dateVector[i].getMonth() < birthday.getMonth() || _dateVector[i].getYear() == birthday.getYear() && _dateVector[i].getMonth() == birthday.getMonth() && _dateVector[i].getDay() <= birthday.getDay()) {
                            ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem(QString::number(_dateVector[i].DaysTillYourBirthday(birthday))));
                        }
                        else {
                            ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem(QString::number(_dateVector[i].DaysTillYourBirthday(nextBirthday))));
                        }
                    }
                }
            }
            else {
                ui->tableWidget->setItem(1, 2, new QTableWidgetItem("Out of range!"));
                ui->tableWidget->setItem(1, 5, new QTableWidgetItem("_"));
                for (int i = 2; i < _dateVector.size(); ++i) {
                    if (_dateVector[i].getYear() == 0) {
                        ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem("_"));
                    }
                    else {
                        if (_dateVector[i].getYear() < birthday.getYear() || _dateVector[i].getYear() == birthday.getYear() && _dateVector[i].getMonth() < birthday.getMonth() || _dateVector[i].getYear() == birthday.getYear() && _dateVector[i].getMonth() == birthday.getMonth() && _dateVector[i].getDay() <= birthday.getDay()) {
                            ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem(QString::number(_dateVector[i].DaysTillYourBirthday(birthday))));
                        }
                        else {
                            ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem("_"));
                        }
                    }
                }
            }
            if (birthday.getYear() == 1) {
                ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Out of range!"));
            }
            else {
                ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(previousBirthday.getDay()) + '.' + QString::number(previousBirthday.getMonth()) + '.' + QString::number(previousBirthday.getYear())));
            }
        }
    }
    else {
        ui->tableWidget->setItem(0, 4, new QTableWidgetItem("_"));
        ui->tableWidget->setItem(0, 5, new QTableWidgetItem("_"));
        for (int i = 0; i < _dateVector.size(); ++i) {
            ui->tableWidget->setItem(i + 2, 5, new QTableWidgetItem("_"));
        }
        for (int i = 0; i < 6; ++i) ui->tableWidget->setItem(1, i, new QTableWidgetItem("_"));
    }


    for (int i = 0; i < _dateVector.size(); ++i) {
        if (_dateVector[i].getYear() == 0) {
            _tableNowVector.push_back(new QTableWidgetItem("Date doesn't exists!"));
            ui->tableWidget->setItem(i + 2, 1, _tableNowVector[i]);
            _tablePreviousVector.push_back(new QTableWidgetItem("Date doesn't exists!"));
            ui->tableWidget->setItem(i + 2, 0, _tablePreviousVector[i]);
            _tableNextVector.push_back(new QTableWidgetItem("Date doesn't exists!"));
            ui->tableWidget->setItem(i + 2, 2, _tableNextVector[i]);
            _tableWeekNumberVector.push_back(new QTableWidgetItem("Date doesn't exists!"));
            ui->tableWidget->setItem(i + 2, 3, _tableWeekNumberVector[i]);
            ui->tableWidget->setItem(i + 2, 4, new QTableWidgetItem("Date doesn't exists!"));
        }
        else if (_dateVector[i].getYear() == 1 && _dateVector[i].getMonth() == 1 && _dateVector[i].getDay() == 1) {

            qDebug() << "p2";
            _tableNowVector.push_back(new QTableWidgetItem(
                    QString::number(_dateVector[i].getDay()) + '.' + QString::number(_dateVector[i].getMonth()) + '.' +
                    QString::number(_dateVector[i].getYear())));
            ui->tableWidget->setItem(i + 2, 1, _tableNowVector[i]);
            _tablePreviousVector.push_back(new QTableWidgetItem("Out of range!"));
            ui->tableWidget->setItem(i + 2, 0, _tablePreviousVector[i]);
            _tableNextVector.push_back(new QTableWidgetItem(QString::number(_dateVector[i].NextDay().getDay()) + '.' +
                                                            QString::number(_dateVector[i].NextDay().getMonth()) + '.' +
                                                            QString::number(_dateVector[i].NextDay().getYear())));
            ui->tableWidget->setItem(i + 2, 2, _tableNextVector[i]);
            _tableWeekNumberVector.push_back(new QTableWidgetItem(QString::number(_dateVector[i].WeekNumber())));
            ui->tableWidget->setItem(i + 2, 3, _tableWeekNumberVector[i]);
        }
        else if (_dateVector[i].getYear() == 9999 && _dateVector[i].getMonth() == 12 &&
                   _dateVector[i].getDay() == 31) {

            qDebug() << "p3";
            _tableNowVector.push_back(new QTableWidgetItem(
                    QString::number(_dateVector[i].getDay()) + '.' + QString::number(_dateVector[i].getMonth()) + '.' +
                    QString::number(_dateVector[i].getYear())));
            ui->tableWidget->setItem(i + 2, 1, _tableNowVector[i]);
            _tablePreviousVector.push_back(new QTableWidgetItem(
                    QString::number(_dateVector[i].PreviousDay().getDay()) + '.' +
                    QString::number(_dateVector[i].PreviousDay().getMonth()) + '.' +
                    QString::number(_dateVector[i].PreviousDay().getYear())));
            ui->tableWidget->setItem(i + 2, 0, _tablePreviousVector[i]);
            _tableNextVector.push_back(new QTableWidgetItem("Out of range!"));
            ui->tableWidget->setItem(i + 2, 2, _tableNextVector[i]);
            _tableWeekNumberVector.push_back(new QTableWidgetItem(QString::number(_dateVector[i].WeekNumber())));
            ui->tableWidget->setItem(i + 2, 3, _tableWeekNumberVector[i]);
        }
        else {

            qDebug() << "p4";
            _tableNowVector.push_back(new QTableWidgetItem(
                    QString::number(_dateVector[i].getDay()) + '.' + QString::number(_dateVector[i].getMonth()) + '.' +
                    QString::number(_dateVector[i].getYear())));
            ui->tableWidget->setItem(i + 2, 1, _tableNowVector[i]);
            _tablePreviousVector.push_back(new QTableWidgetItem(
                    QString::number(_dateVector[i].PreviousDay().getDay()) + '.' +
                    QString::number(_dateVector[i].PreviousDay().getMonth()) + '.' +
                    QString::number(_dateVector[i].PreviousDay().getYear())));
            ui->tableWidget->setItem(i + 2, 0, _tablePreviousVector[i]);
            _tableNextVector.push_back(new QTableWidgetItem(QString::number(_dateVector[i].NextDay().getDay()) + '.' +

                                                            QString::number(_dateVector[i].NextDay().getMonth()) + '.' +
                                                            QString::number(_dateVector[i].NextDay().getYear())));
            ui->tableWidget->setItem(i + 2, 2, _tableNextVector[i]);
            _tableWeekNumberVector.push_back(new QTableWidgetItem(QString::number(_dateVector[i].WeekNumber())));
            ui->tableWidget->setItem(i + 2, 3, _tableWeekNumberVector[i]);
        }
    }

    for (int i = 0, j; i + 1 < _dateVector.size(); ++i) {
        qDebug() << i;
        while (_dateVector[i].getYear() == 0 && i + 2 < _dateVector.size()) {
            _tableDurationVector.push_back(new QTableWidgetItem("_"));
            ui->tableWidget->setItem(i + 2, 4, _tableDurationVector[i]);
            ++i;
        }
        _tableDurationVector.push_back(new QTableWidgetItem("*"));
        j = i + 1;
        while (_dateVector[j].getYear() == 0 && j + 1 < _dateVector.size()) {
            _tableDurationVector.push_back(new QTableWidgetItem("_"));
            ui->tableWidget->setItem(j + 2, 4, _tableDurationVector[j]);
            ++j;
        }
        if (_dateVector[j].getYear() == 0) {
            _tableDurationVector[i] = new QTableWidgetItem("_");
            ui->tableWidget->setItem(i + 2, 4, _tableDurationVector[i]);
            break;
        }
        else {
            _tableDurationVector[i] = new QTableWidgetItem(QString::number(_dateVector[i].Duration(_dateVector[j])));
            ui->tableWidget->setItem(i + 2, 4, _tableDurationVector[i]);
            i = j - 1;
        }
    }

    ui->tableWidget->setItem(_dateVector.size() + 1, 4, new QTableWidgetItem("_"));

    _tableNowVector.clear();
    _tablePreviousVector.clear();
    _tableNextVector.clear();
    _tableWeekNumberVector.clear();
    _tableDurationVector.clear();
    _tableTillBirthdayVector.clear();
}


void Widget::on_set_birthday_clicked() {
    QString date = ui->add_date->text();
    if (checkInput(date)) {
        isBirthdaySet = 1;
        QString day, month, year;
        std::string line = date.toStdString();
        day = QString(line[0]) + QString(line[1]);
        month = QString(line[3]) + QString(line[4]);
        year = QString(line[6]) + QString(line[7]) + QString(line[8]) + QString(line[9]);
        birthday = Date(day.toUInt(), month.toUInt(), year.toUInt());
        if (birthday.getDay() == 29 && birthday.getMonth() == 2) {
            if (birthday.getYear() <= 9995)
                nextBirthday = Date(birthday.getDay(), birthday.getMonth(), birthday.getYear() + 4);
            if (birthday.getYear() >= 5)
                previousBirthday = Date(birthday.getDay(), birthday.getMonth(), birthday.getYear() - 4);
        } else {
            if (birthday.getYear() <= 9998)
                nextBirthday = Date(birthday.getDay(), birthday.getMonth(), birthday.getYear() + 1);
            if (birthday.getYear() >= 2)
                previousBirthday = Date(birthday.getDay(), birthday.getMonth(), birthday.getYear() - 1);
        }
    } else {
        isBirthdaySet = 0;
        ui->add_date->setText("Error!");
        QTimer::singleShot(600, this, SLOT(error()));
    }
    showTable();
}

bool Widget::checkInput(QString text) {
    if (text[2] != '.' || text[5] != '.' || text.size() != 10) return false;
    if (text[0] > '9' || text[0] < '0') return false;
    if (text[1] > '9' || text[1] < '0') return false;
    if (text[3] > '9' || text[3] < '0') return false;
    if (text[4] > '9' || text[4] < '0') return false;
    if (text[6] > '9' || text[6] < '0') return false;
    if (text[7] > '9' || text[7] < '0') return false;
    if (text[8] > '9' || text[8] < '0') return false;
    if (text[9] > '9' || text[9] < '0') return false;
    for (int i = 10; i < text.size(); ++i) if (text[i] != ' ') return false;
    return true;
}

