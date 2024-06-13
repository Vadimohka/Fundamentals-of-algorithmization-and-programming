#include "work.h"

Work::Work(QString input)
{
    QString sotrydnikFIO1 = "";
    QString nameProject1 = "";
    QString zadanie1 = "";
    QString dateOfBegin1 = "";
    QString dateOfDone1 = "";
    QString deadLineStr = "";
    QString rykovoditelFIO1 = "";
    int i = 0;
    while (input[i] != ',') {
        nameProject1.append(input[i]);
        //_price.append(input[i]);
        i++;
    }
    i++;
    while (input[i] != ',') {
        zadanie1.append(input[i]);
        i++;
    }
    i++;
    while (input[i] != ',') {
        sotrydnikFIO1.append(input[i]);
        //_name.append(input[i]);
        i++;
    }
    i++;
    while (input[i] != ',') {
        rykovoditelFIO1.append(input[i]);
        i++;
    }
    i++;
    while (input[i] != ',') {
        dateOfBegin1.append(input[i]);
        i++;
    }
    i++;
    while (input[i] != ',') {
        dateOfDone1.append(input[i]);
        i++;
    }
    i++;
    while (i < input.size()) {
        deadLineStr.append(input[i]);
        //deadLine1 = deadLineStr.toInt();
        i++;
    }

    sotrydnikFIO = sotrydnikFIO1;
    nameProject = nameProject1;
    zadanie = zadanie1;
    dateOfBegin = dateOfBegin1;
    dateOfDone = dateOfDone1;
    deadLine = deadLineStr.toInt();
    rykovoditelFIO = rykovoditelFIO1;
}
