#ifndef PLANE_H
#define PLANE_H

#include <QString>

class Plane
{
private:
    QString type;
    int productionYear;
    double fuelCons;
public:
    Plane(QString type, int productionYear, double fuelCons);
    QString getFullInfo() const;
    QString getTypeString() const;
    double getFuelCons() const;
};

#endif // PLANE_H
