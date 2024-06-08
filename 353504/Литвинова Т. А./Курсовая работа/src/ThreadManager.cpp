#include <QRunnable>
#include <QDebug>
#include <QThread>
#include "apimanager.h"

class ThreadManager : public QRunnable
{
    QString groupNumber;
    ApiManager* apiManager; // Указатель на объект ApiManager

public:
    ThreadManager(QString groupNum, ApiManager* apiManag) : groupNumber(groupNum), apiManager(apiManag) {}

    void run() override
    {
        //qDebug() << "Hello world from thread" << QThread::currentThread() << "with group number" << groupNumber;
        QString response = apiManager->getResponse(groupNumber);
        apiManager->processResult(response);
    }
};
