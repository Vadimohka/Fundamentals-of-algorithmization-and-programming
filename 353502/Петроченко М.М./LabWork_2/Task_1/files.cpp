//
// Created by acryoz on 6.3.24.
//

#include "../headers/files.h"


QVector<Date>* readDates(QFile* file){
    QVector<Date>* vec = new QVector<Date>;
    QString str;
    while(!file->atEnd()){
        str = file->readLine();
        vec->push_back(Date::fromString(str));
    }
    return vec;
}


void writeDates(QFile* file, QVector<Date>* dates){
    QTextStream ofstream(file);
    file->close();
    file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    for(int i = 0; i < dates->size(); ++i){
        ofstream << dates->at(i).toQstring() << '\n';
    }
}