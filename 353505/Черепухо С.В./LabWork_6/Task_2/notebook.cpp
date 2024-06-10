#include "notebook.h"

QString Notebook::tooString()
{
    QString iid = "";
    for(int i = 0; i < 10; i++)
    {
        iid = iid + QString::number(id[i]);
    }

    QString la = QString(company);
    la.remove(la.size() - 1, 1);

    return(QString::number(usbs) + " | " +
            QString::number(cpuCore) + " | " +
            QString(model) + " | " +
            QString::number(isGaming) + " | " +
            iid + " | " + la);
}

Notebook Notebook::toSelf(QString string)
{
    Notebook so;
    QString corre;

    QStringList list = string.split(" | ");
    if(list.size() == 6)
    {
        so.usbs = list[0].toInt();
        so.cpuCore = list[1].toDouble();
        corre = list[2];
        so.model = corre[0].toLatin1();
        so.isGaming = list[3].toInt();

        for(int i = 0; i < 10; i++)
        {
            corre = list[4];
            so.id[i] = corre[i].unicode() - 48;
        }

        for(int i = 0; i < 9; i++)
        {
            so.company[i] = list[5][i].toLatin1();
        }
    }

    return so;
}
