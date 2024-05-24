#ifndef DELETE_H
#define DELETE_H
#include <encryption.h>
#include <QPushButton>
#include <QCheckBox>
#include <QProgressBar>
#include <QVector>
#include <QFile>
#include<QMessageBox>
class Delete
{
public:
    void Hide(QVector <QPushButton*>,QVector<QCheckBox*>);
    std::string process(int i);
    QProgressBar*arr;
};

#endif // DELETE_H
