#include "folder_counting.h"

Folder_counting::Folder_counting() {}

void Folder_counting::count_up(QString path, int &cnt_of_dir, int &cnt_of_files)
{
    QDir dir(path);
    if (!dir.exists()) return;
    QStringList dir_names;
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList contents = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (const QFileInfo &info, contents) {
        dir_names.push_back(info.fileName());
        ++cnt_of_dir;
    }
    dir.setFilter(QDir::Files);
    cnt_of_files += dir.entryList().count();
    foreach (const QString &s, dir_names) {
        QString temp = QString(path + '/' + s);
        count_up(temp, cnt_of_dir, cnt_of_files);
    }
}
