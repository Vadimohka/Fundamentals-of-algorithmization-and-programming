#ifndef DIRECTCHECK_H
#define DIRECTCHECK_H

#include "./ui_mainwindow.h"
#include <QString>

class DirectCheck
{
public:
    DirectCheck();
    void countFilesAndDirs(const QString &path, int &fileCount, int &dirCount, Ui::MainWindow *ui);
};

#endif // DIRECTCHECK_H
