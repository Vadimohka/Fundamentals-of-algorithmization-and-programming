#ifndef FUNC_WITH_FILES_H
#define FUNC_WITH_FILES_H
#include<QString>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
class func_with_files
{
public:
    QString openfile();
    QString readFromFile(QString,int);
    void writeIntoFile(QString,QString);
    bool check(QString,int);
    bool check_str(QString);
private:
    bool fl=0;
    int sch1=0;
    int sch=0;
    int year=0;
};

#endif // FUNC_WITH_FILES_H
