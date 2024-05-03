#include "group.h"

Group::Group() = default;

Group::Group(QString* name) : name(name)
{

}

void Group::SetName(QString* name)
{
    *this->name = *name;
}

QString* Group::GetName()
{
    return new QString(*name);
}

QString *Group::ToQString()
{
    return new QString(*name);
}

void Group::FromQStringToInstance(QString *object)
{
    *name = *object;
}



