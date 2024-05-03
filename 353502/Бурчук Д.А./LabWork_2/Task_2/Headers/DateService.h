#ifndef LAB2_DATESERVICE_H
#define LAB2_DATESERVICE_H

#include "QFileDialog"
#include <vector>
#include <fstream>
#include <QTimer>
#include <QThread>

#include "Date.h"

class DateService : public QObject {
Q_OBJECT

    std::ofstream dateOutput;
    std::ifstream dateInput;

    Date _birthDayDate;

    QString _path;

public:
    DateService();

    void addToFile(Date &dateToWrite);
    void redactFile(Date &dateToWrite,int num);

    std::vector<Date> _date;

    Date todayDate();

    Date birthDayDate();

public slots:

    void setPath();

    void setBirthDay(Date & date);

    void readFile();
};


#endif //LAB2_DATESERVICE_H
