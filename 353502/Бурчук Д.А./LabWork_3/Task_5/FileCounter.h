#ifndef LAB3TASK5_FILECOUNTER_H
#define LAB3TASK5_FILECOUNTER_H

#include <QString>
#include <QDir>

class FileCounter {
public:
    static std::pair<int,int> countFiles(QString path);
};


#endif //LAB3TASK5_FILECOUNTER_H
