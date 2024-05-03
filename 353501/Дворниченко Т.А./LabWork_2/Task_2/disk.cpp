#include "disk.h"
#include "mainwindow.h"
Detail::Detail(QString t, QString c, QString m, QString p, double coa, bool ava) {
    information = t;
    name = c;
    author = m;
    remark = p;
    coast = coa;
    avaliable = ava;
}

QString Detail::GetType(){
    return information;
}

QString Detail::GetName(){
    return name;
}

QString Detail::GetAuthor(){
    return author;
}

QString Detail::GetRemark(){
    return remark;
}

double Detail::GetCoast(){
    return coast;
}

bool Detail::isAvaliable(){
    return avaliable;
}

