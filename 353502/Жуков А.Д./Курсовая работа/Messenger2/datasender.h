#ifndef DATASENDER_H
#define DATASENDER_H

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTcpSocket>
#include <QFile>

class DataSender : public QObject
{
    Q_OBJECT
    QString _id;

public:
    void disconnectSocket();
    void registerUser(QString log, QString pass);
    void logInUser(QString log, QString pass);
    void connectSocket();
    void connectSocket(QString id);
    void createChat(QString type, QString uid1_name, QString uid2_admin);
    void sendMessage(QString text, QString from, QString to, QString isGroup);
    void sendFile(const QString &fileName, const QString &from, const QString &to, const QString &isGroup, const QByteArray &content);
    void receiveFileFromServer(const QByteArray &JData, const QString &outputFilePath);
    void loadChatOnLogin(QString forUser, QString fromChat);
    void downloadFile(const QString &fileName);

    QStringList updateChat(QString uid1_name, QString uid2_admin);
    QStringList getUsersList(QString forUserId, QString key);

private:
    void sendToServer(const QByteArray &data, const QString &metadata);

    QTcpSocket *socket;
    QStringList Users;

public slots:
    void readyReadSlot();
    void userDisconnected();
    void onConnected();

signals:
    void updateRegistrationStatus(QString);
    void loginSucceed(QString);
    void chatCreated(QString);
    void loadMessageText(QString, QString, QString, QString);
    void loadMessageFile(const QString&, const QString&, const QString&, const QString&);
    void incommingFile(const QByteArray &, const QString&);
};

#endif // DATASENDER_H
