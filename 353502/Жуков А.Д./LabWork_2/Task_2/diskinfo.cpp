#include "diskinfo.h"

#include <utility>

DiskInfo::DiskInfo(QString t, QString n, QString a, QString p, QString no)
    : type(std::move(t))
    , name(n)
    , author(a)
    , price(p)
    , note(no)
{

}

bool DiskInfo::searchDisk(QString key)
{
    if (type.contains(key) ||
        name.contains(key) ||
        author.contains(key) ||
        price.contains(key) ||
        note.contains(key))
    {
        return true;
    }
    return false;
}
