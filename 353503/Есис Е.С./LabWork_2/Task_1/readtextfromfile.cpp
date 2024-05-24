#include "readtextfromfile.h"

ReadTextFromFile::ReadTextFromFile() {
    QVector<ReadTextFromFile> dates;
    QFile file("dates.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        dates.append(ReadTextFromFile(line));
    }

    // Выводим даты и следующий день для каждой даты
    for (const ReadTextFromFile &dateClass : dates) {
        qDebug() << "Текущая дата: " << dateClass.date;
        qDebug() << "Следующий день: " << dateClass.date.addDays(1);
    }

    /* in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        dates.append(ReadTextFromFile(line));
    }

    // Выводим даты
    for (const ReadTextFromFile &dateClass : dates) {
        qDebug() << dateClass.date;*/
    }
