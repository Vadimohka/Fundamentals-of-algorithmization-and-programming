#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QSqlError>
#include <ctime>

#include "DatabaseQuerys.h"

class DatabaseManager
{
public:
    DatabaseManager();

    bool registerUser(const QString &, const QString &password);
    bool userExist(const QString &, const QString &password = "");
    bool createChat(const QString &chatName, bool isGroup, const QList<int> &memberIds);
    void addMessage(const QString &message, const QString &fromUser, const QString &toUser, const QString &isGroup, const QString &type, const QByteArray &file = "");
    QStringList loadMessages(const QString &author, const QString &to);
    QString &LoadFile(const QString &author, const QString &to);
    QStringList &getMemebersIds(const QString &chatName);

    QString timeNow();
    QString dateNow();

    QString getUID(const QString & login);
    QString getUsersByKey(const QString & key, const QString & exceptId);
    QString getUserChatNames(int userId);
    QString getNameById(const QString &id);
    QByteArray &getFile(const QString &name);
    int getChatId(const QString &chatName, const QString &fromUser, bool &isGroup);
    //QStringList* getMessages(QString forUser, QString fromUser);

private:
    QSqlDatabase database_users;
    QSqlQuery* query;

    bool pickChat(const QString &, const QString &);
};

#endif // DATABASEMANAGER_H
