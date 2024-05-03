#include "workers.h"

workers::workers(QString fio, QString name, QString task, QString dated, QString start, QString finish) : fio(fio),name(name),task(task),dated(dated),start(start),finish(finish) {

      };

QString workers::getfio(){
    return fio;
};

QString workers::getname(){
    return name;
}

QString workers::gettask(){
    return task;
};


QString workers::getdated(){
    return dated;
};


QString workers::getstart(){
    return start;
};


QString workers::getfinish(){
    return finish;
};
