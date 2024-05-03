#ifndef SCHEDULETEMPLATE_H
#define SCHEDULETEMPLATE_H

#include <QObject>
#include <QRegularExpression>

class ScheduleTemplate
{
public:
    ScheduleTemplate(QString numOfRoute,
                     QString destination,
                     QString flightRange,
                     QString typeOfAirplane,
                     QString departureTime,
                     QString landingTime);

    bool IsValid();

    QString GetNumOfRoute() const { return numOfRoute; }
    QString GetDestination() const { return destination; }
    QString GetFlightRange() const { return flightRange; }
    QString GetTypeOfAirplane() const { return typeOfAirplane; }
    QString GetDepartureTime() const { return departureTime; }
    QString GetLandingTime() const { return landingTime; }

private:
    QString numOfRoute;
    QString destination;
    QString flightRange;
    QString typeOfAirplane;
    QString departureTime;
    QString landingTime;
    QRegularExpression timeFormat;
};

#endif // SCHEDULETEMPLATE_H
