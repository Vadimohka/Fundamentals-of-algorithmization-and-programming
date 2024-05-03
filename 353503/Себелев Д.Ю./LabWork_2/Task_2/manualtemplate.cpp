#include "manualtemplate.h"

ManualTemplate::ManualTemplate(QString typeOfAirplane,
                               QString yearOfProduction,
                               QString fuelConsumption)
:   typeOfAirplane(typeOfAirplane),
    yearOfProduction(yearOfProduction),
    fuelConsumption(fuelConsumption)
{}

bool ManualTemplate::IsValid()
{
    bool validTypeOfAirplane = false;
    bool validYearOfProduction = false;
    bool validFuelConsumption = false;

    for (auto ch : std::as_const(typeOfAirplane))
    {
        if (typeOfAirplane[0] != ' ' && (ch.isLetter() || ch.isDigit() || ch == ' '))
        {
            validTypeOfAirplane = true;
        }
        else
        {
            validTypeOfAirplane = false;
            break;
        }
    }

    for (auto ch : std::as_const(yearOfProduction))
    {
        if (ch.isDigit())
        {
            validYearOfProduction = true;
        }
        else
        {
            validYearOfProduction = false;
            break;
        }
    }

    for (auto ch : std::as_const(fuelConsumption))
    {
        if (ch.isDigit() || ch == '.')
        {
            validFuelConsumption = true;
        }
        else
        {
            validFuelConsumption = false;
            break;
        }
    }

    if (validTypeOfAirplane && validYearOfProduction && validFuelConsumption)
    {
        return true;
    }
    else
    {
        return false;
    }
}

