#ifndef FOLDER_H
#define FOLDER_H
#include <QDir>

class Folder
{
public:
    Folder();
    void Count(QString path, long long& directoriesAmount, long long& filesAmount);
};

#endif // FOLDER_H
