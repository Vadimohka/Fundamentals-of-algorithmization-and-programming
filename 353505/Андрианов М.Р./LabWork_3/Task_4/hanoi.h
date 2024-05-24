#ifndef HANOI_H
#define HANOI_H
#include<QTableWidget>
#include<QTableWidgetItem>
#include<string>
#include<QString>
class hanoi
{
private:
    int count=0;
public:
    void hanoi_solver(int,char,char,char,QTableWidget*);
};

#endif // HANOI_H
