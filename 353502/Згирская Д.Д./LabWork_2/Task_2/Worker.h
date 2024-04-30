//
// Created by zgdarya on 4/13/24.
//

#ifndef LAB2_TASK2_WORKER_H
#define LAB2_TASK2_WORKER_H
#define uint unsigned

#include <QString>
#include "Date.h"

class Worker {
    QString _workerFIO;
    QString _projectName;
    QString _task;
    QString _mentorFIO;
    Date _dateGave;
    Date _deadline;
    Date _dateComplete;

public:
    Worker(QString workerFIO);

    Worker();

    void setWorkerFIO(QString workerFIO);

    void setProject(QString projectName);

    void setTask(QString task);

    void setDateGave(QString dateGave);

    void setDateComplete(QString dateComplete);

    void setDeadline(QString deadline);

    void setMentorFIO(QString mentorFIO);

    Date getDateGaveDate();
    Date getDeadlineDate();
    Date getDateCompleteDate();

    QString getWorkerFIOString();
    QString getProjectNameString();
    QString getTaskString();
    QString getMentorFIOString();
    QString getDatesString();
    QString getDateGaveString();
    QString getDeadlineString();
    QString getDateCompleteString();
};


#endif //LAB2_TASK2_WORKER_H
