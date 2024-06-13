#include "server.h"

void Server::startServer()
{
    if (this->listen(QHostAddress::Any, 5555)) {
        qDebug() << "Server is running";
    } else {
        qDebug() << "ERROR Server is not running";
    }
    databaseManager = new DatabaseManager();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::userDisconnected);
    qDebug() << "new connection";

    //Sockets.push_back(socket);
}

void Server::slotReadyRead()
{
    qDebug() << "\nNEW QUERY\n";
    socket = (QTcpSocket*)sender();
    Data = socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(Data);
    QJsonObject rootObject = jsonDoc.object();
    QString metadata = rootObject["metadata"].toString();
    QByteArray fileData = QByteArray::fromBase64(rootObject["data"].toString().toLatin1());
    QString data;

    qDebug() << "Bytes: " << fileData << metadata;

    if (metadata == "downloadFile") {
        downloadFile(fileData);
    } else {
        data = QString::fromUtf8(fileData);
        qDebug() << "String: " << data << metadata;
        if (metadata == "newConnection") {
            socketsStorage.insert(data, socket);
            sendToClient(socket, databaseManager->getUserChatNames(data.toInt()).toUtf8(), "chatsLoaded");
        } else if (metadata == "userDisconnected") {
            socketsStorage.remove(data);
            sendToClient(socket, "", "disconnected");
        } else if (metadata == "register") {
            registerUser(data);
        } else if (metadata == "login") {
            LogInUser(data);
        } else if (metadata == "findUsersByKey") {
            findUsersByKey(data);
        } else if (metadata == "createChat") {
            createChat(data);
        } else if (metadata == "sendMessage_text") {
            sendOut(data, "text");
        } else if (metadata.split(u'').first() == "sendMessage_file") {
            QStringList newData = metadata.split(u'');
            metadata.remove(0, 1);
            QString messageData = newData.join("");
            qDebug() << messageData;
            sendOut(messageData, "file", fileData);
        } else if (metadata == "loadOnLogin") {
            voidOnLogin(data);
        }
    }
}

void Server::userDisconnected()
{
    socket = (QTcpSocket*)sender();
    if (socket) {
        socket->deleteLater();
    }
    qDebug() << "USER DISCONNECTED";
}

void Server::sendToClient(QTcpSocket *socket, const QByteArray &data, const QString &metadata) {
    qDebug() << "TRYING TO SEND" << data.size();
    QJsonObject package;
    package["metadata"] = metadata;
    package["data"] = QString::fromLatin1(data.toBase64());
    QJsonDocument jsonDoc(package);
    QByteArray JData = jsonDoc.toJson();

    socket->write(JData);
    socket->waitForBytesWritten();
}

void Server::sendOut(const QString &data, const QString &type, const QByteArray &file)
{
    qDebug() << "SEND OUT" << data << type;
    QStringList newMessages;
    QStringList textMessage = data.split(u''); //message, author, to, isGroup \\ name, author, to, isGroup, content
    if (type == "text") {
        databaseManager->addMessage(textMessage.first(), textMessage.at(1), textMessage.at(2), textMessage.last(), "text");
        newMessages = databaseManager->loadMessages(textMessage.at(1), textMessage.at(2));
    } else {
        databaseManager->addMessage(textMessage.at(1), textMessage.at(2), textMessage.at(3), textMessage.at(4), "file", file);
        newMessages.append(databaseManager->loadMessages(textMessage.at(2), textMessage.at(3)));
    }

    newMessages.last().chop(5);
    sendToClient(socket, newMessages.last().toUtf8(), "loadMessage_" + type);
    if (!textMessage.at(3).toShort()) {
        QString sendToChatId = databaseManager->getUID(textMessage.at(type == "text" ? 2 : 3));
        if (socketsStorage.contains(sendToChatId)) {
            ////////////////
            qDebug() << "TRYING TO SEND TO " << textMessage.at(2) << sendToChatId;
            ////////////////
            sendToClient(socketsStorage.value(sendToChatId), newMessages.last().toUtf8(), "loadMessage_" + type);
        }
    } else {
        QStringList sendToChatIds = databaseManager->getMemebersIds(textMessage.at(2));
        for (QString & id : sendToChatIds) {
            if (socketsStorage.contains(id)) {
                ////////////////
                qDebug() << "TRYING TO SEND TO " << textMessage.at(1) << "";
                ////////////////
                sendToClient(socketsStorage.value(id), newMessages.last().toUtf8(), "loadMessage_" + type);
            }
        }
    }
}

void Server::voidOnLogin(const QString &data)
{
    QStringList for_from = data.split(u'');
    QStringList messages = databaseManager->loadMessages(for_from.at(0), for_from.at(1));
    if (!messages.isEmpty()) {
        for (auto& message : messages) {
            qDebug() << "MESSAGE TO" << message.split(u'').at(2) << ": " << message;
            if (message.split(u'').last() == "text") {
                message.chop(5);
                sendToClient(socket, message.toUtf8(), "loadMessage_text");
            } else if (message.split(u'').last() == "file") {
                message.chop(5);
                sendToClient(socket, message.toUtf8(), "loadMessage_file");
            }
        }
    }
}

void Server::registerUser(const QString & log_pass)
{
    QString login = log_pass.split(u'').first();
    QString password = log_pass.split(u'').last();

    if (databaseManager->registerUser(login, password)) {
        sendToClient(socket, ("user " + login + " successfully registered").toUtf8(), "registrationMessage");
    } else {
        sendToClient(socket, ("user " + login + " already registered").toUtf8(), "registrationMessage");
    }
}

void Server::LogInUser(const QString & log_pass)
{
    QString login = log_pass.split(u'').first();
    QString password = log_pass.split(u'').last();
    //qDebug() << "PEREMOGA (logged)";

    if (databaseManager->userExist(login, password)) {
        sendToClient(socket, databaseManager->getUID(login).toUtf8(), "loginMessage");
        qDebug() << "MACHAAA";
    }
}

void Server::findUsersByKey(const QString & key_id)
{
    //qDebug() << "TRYING TO FIND";
    QString key = key_id.split(u'').last();
    QString id = key_id.split(u'').first();
    sendToClient(socket, databaseManager->getUsersByKey(key, id).toUtf8(), "findByIdResponse");
}

void Server::createChat(const QString & type_un_ua)
{
    QString type = type_un_ua.split(u'').first();
    QString uid1_name = type_un_ua.split(u'').at(1);
    QString uid2_admin = type_un_ua.split(u'').last();

    if (type == "private") {
        if (databaseManager->createChat(uid2_admin, false, QList{databaseManager->getUID(uid1_name).toInt(), databaseManager->getUID(uid2_admin).toInt()})){
            sendToClient(socket, uid2_admin.toUtf8(), "chatCreated");
        } else {
            qDebug() << "ERROR: Chat hasnt been created due to database error (server.cpp)";
        }
    } else {
        if (databaseManager->createChat(uid1_name, true, QList{databaseManager->getUID(uid2_admin).toInt()})) {
            sendToClient(socket, uid1_name.toUtf8(), "chatCreated");
        } else {
            qDebug() << "ERROR: Chat hasnt been created due to database error (server.cpp)";
        }
    }
}

void Server::downloadFile(const QString &fileName)
{
    sendToClient(socket, databaseManager->getFile(fileName), "fileDownload" + fileName);
}
