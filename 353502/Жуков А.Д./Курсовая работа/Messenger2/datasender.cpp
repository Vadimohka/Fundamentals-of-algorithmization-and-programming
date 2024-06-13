#include "datasender.h"

constexpr int MAX_USERLIST_CAPACITY = 15;

void DataSender::disconnectSocket()
{
    socket->close();
}

void DataSender::userDisconnected()
{
    sendToServer((_id).toUtf8(), "userDisconnected");
    //socket->close();
}

void DataSender::onConnected()
{
    if (!(_id.isEmpty())) {
        sendToServer((_id).toUtf8(), "newConnection");
    }
}

void DataSender::registerUser(QString login, QString password)
{
    sendToServer((login + "" + password).toUtf8(), "register");
}

void DataSender::logInUser(QString login, QString password)
{
    sendToServer((login + "" + password).toUtf8(), "login");
}

void DataSender::connectSocket()
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &DataSender::readyReadSlot);
    connect(socket, &QTcpSocket::disconnected, this, &DataSender::deleteLater);
    socket->connectToHost("26.70.35.237", 5555);
}

void DataSender::connectSocket(QString id)
{
    _id = id;
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &DataSender::readyReadSlot);
    connect(socket, &QTcpSocket::disconnected, this, &DataSender::deleteLater);
    connect(socket, &QTcpSocket::connected, this, &DataSender::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &DataSender::userDisconnected);
    socket->connectToHost("26.70.35.237", 5555);
}

void DataSender::createChat(QString type, QString uid1_name, QString uid2_admin)
{
    sendToServer((type + "" + uid1_name + "" + uid2_admin).toUtf8(), "createChat");
}

void DataSender::sendMessage(QString text, QString from, QString to, QString isGroup)
{
    sendToServer((text + "" + from + "" + to + "" + isGroup).toUtf8(), "sendMessage_text");
}

void DataSender::sendFile(const QString &fileName, const QString &from, const QString &to, const QString &isGroup, const QByteArray &content)
{
    qDebug() << "PREPARING..." << content.size();
    sendToServer(content, QString("sendMessage_file") + "" + fileName + "" + from + "" + to + "" + isGroup);
}

QStringList DataSender::updateChat(QString uid1_name, QString uid2_admin)
{
    sendToServer((uid1_name + "" + uid2_admin).toUtf8(), "updateChat");
}

QStringList DataSender::getUsersList(QString uid, QString key)
{
    sendToServer((uid + "" + key).toUtf8(), "findUsersByKey");
    return Users;
}

void DataSender::sendToServer(const QByteArray &data, const QString &metadata) {
    QJsonObject package;                                                                            //metadata: login, register, findUsersByKey, createChat
    package["metadata"] = metadata;
    package["data"] = QString::fromLatin1(data.toBase64());
    QJsonDocument jsonDoc(package);
    QByteArray JData = jsonDoc.toJson();

    qDebug() << "SENDING..." << JData.size();
    socket->write(JData);
    socket->waitForBytesWritten();
}

/*
void DataSender::newMessage(QString data)
{
    QString fromUser = data.split(u'').first();
    QString text = data.split(u'').at(1);
    QString date = data.split(u'').at(2);
    QString time = data.split(u'').last();
    emit incommingMessage(fromUser, text, date, time);
}
*/

void DataSender::receiveFileFromServer(const QByteArray &JData, const QString &outputFilePath) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(JData);
    if (!jsonDoc.isObject()) {
        qDebug() << "Invalid JSON data";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString metadata = jsonObj["metadata"].toString();
    QByteArray fileData = QByteArray::fromBase64(jsonObj["data"].toString().toLatin1());

    QFile file(outputFilePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error opening file for writing:" << file.errorString();
        return;
    }

    file.write(fileData);
    file.close();

    qDebug() << "File received and saved successfully. Metadata:" << metadata;
}

void DataSender::loadChatOnLogin(QString forUser, QString fromChat)
{
    sendToServer((forUser + "" + fromChat).toUtf8(), "loadOnLogin");
}

void DataSender::downloadFile(const QString &fileName)
{
    sendToServer(fileName.toUtf8(), "downloadFile");
}

void DataSender::readyReadSlot()
{
    qDebug() << "DATA CAME TO CLIENT";

    QByteArray JData = socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(JData);
    if (!jsonDoc.isObject()) {
        qDebug() << "Invalid JSON data";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString metadata = jsonObj["metadata"].toString();
    QByteArray dataBytes = QByteArray::fromBase64(jsonObj["data"].toString().toLatin1());
    QString data;

    qDebug() << "JDATA" << dataBytes.size();

    if (metadata.split(u'').first() == "fileDownload" && !dataBytes.isEmpty()) {
        qDebug() << "USPEX??";
        emit incommingFile(dataBytes, metadata.split(u'').last());
    } else {
        data = QString::fromUtf8(dataBytes);
    }

    qDebug() << "DATA: " << data;
    qDebug() << "METADATA: " << metadata;

    if (metadata == "registrationMessage")
    {
        emit updateRegistrationStatus(data);
    }
    else if (metadata == "loginMessage")
    {
        if (!data.isEmpty()) {
            emit loginSucceed(data);
        } else {
            emit updateRegistrationStatus("No such user");
        }
    }
    else if (metadata == "findByIdResponse")
    {
        if (!data.isEmpty()) {
            Users = data.split(u'');
        } else {
            Users = QStringList{};
        }
    }
    else if (metadata == "chatCreated")
    {
        emit chatCreated(data);
    }
    else if (metadata == "chatsLoaded")
    {
        if (!data.isEmpty()) {
            QStringList chats = data.split(u'');
            for (auto &chat : chats) {
                emit chatCreated(chat);
            }
        }
    }
    else if (metadata == "loadMessage_text")
    {
        if (!data.isEmpty()) {
            QStringList message = data.split(u'');
            emit loadMessageText(message.at(0), message.at(1), message.at(2), message.at(3));
        }
    }
    else if (metadata == "loadMessage_picture")
    {
        QStringList message = data.split(u'');
        //emit loadMessages(data.at(0), data.at(0), data.at(0),data.at(0));
    }
    else if (metadata == "loadMessage_file")
    {
        if (!data.isEmpty()) {
            QStringList message = data.split(u'');
            emit loadMessageFile(message.at(0), message.at(1), message.at(2), message.at(3));
        }
    }
    else if (metadata == "disconnected")
    {
        socket->close();
    }
    else
    {
        qDebug() << "ERROR: smth wrong with data";
    }
}
