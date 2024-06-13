//
// Created by acryoz on 9.3.24.
//

#include "../headers/files.h"


QMap<QString, Party>* readFile(QFile* file){
    auto map = new QMap<QString, Party>;
    file->close();
    file->open(QIODevice::ReadOnly);
    QString name;
    uint region;
    QString party;
    QString occupation;
    uint income;
    uint age;
    while(!file->atEnd()){
        name = file->readLine();
        name.chop(1);
        qDebug() << name;
        region = file->readLine().toInt();
        qDebug() << region;
        party = file->readLine().toLower();
        party.chop(1);
        qDebug() << party;
        occupation = file->readLine().toLower();
        occupation.chop(1);
        qDebug() << occupation;
        income = file->readLine().toInt();
        qDebug() << income;
        age = file->readLine().toInt();
        qDebug() << age;
        if(!map->contains(party)){
            map->insert(party, Party(party));
        }
        (*map)[party].add(Candidate(name, region, party, occupation, income, age));
    }
    return map;
}


void writeFile(QFile* file, QMap<QString, Party>* map){
    QTextStream ofstream(file);
    file->close();
    file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    for (auto it = map->keyValueBegin(); it != map->keyValueEnd(); ++it){
        for(const Candidate& c: *it->second.candidates()){
            ofstream << c.name() << '\n';
            ofstream << c.region() << '\n';
            ofstream << c.party() << '\n';
            ofstream << c.occupation() << '\n';
            ofstream << c.income() << '\n';
            ofstream << c.age() << '\n';
        }
    }
}

