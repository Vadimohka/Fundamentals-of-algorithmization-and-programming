#ifndef FOLDER_COUNTING_H
#define FOLDER_COUNTING_H
#include <QString>
#include <QDir>

class Folder_counting
{
public:
    Folder_counting();
    void count_up(QString path, int &cnt_of_dir, int &cnt_of_files);
};

#endif // FOLDER_COUNTING_H
