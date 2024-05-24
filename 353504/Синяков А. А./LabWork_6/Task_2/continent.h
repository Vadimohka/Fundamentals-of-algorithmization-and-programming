#ifndef CONTINENT_H
#define CONTINENT_H
#include <QDataStream>

struct Continent {
    int area;
    double averageHeight;
    char firstLetter;
    bool hasOceanCoast;
    static const int stringLength = 20;
    char name[stringLength];
    static const int climateDataSize = 5;
    int climateData[climateDataSize];

    friend QDataStream &operator<<(QDataStream &out, const Continent &continent) {
        out << continent.area << continent.averageHeight << continent.firstLetter << continent.hasOceanCoast;
        out.writeRawData(continent.name, stringLength);
        for (int i = 0; i < continent.climateDataSize; ++i) {
            out << continent.climateData[i];
        }
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, Continent &continent) {
        in >> continent.area >> continent.averageHeight >> continent.firstLetter >> continent.hasOceanCoast;
        in.readRawData(continent.name, stringLength);
        for (int i = 0; i < continent.climateDataSize; ++i) {
            in >> continent.climateData[i];
        }
        return in;
    }
};

#endif // CONTINENT_H
