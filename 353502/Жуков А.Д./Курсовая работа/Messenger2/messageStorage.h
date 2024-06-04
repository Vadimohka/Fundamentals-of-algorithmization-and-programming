#ifndef MESSAGESTORAGE_H
#define MESSAGESTORAGE_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QString>
#include <QListWidget>
#include <QDebug>
#include "messageItem.h"

class MessageStorage : QObject
{
    Q_OBJECT
    QMap<QString, QListWidget*> storage;
public:
    ~MessageStorage() override = default;
    void addChat(QListWidget *widget, const QString &name);
    //void addMessage(ChatMessageWidget *obg, const QString &name);
    QListWidget * loadChat(const QString &chat);
    bool chatExists(const QString &chat);
};

#endif // MESSAGESTORAGE_H
