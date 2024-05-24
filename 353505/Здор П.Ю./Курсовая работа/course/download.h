#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include <encryption.h>
#include <QPushButton>
#include <QCheckBox>
#include <QProgressBar>
#include <QVector>
#include <QFile>
#include<QMessageBox>
#include <QProcess>
class Download
{
public:

    void Hide(QVector <QPushButton*>,QVector<QCheckBox*>);
    std::string process(int );
    QProgressBar*arr;
    void downloading(std::string);
};

#endif // DOWNLOAD_H
