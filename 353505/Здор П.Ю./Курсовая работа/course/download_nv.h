#ifndef DOWNLOAD_NV_H
#define DOWNLOAD_NV_H
#include <encryption.h>
#include <QPushButton>
#include <QCheckBox>
#include <QProgressBar>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QStorageInfo>
class Download_nv
{
public:

    void Hide(QVector <QPushButton*>,QVector<QCheckBox*>,std::vector<double>);
    std::string process(int i);
    QProgressBar *arr;
};

#endif // DOWNLOAD_NV_H
