#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <QString>
class Mathematics
{
public:
    Mathematics();

    QString decToBin(double dec);

private:
    QString intToBin (int numbe);

    QString tailToBin(double tail);

    QString _tailToBin(double tail, int digits);
};

#endif // MATHEMATICS_H
