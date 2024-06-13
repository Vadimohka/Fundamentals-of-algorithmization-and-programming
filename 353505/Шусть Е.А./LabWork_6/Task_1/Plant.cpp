#include "Plant.h"

QString Plant::name[MAX_ANOUNT_PLANT];
int Plant::nutrients[MAX_ANOUNT_PLANT];

Plant::Plant()
    : age(0)
    , height(0.0)
    , number('-')
    , SolarSystem(false)
{
    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}

Plant::Plant(int age, double height, char number, bool SolarSystem)
    : age(age)
    , height(height)
    , number(number)
    , SolarSystem(SolarSystem)
{
    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}

QString Plant::plantToString()
{
    return "Age: " + QString::number(age) + " | Height: " + QString::number(height)
           + " | DwarfPlanet: " + number + " | InTheSolarSystem: " + (SolarSystem ? "Yes" : "No");
}

void Plant::clear()
{
    age = 0;
    height = 0.0;
    number = '-';
    SolarSystem = false;

    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}
