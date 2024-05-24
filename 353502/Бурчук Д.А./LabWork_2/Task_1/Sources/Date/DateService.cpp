#include "../../Headers/DateService.h"

#define DEBUG

DateService::DateService() {
    _path = nullptr;
    _birthDayDate = Date();
    _birthDayDate.isBirthDay();
}

void DateService::setPath() {
    _path = QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;");
#ifdef DEBUG
    qDebug() << _path;
#endif

    //readFile();
}

void DateService::readFile() {
    if (_path != nullptr) {
        qDebug() << "reading file";
        dateInput.open(_path.toUtf8(), std::ofstream::in);

        if (dateInput.is_open()) {
            Date temp;
            _date.clear();
            while (dateInput.read((char *) &temp, sizeof(Date))) {
                _date.push_back(temp);
            }
            for (auto &date: _date) {
                qDebug() << date.day() << date.month() << date.year() << date.isLeap();
            }
        }
        dateInput.close();
    }
}

void DateService::addToFile(Date &dateToWrite) {
    if (_path != nullptr) {
        qDebug() << "adding to file";
        dateOutput.open(_path.toUtf8(), std::ofstream::app);

        if (dateOutput.is_open()) {
            qDebug().nospace() << dateToWrite.day() << '.' << dateToWrite.month() << '.' << dateToWrite.year() << '.'
                               << dateToWrite.isLeap() << '\n';
            /*dateToWrite = dateToWrite.previousDay();
            qDebug().nospace() << dateToWrite.day() << '.'  << dateToWrite.month() << '.'  << dateToWrite.year() << '.'  << dateToWrite.isLeap() << '\n' ;
            dateToWrite = dateToWrite.nextDay();
            qDebug().nospace() << dateToWrite.day() << '.'  << dateToWrite.month() << '.'  << dateToWrite.year() << '.'  << dateToWrite.isLeap() << '\n' ;*/
            qDebug().nospace() << dateToWrite.difference(Date());
            dateOutput.write((char *) &dateToWrite, sizeof(dateToWrite));
            /*Date temp = Date(1,1,0001);
            dateOutput.write((char *) &temp, sizeof(temp));
            temp = Date(24,4,2000);
            dateOutput.write((char *) &temp, sizeof(temp));
            temp = Date(29,2,2000);
            dateOutput.write((char *) &temp, sizeof(temp));
            temp = Date(31,12,2021);
            dateOutput.write((char *) &temp, sizeof(temp));*/
            dateOutput.close();
        }
    }
}

Date DateService::todayDate() {
    return Date();
}

Date DateService::birthDayDate() {
    return _birthDayDate;
}

void DateService::setBirthDay(Date &date) {
    _birthDayDate = date;
}

void DateService::redactFile(Date &dateToWrite, int num) {
    num -= 3;
    if (_path != nullptr) {
        qDebug() << "adding to file";
        dateOutput.open(_path.toUtf8());
        for (int i = 0; i < _date.size(); i++) {
            if (i == num) { dateOutput.write((char *) &dateToWrite, sizeof(dateToWrite)); }
            else { dateOutput.write((char *) &_date[i], sizeof(_date[i])); }
        }
        readFile();
        dateOutput.close();
    }
}

