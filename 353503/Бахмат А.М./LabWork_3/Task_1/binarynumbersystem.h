#ifndef BINARYNUMBERSYSTEM_H
#define BINARYNUMBERSYSTEM_H

#include <QString>

class BinaryNumberSystem
{
public:
    BinaryNumberSystem();
    static::QString toBinary(long double number);
    static::QString intToBinary(long double number);
    static::QString doubleToBinary(long double number, int iteration);
};

#endif // BINARYNUMBERSYSTEM_H
