#ifndef COUNTER_H
#define COUNTER_H
#include<QDir>
#include<QString>
class counter
{
public:
    void count(QString path,int &count_of_dir,int &count_of_files);
};

#endif // COUNTER_H
