//
// Created by acryoz on 15.05.24.
//

#ifndef LAB6_INCLUDE_SMARTPHONE_H_
#define LAB6_INCLUDE_SMARTPHONE_H_

#include <QString>
#include <QStringList>

struct Smartphone {
    uint64_t imei;
    double screen_size;
    bool enabled;
    char model;
    char* serial_no;
    uint32_t pb_length;
    uint64_t* phone_book;
    explicit Smartphone(QString);
    Smartphone() = default;
    ~Smartphone();
    QString print();
};

#endif  //LAB6_INCLUDE_SMARTPHONE_H_
