//
// Created by acryoz on 15.05.24.
//
#include "../include/smartphone.h"

Smartphone::Smartphone(QString init_str) {
    auto list = init_str.split(" ");
    this->imei = list[0].toULongLong();
    this->enabled = (list[1].toInt() == 1);
    this->model = list[2].toStdString()[0];
    this->screen_size = list[3].toDouble();
    this->serial_no = new char[list[4].length()];
    for (int i = 0; i < list[4].length(); ++i) {
        this->serial_no[i] = list[4].toStdString()[i];

    }
    this->serial_no[list[4].length()] = '\0';
    this->phone_book = new uint64_t[list.length() - 5];
    for (int i = 0; i < list.length() - 5; ++i) {
        this->phone_book[i] = list[i + 5].toULongLong();
    }
    this->pb_length = list.length() - 5;
}

QString Smartphone::print() {
    QString res;
    res.append("IMEI: " + QString::number(this->imei) + "\n");
    res.append("Enabled: " +
               ((this->enabled) ? QString("yes") : QString("no")) + "\n");
    res.append("Model: " + QString(this->model) + "\n");
    res.append("Serial №: " + QString(this->serial_no) + "\n");
    res.append("Phone book:\n");
    for (size_t i = 0; i < this->pb_length; ++i) {
        res.append(QString::number(this->phone_book[i]) + "\n");
    }
    return res;
}

Smartphone::~Smartphone() {
    delete[] this->phone_book;
    delete[] this->serial_no;
}
