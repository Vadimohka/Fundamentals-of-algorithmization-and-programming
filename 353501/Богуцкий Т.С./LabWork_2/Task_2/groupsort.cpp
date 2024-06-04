#include "groupsort.h"

QString GroupSort::get_name()
{
    return name_for_group;
}

void GroupSort::on_ready_clicked()
{
    name_for_group = lineEdit1->text();
    accept();
}
