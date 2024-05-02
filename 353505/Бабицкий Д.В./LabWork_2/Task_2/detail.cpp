#include "detail.h"
#include "mainwindow.h"
Detail::Detail(QString t, QString c, QString m, QString p, double coa, bool ava) {
    type = t;
    company = c;
    model = m;
    parameters = p;
    coast = coa;
    avaliable = ava;
}

QString Detail::GetType(){
    return type;
}

QString Detail::GetCompany(){
    return company;
}

QString Detail::GetModel(){
    return model;
}

QString Detail::GetParameters(){
    return parameters;
}

double Detail::GetCoast(){
    return coast;
}

bool Detail::isAvaliable(){
    return avaliable;
}
