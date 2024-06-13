#include "Plant.h"

QString Plant::name[MAX_ANOUNT_PLANT];
int Plant::nutrients[MAX_ANOUNT_PLANT];

Plant::Plant()
    : age(0)
    , height(0.0)
    , vitamin('-')
    , isFlowering(false)
{
    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}

Plant::Plant(int age, double height, char vitamin, bool isFlowering)
    : age(age)
    , height(height)
    , vitamin(vitamin)
    , isFlowering(isFlowering)
{
    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}

QString Plant::plantToString()
{
    return "Age: " + QString::number(age) + " | Height: " + QString::number(height)
           + " | DwarfPlanet: " + vitamin + " | InTheSolarSystem: " + (isFlowering ? "Yes" : "No");
}

void Plant::clear()
{
    age = 0;
    height = 0.0;
    vitamin = '-';
    isFlowering = false;

    for (int i = 0; i < MAX_ANOUNT_PLANT; ++i) {
        name[i] = "Unknown";
        nutrients[i] = 0;
    }
}
