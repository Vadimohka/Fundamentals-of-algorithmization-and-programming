#ifndef COUNTER_H
#define COUNTER_H

#include <QDir>
class Counter
{
public:

   static void count(QString path);
   static long long getF();
   static long long getD();
   static void toZero();
private:
    static long long filesCount;
    static long long dirCount;
};

#endif // COUNTER_H
