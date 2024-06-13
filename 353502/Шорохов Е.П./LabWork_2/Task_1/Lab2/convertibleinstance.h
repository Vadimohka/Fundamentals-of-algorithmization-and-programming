#ifndef CONVERTIBLEINSTANCE_H
#define CONVERTIBLEINSTANCE_H

#include <QString>

//TL;DR It was rm rf'ed by aonbel, so I've copypasted it, instead of a complete redo
class ConvertibleInstance
{
public:
    ConvertibleInstance();
    virtual ~ConvertibleInstance() = default;
    virtual QString ToQString() = 0;
    virtual void SetInstanceFromQString(QString object) = 0;
};

#endif // CONVERTIBLEINSTANCE_H
