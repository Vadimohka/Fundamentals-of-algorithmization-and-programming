#ifndef CONVERTIBLEINSTANCE_H
#define CONVERTIBLEINSTANCE_H
//I've explained it all earlier
#include <QString>

class ConvertibleInstance
{
public:
    ConvertibleInstance();
    virtual ~ConvertibleInstance() = default;
    virtual QString* ToQString() = 0;
    virtual void FromQStringToInstance(QString* object) = 0;
};

#endif // CONVERTIBLEINSTANCE_H
