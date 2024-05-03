#ifndef BINARYVIEW_H
#define BINARYVIEW_H

#include <QString>

class BinaryView
{
public:
    BinaryView();
    static::QString toBinary(long double number);
    static::QString toIntBinary(long double number);
    static::QString toDoublePartBinary(long double number, int iteration);

};

#endif // BINARYVIEW_H
