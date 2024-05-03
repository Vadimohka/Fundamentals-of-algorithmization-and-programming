#ifndef MANUALTEMPLATE_H
#define MANUALTEMPLATE_H

#include <QString>

class ManualTemplate
{
public:
    ManualTemplate(QString typeOfAirplane,
                   QString yearOfProduction,
                   QString fuelConsumption);

    bool IsValid();

    QString GetTypeOfAirplane() const { return typeOfAirplane; }
    QString GetYearOfProduction() const { return yearOfProduction; }
    QString GetFuelConsumption() const { return fuelConsumption; }

private:
    QString typeOfAirplane;
    QString yearOfProduction;
    QString fuelConsumption;
};

#endif // MANUALTEMPLATE_H
