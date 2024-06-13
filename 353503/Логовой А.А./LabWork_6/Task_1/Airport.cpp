#include "Airport.h"

char Airport::name[SIZE] = "";
int Airport::flights[TEN] = {0};

QString Airport::printInfo() {
    QString info;
    info += "Airport id: " +  QString::number(id) + " | ";
    info += QString::number(altitude) + " | ";
    info += isOpen ? "Open" : "Closed";
    info += " | " + QString(name) + " | ";
    for(int i = 0; i < TEN; i++)
    {
        info += QString::number(flights[i]) + " ";
    }
    return info;
}
