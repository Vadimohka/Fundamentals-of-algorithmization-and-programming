#include "messageStorage.h"

void MessageStorage::addChat(QListWidget *widget, const QString &name)
{
    if (storage.contains(name)) {
        storage.erase(storage.find(name));
    }
    storage.insert(name, widget);
}
/*
void MessageStorage::addMessage(ChatMessageWidget *obg, const QString &name)
{
    if (storage.contains(name)) {
        storage.value(name).append(obg);
    }
}
*/
QListWidget * MessageStorage::loadChat(const QString &chat)
{
    qDebug() << storage.value(chat)->count();
    if (storage.contains(chat))
        return storage.value(chat);
    return new QListWidget;
}

bool MessageStorage::chatExists(const QString &chat)
{
    if (storage.contains(chat))
        return true;
    return false;
}
