#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QSharedPointer>
#include <QString>
#include <QByteArray>

#include "databasemanager.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(){}
    void startServer();

private:
    QTcpSocket *socket;

    QString buffKey;
    QByteArray Data;
    QByteArray Metadata;
    DatabaseManager* databaseManager;
    QMap<QString, QTcpSocket*> socketsStorage;
    //qint16 BlockSize = 0;

    void sendToClient(QTcpSocket *socket, const QByteArray &data, const QString &metadata);
    void sendOut(const QString &data, const QString &type, const QByteArray &file = "");
    //void sendOutFile(const QString &data);
    void voidOnLogin(const QString &data);

    void registerUser(const QString &);
    void LogInUser(const QString &);
    void findUsersByKey(const QString &);
    void createChat(const QString &);
    void downloadFile(const QString &);

public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void slotReadyRead();
    void userDisconnected();
};

#endif // SERVER_H
