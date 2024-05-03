#ifndef SOLUTION_H
#define SOLUTION_H
#include <QString>
#include <QtMath>
class Solution
{
public:
    Solution();
    QString binaryRepresentation(double number);
private:
    QString fractionalBinaryRepresentation(double fraction);
    QString integerBinaryRepresentation(int number);
    int numberOperationsFractionalBinaryRepresentation = 0;
};

#endif // SOLUTION_H
