#ifndef DIRSCOUNTER_H
#define DIRSCOUNTER_H
#include <QDir>
class DirsCounter
{
public:
    DirsCounter();
    void Count(QString path, long long& directoriesAmount, long long& filesAmount);
};

#endif // DIRSCOUNTER_H
