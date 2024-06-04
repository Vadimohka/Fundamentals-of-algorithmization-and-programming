#include "findstudent.h"

void FindStudent::on_ready_clicked()
{
    namE = lineEdit1->text();
    surnamE = lineEdit2->text();
    dadsnamE = lineEdit3->text();
    accept();
}

QString FindStudent::get_name()
{
    return namE;
}

QString FindStudent::get_surname()
{
    return surnamE;
}

QString FindStudent::get_dadsname()
{
    return dadsnamE;
}
