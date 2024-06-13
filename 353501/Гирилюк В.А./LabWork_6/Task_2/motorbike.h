#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <QString>


struct Motorbike
{
    int serialNumber;
    double maxSpeed;
    char color;
    bool isMoving;
    const char* name;
    int size[3];

    QString toQString(QChar separator)
    {
        QString result;

        result.push_back(QString::number(serialNumber));
        result.push_back(separator);
        result.push_back(QString::number(maxSpeed));
        result.push_back(separator);
        result.push_back(color);
        result.push_back(separator);
        result.push_back(isMoving ? "True" : "False");
        result.push_back(separator);
        result.push_back(name);
        result.push_back(separator);
        for(int i = 0; i < 3; ++i){
            result.push_back(QString::number(size[i]));
            result.push_back(separator);
        }

        return result;
    }
};
#endif // MOTORBIKE_H
