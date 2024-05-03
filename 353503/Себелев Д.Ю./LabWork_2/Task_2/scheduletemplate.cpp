#include "scheduletemplate.h"

ScheduleTemplate::ScheduleTemplate(QString numOfRoute,
                                   QString destination,
                                   QString flightRange,
                                   QString typeOfAirplane,
                                   QString departureTime,
                                   QString landingTime)
    : numOfRoute(numOfRoute),
    destination(destination),
    flightRange(flightRange),
    typeOfAirplane(typeOfAirplane),
    departureTime(departureTime),
    landingTime(landingTime)
{}

bool ScheduleTemplate::IsValid()
{
    bool validNumOfRoute = false;
    bool validDestination = false;
    bool validFlightRange = false;
    bool validDepartureTime = false;
    bool validLandingTime = false;

    for (auto ch : std::as_const(numOfRoute))
    {
        if (ch.isDigit())
        {
            validNumOfRoute = true;
        }
        else
        {
            validNumOfRoute = false;
            break;
        }
    }

    for (auto ch: std::as_const(destination))
    {
        if (destination[0].isUpper() && (ch.isLetter() || ch == ' '))
        {
            validDestination = true;
        }
        else
        {
            validDestination = false;
            break;
        }
    }

    for (auto ch : std::as_const(flightRange))
    {
        if (ch.isDigit())
        {
            validFlightRange = true;
        }
        else
        {
            validFlightRange = false;
            break;
        }
    }

    timeFormat = QRegularExpression("^([01]?[0-9]|2[0-3]):[0-5][0-9]$");

    validDepartureTime = timeFormat.match(departureTime).hasMatch();

    validLandingTime = timeFormat.match(landingTime).hasMatch();

    if (validNumOfRoute && validDestination && validFlightRange && validDepartureTime && validLandingTime)
    {
        return true;
    }
    else
    {
        return false;
    }
}

